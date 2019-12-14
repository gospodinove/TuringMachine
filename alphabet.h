//
// Created by Emanuil Gospodinov on 21.11.19.
//

#ifndef TURING_MACHINE_ALPHABET_H
#define TURING_MACHINE_ALPHABET_H

#include <vector>

class Alphabet {
    std::vector<char> letters;
public:
    Alphabet();
    Alphabet(std::vector<char> letters);
    Alphabet(Alphabet const &other);
    Alphabet& operator=(Alphabet const &other);
    ~Alphabet();

    bool hasLetter(char letter);
    void addLetter(char letter);

    std::vector<char> getLetters();
    void print();

    void enter();
};

#endif //TURING_MACHINE_ALPHABET_H
