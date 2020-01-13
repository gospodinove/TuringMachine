//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include "../turingMachine.h"

using Transition = std::tuple<char, int, char, Command>;
using States = std::vector<std::string>;
using Transitions = std::vector<std::vector<Transition>>;

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
        for (Transition transition: row) {
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
TuringMachine::TuringMachine(TuringMachine &t1, TuringMachine &t2) {
    // start state
    startState = t1.startState;
    // accept state
    acceptState = t1.states.size() - 1 + t2.acceptState;
    // reject state
    rejectState = t1.states.size() - 1 + t2.rejectState;
    // states
    states.insert(states.end(), t1.states.begin(), t1.states.end());
    states.insert(states.end(), t2.states.begin(), t2.states.end());
    // alphabet
    tape.getAlphabet().getLetters().insert(
            tape.getAlphabet().getLetters().end(),
            t1.tape.getAlphabet().getLetters().begin(),
            t1.tape.getAlphabet().getLetters().end());
    tape.getAlphabet().getLetters().insert(
            tape.getAlphabet().getLetters().end(),
            t2.tape.getAlphabet().getLetters().begin(),
            t2.tape.getAlphabet().getLetters().end());
    // transitions
    transitions.insert(
            transitions.end(),
            t1.transitions.begin(),
            t1.transitions.end());
    transitions.insert(
            transitions.end(),
            t2.transitions.begin(),
            t2.transitions.end());
        // define the other "special" transitions
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
TuringMachine::~TuringMachine(){

}

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

        transitions.push_back(currentStateTransitions);
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
        int index = -1;
        Transition update;

        char currentTapeCellContent = getCurrentTapeCell()->getData();

        do {
            index++;
            update = transitions[currentState][index];
        } while (index < transitions[currentState].size() &&
                 std::get<0>(transitions[currentState][index]) != currentTapeCellContent);

        if (index < transitions[currentState].size()) {
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

void TuringMachine::printTransitions() {
    for (int i = 0; i < transitions.size(); i++) {
        for (auto transition: transitions[i]) {
            std::cout<<std::get<0>(transition);
            std::cout<<states[i];
            std::cout<<"->";
            std::cout<<std::get<2>(transition);
            std::cout<<states[std::get<1>(transition)];
            std::cout<<std::get<3>(transition).getCommand();
            std::cout<<",";
        }
        std::cout<<std::endl;
    }
}