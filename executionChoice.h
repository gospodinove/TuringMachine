//
// Created by Emanuil Gospodinov on 13.01.20.
//

#ifndef TURING_MACHINE_EXECUTIONCHOICE_H
#define TURING_MACHINE_EXECUTIONCHOICE_H

#include <iostream>
#include <string>

class ExecutionChoice {
    std::string choice;

    bool isValidExecutionChoice(std::string choice);
public:
    ExecutionChoice();
    ExecutionChoice(std::string choice);
    ExecutionChoice(const ExecutionChoice& other);
    ExecutionChoice& operator=(const ExecutionChoice& other);
    ~ExecutionChoice();
};

#endif //TURING_MACHINE_EXECUTIONCHOICE_H
