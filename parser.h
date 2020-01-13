//
// Created by Emanuil Gospodinov on 13.01.20.
//

#ifndef TURING_MACHINE_PARSER_H
#define TURING_MACHINE_PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "alphabet.h"
#include "turingMachine.h"
#include "command.h"
//#include "executionChoice.h"

using States = std::vector<std::string>;
using Transition = std::tuple<char, int, char, Command>;
using Transitions = std::vector<std::vector<Transition>>;

class Parser {
    int machineIndex;
    std::string fileAddress;
    std::string executionChoice;
    Alphabet alphabet;
    std::vector<char> input;

    std::vector<States> statesForMachine;
    std::vector<Transitions> transitionsForMachine;
    std::vector<int> startingStateForMachine;
    std::vector<int> acceptingStateForMachine;
    std::vector<int> rejectingStateForMachine;
    std::vector<TuringMachine*>& machines;

    std::string parseAlphabet(std::ifstream& file);
    std::string parseExecutionChoice(std::ifstream& file);
    std::string parseInput(std::ifstream& file);
    std::string parseStates(std::ifstream& file);
    std::string parseStartingState(std::ifstream& file);
    std::string parseAcceptingState(std::ifstream& file);
    std::string parseRejectingState(std::ifstream& file);
    std::string parseTransitions(std::ifstream& file);

    bool isValidFile();
    bool isValidExecutionChoice(const std::string& choice);
    bool isValidState(const std::string& state);
    static bool hasLineMultipleItems(const std::string& line);

    int getStateIndex(const std::string& state);
public:
    Parser(const std::string& fileAddress, std::vector<TuringMachine*>& tms);
    ~Parser();

    std::string parse();
};

#endif //TURING_MACHINE_PARSER_H
