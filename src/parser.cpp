//
// Created by Emanuil Gospodinov on 13.01.20.
//

#include "../parser.h"

Parser::Parser(const std::string& fileAddress) {
    this->fileAddress = fileAddress;
    this->machine = nullptr;
    startingState = 0;
    rejectingState = 0;
    acceptingState = 0;
}

Parser::~Parser() = default;

std::string Parser::parse() {
    if (!isValidFile()) return "Invalid file";

    std::ifstream file(fileAddress);

    std::string parseMessage = parseAlphabet(file);
    // check for errors
    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseInput(file);
    if (!parseMessage.empty()) return parseMessage;

//    parseMessage = parseExecutionChoice(file);
//    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseStates(file);
    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseStartingState(file);
    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseAcceptingState(file);
    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseRejectingState(file);
    if (!parseMessage.empty()) return parseMessage;

    parseMessage = parseTransitions(file);
    if (!parseMessage.empty()) return parseMessage;

    machine = new TuringMachine(alphabet, input, states, transitions, startingState, acceptingState, rejectingState);

    file.close();

    return "none";
}

TuringMachine* Parser::getMachine() {
    return machine;
}

std::string Parser::parseAlphabet(std::ifstream& file) {
    std::string currentLine;

    getline(file, currentLine);

    if (!hasLineMultipleItems(currentLine)) return "No tape alphabet given";

    while (currentLine.size() > 0) {
        // add the letter to the alphabet
        alphabet.addLetter(currentLine[0]);
        // remove the letter from the line
        currentLine.erase(0, 1);
        // check for bad comma placement
        if (currentLine.size() > 0 && currentLine[0] != ',') return "Error while parsing the alphabet";
        // remove the comma from the line
        else if (currentLine.size() > 0) currentLine.erase(0, 1);
    }

    return "";
}

std::string Parser::parseInput(std::ifstream &file) {
    std::string currentLine;

    getline(file, currentLine);

    if (!hasLineMultipleItems(currentLine)) return "No input given";

    while (currentLine.length() > 0) {
        // add the letter to the input
        input.push_back(currentLine[0]);
        // remove the letter from the line
        currentLine.erase(0, 1);
        // check for bad comma placement
        if (currentLine.size() > 0 && currentLine[0] != ',') return "Error while parsing the alphabet";
            // remove the comma from the line
        else if (currentLine.size() > 0) currentLine.erase(0, 1);
    }

    return "";
}

std::string Parser::parseExecutionChoice(std::ifstream &file) {
    std::string currentLine;

    getline(file, currentLine);

    if (hasLineMultipleItems(currentLine)) return "No choice of execution provided";
    if (!isValidExecutionChoice(currentLine)) return "Invalid execution choice";

//    executionChoice = currentLine;

    return "";
}

std::string Parser::parseStates(std::ifstream &file) {
    std::string currentLine;

    // empty states
    states.clear();

    getline(file, currentLine);

    int stateCount = std::count(currentLine.begin(), currentLine.end(), ',') + 1;

    for (int i = 0; i < stateCount; i++) {
        // get the index of the comma
        int commaIndex = currentLine.find(',');

        // get the state's name
        std::string stateName = currentLine.substr(0, commaIndex);

        // erase the state from the line
        currentLine.erase(0, commaIndex + 1);

        // remove the spaces (front and back)
        while (stateName.front() == ' ') {
            stateName.erase(0, 1);
        }

        while (stateName.back() == ' ') {
            stateName.erase(stateName.size()-1, 1);
        }

        if (stateName.front() != '{' || stateName.back() != '}') return "Wrong state name formatting for: " + stateName;

        states.push_back(stateName);
    }

    return "";
}

std::string Parser::parseStartingState(std::ifstream &file) {
    std::string currentLine;

    getline(file, currentLine);

    if (hasLineMultipleItems(currentLine)) return "No starting state provided";
    if (!isValidState(currentLine)) return "Non-existеnt starting state selected";

    startingState = getStateIndex(currentLine);

    return "";
}

std::string Parser::parseAcceptingState(std::ifstream &file) {
    std::string currentLine;

    getline(file, currentLine);

    if (hasLineMultipleItems(currentLine)) return "No accepting state provided";
    if (!isValidState(currentLine)) return "Non-existent accepting state selected";

    acceptingState = getStateIndex(currentLine);

    return "";
}

std::string Parser::parseRejectingState(std::ifstream &file) {
    std::string currentLine;

    getline(file, currentLine);

    if (hasLineMultipleItems(currentLine)) return "No rejecting state provided";
    if (!isValidState(currentLine)) return "Non-existеnt rejecting state selected";

    rejectingState = getStateIndex(currentLine);

    return "";
}

