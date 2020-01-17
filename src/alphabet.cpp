//
// Created by Emanuil Gospodinov on 21.11.19.
//

#include "../alphabet.h"

Alphabet::Alphabet() {
    addLetter(' ');
}
Alphabet::Alphabet(std::vector<char> letters) {
    addLetter(' ');
    for (auto letter: letters) {
        addLetter(letter);
    }
}
Alphabet::Alphabet(Alphabet const &other) {
    letters = other.letters;
}
Alphabet& Alphabet::operator=(Alphabet const &other) {
    if (this != &other) {
        letters = other.letters;
    }
    return *this;
}
Alphabet::~Alphabet(){

}

void Alphabet::addLetter(char letter) {
    if (!hasLetter(letter)) {
        letters.push_back(letter);
    }
}

bool Alphabet::hasLetter(char letter) {
    for (char i : letters) {
        if (i == letter) {
            return true;
        }
    }

    return false;
}

std::vector<char> Alphabet::getLetters() {
    return letters;
}

void Alphabet::enter() {
    char keepAddingAnswer;

    do {
        char letter;
        std::cout << "Enter letter: ";
        std::cin >> letter;

        addLetter(letter);

        std::cout << "Do you wish to add another letter (Y/N): ";
        std::cin >> keepAddingAnswer;
    } while (keepAddingAnswer == 'y' || keepAddingAnswer == 'Y');

    std::cout << "\n\n";
}