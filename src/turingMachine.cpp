//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include "../turingMachine.h"

using Transition = std::tuple<char, int, char, Command>;
using States = std::vector<std::string>;
using Transitions = std::vector<std::pair<std::string, std::vector<Transition>>>;

TuringMachine::TuringMachine() {
    tape.getAlphabet().enter();
    enterStates();
    enterTransitions();
    currentState = startState;
}
TuringMachine::TuringMachine(TuringMachine const &other) {
    tape = other.tape;
    states = other.states;
    transitions = other.transitions;
    startState = other.startState;
    acceptState = other.acceptState;
    rejectState = other.rejectState;
    currentState = other.currentState;
}
TuringMachine::TuringMachine(Tape const &tape, States const &states, Transitions const &transitions, int const &start, int const &acpt, int const &rjct) {
    bool shouldAcceptTransitions = true;

    this->tape = tape;
    this->states = states;

    for (auto row: transitions) {
        for (Transition transition: row.second) {
            if (!isValidTransition(transition)) shouldAcceptTransitions = false;
        }
    }

    if (shouldAcceptTransitions) {
        this->transitions = transitions;
    } else {
        std::cerr << "An invalid transition was found\n";
    }

    this->startState = start;
    this->acceptState = acpt;
    this->rejectState = rjct;

    currentState = start;
}
// composition
TuringMachine::TuringMachine(TuringMachine* t1, TuringMachine* t2) {
    // Composition -> T1(T2)

    // start state
    startState = t2->startState;
    // accept state
    acceptState = t2->states.size() + t1->acceptState;
    // reject state
    rejectState = t2->states.size() + t1->rejectState;
    // current state
    currentState = startState;

    // states
    // TODO: Check for state uniqueness
    states.insert(states.end(), t2->states.begin(), t2->states.end());
    states.insert(states.end(), t1->states.begin(), t1->states.end());

    // alphabet
    for (auto letter : t1->tape.getAlphabet().getLetters()) {
        tape.getAlphabet().addLetter(letter);
    }

    for (auto letter : t2->tape.getAlphabet().getLetters()) {
        tape.getAlphabet().addLetter(letter);
    }

    // transitions
    transitions.insert(
            transitions.end(),
            t2->transitions.begin(),
            t2->transitions.end());
    transitions.insert(
            transitions.end(),
            t1->transitions.begin(),
            t1->transitions.end());

    // getting the transitions of starting state of the outer machine and adding them
    // to the transitions of the accepting state of the inner machine
    std::vector<Transition> transiotionsToReplicate;
    int i = -1;

    do {
        i++;
        transiotionsToReplicate = t1->transitions[i].second;
    } while (i < t1->transitions.size() && t1->transitions[i].first != t1->states[t1->startState]);

    // correct the indexes of the transitions
    for (int j = 0; j < transiotionsToReplicate.size(); j++) {
        std::get<1>(transiotionsToReplicate[j]) = std::get<1>(transiotionsToReplicate[j]) + t2->states.size();
    }

    std::pair<std::string, std::vector<Transition>> transitionsPair = {t2->states[t2->acceptState], transiotionsToReplicate};

    transitions.push_back(transitionsPair);

    // make transitions from the inner reject state to the outer reject state
    transitionsPair.first = t2->states[t2->rejectState];

    // create the transitions
    transiotionsToReplicate.clear();

    for (auto letter : tape.getAlphabet().getLetters()) {
        Transition tr = {letter, rejectState, letter, Command('S')};
        transiotionsToReplicate.push_back(tr);
    }

    transitionsPair.second = transiotionsToReplicate;
    transitions.push_back(transitionsPair);
}
TuringMachine& TuringMachine::operator=(TuringMachine const &other) {
    if (this != &other) {
        tape = other.tape;
        states = other.states;
        transitions = other.transitions;
        startState = other.startState;
        acceptState = other.acceptState;
        rejectState = other.rejectState;
        currentState = other.currentState;
    }
    return *this;
}
TuringMachine::~TuringMachine() = default;

void TuringMachine::move(char direction) {
    tape.moveCurrent(direction);
}
void TuringMachine::writeOnCurrentCell(char data) {
    tape.writeOnCurrent(data);
}

TapeCell* TuringMachine::getCurrentTapeCell() {
    return tape.getCurrent();
}
Tape& TuringMachine::getTape() {
    return tape;
}