std::string Parser::parseTransitions(std::ifstream &file) {
    std::string currentLine;

    // empty the transitions
    transitions.clear();

    while (getline(file, currentLine) && currentLine != ".") {
        int transitionsCount = std::count(currentLine.begin(), currentLine.end(), ',') + 1;
        std::string currentState;
        std::vector<Transition> currentStateTransitions;
        std::pair<int, std::vector<Transition>> currentStateTransitionsPair;

        int currentStateIndex = 0;

        for (int i = 0; i < transitionsCount; i++) {
            // select the current transition
            int commaIndex = currentLine.find(',');
            std::string transitionString = currentLine.substr(0, commaIndex);
            currentLine.erase(0, commaIndex + 1);

            char currentTapeCellContent = transitionString.front();

            // check if the current tape cell content is in the alphabet
            if (!alphabet.hasLetter(currentTapeCellContent)) return "Usage of bad letter for: " + transitionString;

            // erasing the current tape cell content from the line
            transitionString.erase(0, 1);

            if (transitionString.front() != '{') {
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Non-existent state selected for: " + transitionString;
            }

            int endBracketIndex = transitionString.find('}');
            if (endBracketIndex == std::string::npos) {
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Non-existent state selected for: " + transitionString;
            }

            currentState = transitionString.substr(0, transitionString.find('}') + 1);

            if (!isValidState(currentState)) {
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Non-existent state selected for: " + transitionString;
            }

            // erase the current state name
            transitionString.erase(0, transitionString.find('}') + 1);

            currentStateIndex = getStateIndex(currentState);

            // check for '->'
            if (transitionString[0] != '-' || transitionString[1] != '>') {
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Missing transition indicator '->' for: "+transitionString;
            }

            // erase '->'
            transitionString.erase(0, 2);

            // get the content to write on the cell
            char contentToWriteOnCell = transitionString.front();

            if (!alphabet.hasLetter(contentToWriteOnCell)) {
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Usage of bad letter for: " + transitionString;
            }

            // erase the content to write on the cell
            transitionString.erase(0, 1);

            if (transitionString.front() != '{') {
                // put the content to be written back in front
                transitionString.insert(0, 1, contentToWriteOnCell);
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Wrong transition formatting for: " + transitionString;
            }

            endBracketIndex = transitionString.find('}');
            if (endBracketIndex == std::string::npos) {
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Non-existent state selected for: " + transitionString;
            }

            std::string targetState = transitionString.substr(0, transitionString.find('}') + 1);

            if (!isValidState(targetState)) {
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Non-existent state selected for: " + transitionString;
            }

            // erase target state from line
            transitionString.erase(0, transitionString.find('}') + 1);

            if (transitionString.empty()) {
                // put the target state in front
                transitionString.insert(0, targetState);
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Missing command for: "+transitionString;
            } else if (transitionString.size() > 1) {
                // put the target state in front
                transitionString.insert(0, targetState);
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Wrong command formatting for: "+transitionString;
            }

            Command cmd;
            if(!cmd.setCommand(transitionString.front())) {
                // put the target state in front
                transitionString.insert(0, targetState);
                // put '->' back in front
                transitionString.insert(0, "->");
                // put the current state back in front
                transitionString.insert(0, currentState);
                // put the current tape cell content back in front
                transitionString.insert(0, 1, currentTapeCellContent);
                return "Wrong command formatting for: "+transitionString;
            }

            Transition currentTransition = std::make_tuple(currentTapeCellContent, getStateIndex(targetState), contentToWriteOnCell, cmd);

            currentStateTransitions.push_back(currentTransition);
        }

        currentStateTransitionsPair.first = getStateIndex(currentState);
        currentStateTransitionsPair.second = currentStateTransitions;

        transitions.push_back(currentStateTransitionsPair);
    }

    return "";
}

bool Parser::isValidFile() {
    std::ifstream file(fileAddress);
    bool result = file.good();
    file.close();

    return result;
}

bool Parser::isValidExecutionChoice(const std::string& choice) {
    if (choice == "composition") return true;
    if (choice == "extension") return true;
    if (choice == "cycle") return true;

    return false;
}

bool Parser::isValidState(const std::string& state) {
    for (int i = 0; i < states.size(); i++) {
        if (states[i] == state) return true;
    }

    return false;
}

bool Parser::hasLineMultipleItems(const std::string &line) {
    return line.find(',') != std::string::npos;
}

int Parser::getStateIndex(const std::string& state) {
    int i;
    for (i = 0; i < states.size(); i++) {
        if (states[i] == state) break;
    }

    return i;
}