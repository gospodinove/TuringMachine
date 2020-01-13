//
// Created by Emanuil Gospodinov on 13.01.20.
//

#include "../executionChoice.h"

ExecutionChoice::ExecutionChoice() {
    std::string choice;

    std::cout<<"Enter your choice of execution: ";
    std::cin>>choice;

    if (isValidExecutionChoice(choice)) this->choice = choice;
    else std::cout<<"Invalid execution choice\n";
}

ExecutionChoice::ExecutionChoice(std::string choice) {
    if (isValidExecutionChoice(choice)) this->choice = choice;
    else std::cout<<"Invalid execution choice\n";
}

ExecutionChoice::ExecutionChoice(const ExecutionChoice& other) {
    // todo: finish other constructors
}

ExecutionChoice& ExecutionChoice::operator=(const ExecutionChoice& other) {
    if (this != &other) {

    }
}

ExecutionChoice::~ExecutionChoice() {

}

bool ExecutionChoice::isValidExecutionChoice(std::string choice) {
    if (choice == "composition") return true;
    if (choice == "extension") return true;
    if (choice == "cycle") return true;

    return false;
}