void TuringMachine::printStates() {
    for (int i = 0; i < states.size(); i++) {
        std::cout << i <<". "<<states[i]<<std::endl;
    }
}

void TuringMachine::enterStates() {
    char keepAddingAnswer;
    int selectedState;

    do {
        std::string name;
        std::cout << "Enter state name: ";
        std::cin >> name;

        states.push_back(name);

        std::cout << "Do you wish to add another state (Y/N): ";
        std::cin >> keepAddingAnswer;
    } while (keepAddingAnswer == 'y' || keepAddingAnswer == 'Y');

    std::cout << "\n\n";

    std::cout << "To select a state enter its number\n";

    printStates();

    do {
        std::cout << "Which state is the starting state: ";
        std::cin >> selectedState;
    } while (!isValidState(selectedState));
    startState = selectedState;

    do {
        std::cout << "Which state is the accepting state: ";
        std::cin >> selectedState;
    } while (!isValidState(selectedState));
    acceptState = selectedState;

    do {
        std::cout << "Which state is the rejecting state: ";
        std::cin >> selectedState;
    } while (!isValidState(selectedState) || selectedState == acceptState);
    rejectState = selectedState;

    std::cout << "\n\n";
}

void TuringMachine::enterTransitions() {
    std::cout << "To select a state enter its number\n";

    printStates();

    for (int i = 0; i < states.size(); i++) {
        std::vector<Transition> currentStateTransitions;

        for (int j = 0; j < tape.getAlphabet().getLetters().size(); j++) {
            int selectedState;
            char newCellContent, direction, desireToRegisterTransition;
            Command cmd;
            Transition update;

            char currentLetter = tape.getAlphabet().getLetters()[j];

            std::cout << "Do you want to register a transition from '" << states[i]
                      << "' with " << currentLetter
                      << " (Y/N): ";
            std::cin >> desireToRegisterTransition;

            if (desireToRegisterTransition == 'y' || desireToRegisterTransition == 'Y') {
                std::cout << "Transition from state '" << states[i]
                          << "' with " << currentLetter << std::endl;

                do {
                    std::cout << "Goes to state: ";
                    std::cin >> selectedState;
                } while (!isValidState(selectedState));

                do {
                    std::cout << "Writes on current tape cell: ";
                    std::cin >> newCellContent;
                } while (!tape.getAlphabet().hasLetter(newCellContent));

                do {
                    std::cout << "Move head (L, R, S): ";
                    std::cin >> direction;
                } while (!cmd.setCommand(direction));

                update = std::make_tuple(currentLetter, selectedState, newCellContent, cmd);

                currentStateTransitions.push_back(update);
            }
        }

        transitions.push_back(std::pair(states[i], currentStateTransitions));
    }

    std::cout << "\n\n";
}

bool TuringMachine::isValidState(int id) {
    return states.size() > id && id >= 0;
}

bool TuringMachine::isValidTransition(Transition tr) {
    return  tape.getAlphabet().hasLetter(std::get<0>(tr)) &&
            isValidState(std::get<1>(tr)) &&
            tape.getAlphabet().hasLetter(std::get<2>(tr));
}

bool TuringMachine::start() {
    while (currentState != acceptState && currentState != rejectState) {
        int i = -1,j = -1;
        std::vector<Transition> currentStateTransitions;
        Transition update;

        // select the transitions of the current state
        do {
            i++;
            currentStateTransitions = transitions[i].second;
        } while (i < transitions.size() && transitions[i].first != states[currentState]);

        char currentTapeCellContent = getCurrentTapeCell()->getData();

        do {
            j++;
            update = currentStateTransitions[j];
        } while (j < currentStateTransitions.size() &&
                 std::get<0>(currentStateTransitions[j]) != currentTapeCellContent);

        if (j < currentStateTransitions.size()) {
            currentState = std::get<1>(update);
            writeOnCurrentCell(std::get<2>(update));
            move(std::get<3>(update).getCommand());
        } else {
            // assuming that if there is no defined transition
            // we should reject the input
            currentState = rejectState;
        }
    }

    return currentState == acceptState;
}

std::string TuringMachine::writeTapeOnFile(const std::string &fileAddress) {
    std::ofstream oldFile(fileAddress, std::ofstream::trunc);
    oldFile.close();

    std::ofstream newFile(fileAddress, std::ofstream::app);

    if (newFile.good()) {
        newFile << tape.getTapeContent();
    } else {
        return "Could not write on file: " + fileAddress;
    }

    return "";
}
