//
// Created by Emanuil Gospodinov on 20.11.19.
//

#ifndef TURING_MACHINE_TURINGMACHINE_H
#define TURING_MACHINE_TURINGMACHINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include "command.h"
#include "tape.h"


using Transition = std::tuple<char, int, char, Command>;
using States = std::vector<std::string>;
using Transitions = std::vector<std::pair<std::string, std::vector<Transition>>>;

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
    bool isValidTransition(Transition tr);
public:
    TuringMachine();
    TuringMachine(TuringMachine const &other);
    TuringMachine(Tape const &tape, States const &states, Transitions const &transitions, int const &start, int const &acpt, int const &rjct);
    // composition
    TuringMachine(TuringMachine* t1, TuringMachine* t2);
    TuringMachine& operator=(TuringMachine const &other);
    ~TuringMachine();

    void move(char direction); // move the machine's head
    void writeOnCurrentCell(char data);

    Tape& getTape();
    TapeCell* getCurrentTapeCell();

    // start the machine
    // returns true if the input is accepted
    // otherwise returns false
    bool start();

    std::string writeTapeOnFile(const std::string& fileAddress);
};
#endif //TURING_MACHINE_TURINGMACHINE_H
