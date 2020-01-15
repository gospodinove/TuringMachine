//
// Created by Emanuil Gospodinov on 20.11.19.
//

#ifndef TURING_MACHINE_TAPE_H
#define TURING_MACHINE_TAPE_H

#include <iostream>
#include <string>
#include "tapeCell.h"
#include "alphabet.h"

class Tape {
    TapeCell *head;
    Alphabet alphabet;
    // currently examined cell
    TapeCell *current;

    bool isValidMove(char direction);

    void append(char data);
    void prepend(char data);
public:
    Tape();
    Tape(Tape const &other);
    Tape(const Alphabet& alphabet);
    Tape(const Alphabet& alphabet, const std::vector<char>& content);
    Tape& operator=(Tape const &other);
    ~Tape();

    void print();

    TapeCell* moveCurrent(char direction); // move current cell indicator
    void writeOnCurrent(char data);

    TapeCell* getHead();
    TapeCell* getCurrent();
    Alphabet& getAlphabet();

    std::string getTapeContent();
};
#endif //TURING_MACHINE_TAPE_H
