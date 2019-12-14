//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include "../turingMachine.h"

using TransitionUpdate = std::tuple<int, char, Command>;
using States = std::vector<std::string>;
using Transitions = std::vector<std::vector<TransitionUpdate>>;

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
TuringMachine::TuringMachine(Tape const &tape) {
    this->tape = tape;
    enterStates();
    enterTransitions();
    currentState = startState;
}
TuringMachine::TuringMachine(Tape const &tape, States const &states, Transitions const &transitions, int const &start,
                             int const &acpt, int const &rjct) {
    this->tape = tape;
    this->states = states;
    this->transitions = transitions;
    this->startState = start;
    this->acceptState = acpt;
    this->rejectState = rjct;

    currentState = start;
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
        std::vector<TransitionUpdate> currentStateTransitions;

        for (int j = 0; j < tape.getAlphabet().getLetters().size(); j++) {
            int selectedState;
            char newCellContent, direction;
            Command cmd;
            TransitionUpdate update;

            std::cout << "Transitions from state '" << states[i]
                      << "' with " << tape.getAlphabet().getLetters()[j] << std::endl;

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

            update = std::make_tuple(selectedState, newCellContent, cmd);

            currentStateTransitions.push_back(update);
        }

        transitions.push_back(currentStateTransitions);
    }

    std::cout << "\n\n";
}

bool TuringMachine::isValidState(int id) {
    return states.size() > id && id >= 0;
}

bool TuringMachine::start() {
    while (currentState != acceptState && currentState != rejectState) {
        std::cout<<"Current state: "<<currentState<<std::endl;

        char currentTapeCellContent = getCurrentTapeCell()->getData();
        auto iterator = std::find(
                tape.getAlphabet().getLetters().begin(),
                tape.getAlphabet().getLetters().end(),
                currentTapeCellContent);
        int letterAlphabetID = std::distance(
                tape.getAlphabet().getLetters().begin(),
                iterator);

        auto update = transitions[currentState][letterAlphabetID];

        currentState = std::get<0>(update);
        writeOnCurrentCell(std::get<1>(update));
        move(std::get<2>(update).getCommand());
    }

    return currentState == acceptState;
}