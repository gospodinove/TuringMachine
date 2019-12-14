//
// Created by Emanuil Gospodinov on 20.11.19.
//

#ifndef TURING_MACHINE_TURINGMACHINE_H
#define TURING_MACHINE_TURINGMACHINE_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "command.h"
#include "tape.h"


using TransitionUpdate = std::tuple<int, char, Command>;
using States = std::vector<std::string>;
using Transitions = std::vector<std::vector<TransitionUpdate>>;

class TuringMachine {
    Tape tape;
    States states;
    Transitions transitions;
    int startState;
    int acceptState;
    int rejectState;
    int currentState;

    void enterTransitions();
    void enterStates();
    void printStates();

    bool isValidState(int id);
public:
    TuringMachine();
    explicit TuringMachine(Tape const &tape);
    TuringMachine(TuringMachine const &other);
    TuringMachine(Tape const &tape, States const &states, Transitions const &transitions, int const &start, int const &acpt, int const &rjct);
    TuringMachine& operator=(TuringMachine const &other);
    ~TuringMachine();

    void move(char direction);
    void writeOnCurrentCell(char data);

    Tape& getTape();
    TapeCell* getCurrentTapeCell();

    bool start();
};
#endif //TURING_MACHINE_TURINGMACHINE_H
