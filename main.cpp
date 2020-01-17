#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tapeCell.h"
#include "tape.h"
#include "command.h"
#include "turingMachine.h"
#include "alphabet.h"
#include "parser.h"
#include <iostream>

TEST_CASE("Turing Machine functionality test") {
    Alphabet alphabet({'0', '1'});
    std::vector<char> content = {'0', '1', '1', '1', '0'};

    std::vector<std::string> states = {"A", "B", "C", "Reject", "Accept"};
    std::vector<std::pair<int, std::vector<std::tuple<char, int, char, Command>>>> transitions = {
            {0, {{'0', 1, '0', Command('R')}, {'1', 3, '1', Command('R')}, {' ', 3, ' ', Command('R')}}},
            {1, {{'0', 2, '0', Command('R')}, {'1', 1, '1', Command('R')}, {' ', 3, ' ', Command('R')}}},
            {2, {{'0', 3, '0', Command('R')}, {'1', 3, '1', Command('R')}, {' ', 4, ' ', Command('R')}}}
    };

    TuringMachine tm(alphabet, content, states, transitions, 0, 4, 3);

            CHECK(tm.start());
}

TEST_CASE("Reading Turing Machine from file") {
    std::string t1FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t1.csv";
    std::string t2FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t2.csv";
    std::string t3FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t3.csv";

    std::string outputFilePath = "/Users/gospodinove/CLionProjects/TuringMachine/output.csv";

    TuringMachine* t1;
    TuringMachine* t2;
    TuringMachine* t3;

    Parser parser1(t1FilePath), parser2(t2FilePath), parser3(t3FilePath);

    std::string parsingMessage1 = parser1.parse();
    std::string parsingMessage2 = parser2.parse();
    std::string parsingMessage3 = parser3.parse();

    if (parsingMessage1 == "none") {
        t1 = parser1.getMachine();
                CHECK(t1->start());
    } else {
        std::cout<<parsingMessage1<<std::endl;
    }

    if (parsingMessage2 == "none") {
        t2 = parser2.getMachine();
                CHECK(t2->start());
    } else {
        std::cout<<parsingMessage2<<std::endl;
    }

    if (parsingMessage3 == "none") {
        t3 = parser3.getMachine();
                CHECK(t3->start());
    } else {
        std::cout<<parsingMessage3<<std::endl;
    }

    // delete the dynamic memory
    delete t1;
    delete t2;
    delete t3;
}

void extension(std::string& fileAddress, TuringMachine* tm1, TuringMachine* tm2, TuringMachine* tm3) {
    if (tm1->start() && tm2->start()) {
        tm2->writeTapeOnFile(fileAddress);
    } else if (!tm1->start() && tm3->start()) {
        tm3->writeTapeOnFile(fileAddress);
    }
}

TEST_CASE("Extension test") {
    std::string t1FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t1.csv";
    std::string t2FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t2.csv";
    std::string t3FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t3.csv";

    std::string outputFilePath = "/Users/gospodinove/CLionProjects/TuringMachine/output.csv";

    TuringMachine* t1 = nullptr;
    TuringMachine* t2 = nullptr;
    TuringMachine* t3 = nullptr;

    Parser parser1(t1FilePath), parser2(t2FilePath), parser3(t3FilePath);

    std::string parsingMessage1 = parser1.parse();
    std::string parsingMessage2 = parser2.parse();
    std::string parsingMessage3 = parser3.parse();

    if (parsingMessage1 == "none") {
        t1 = parser1.getMachine();
    } else {
        std::cout<<parsingMessage1<<std::endl;
    }

    if (parsingMessage2 == "none") {
        t2 = parser2.getMachine();
    } else {
        std::cout<<parsingMessage2<<std::endl;
    }

    if (parsingMessage3 == "none") {
        t3 = parser3.getMachine();
    } else {
        std::cout<<parsingMessage3<<std::endl;
    }

    extension(outputFilePath, t1, t2, t3);

    // delete the dynamic memory
    delete t1;
    delete t2;
    delete t3;
}

TEST_CASE("Composition test") {
    std::string t1FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t1.csv";
    std::string t2FilePath = "/Users/gospodinove/CLionProjects/TuringMachine/t2.csv";

    std::string outputFilePath = "/Users/gospodinove/CLionProjects/TuringMachine/output2.csv";

    TuringMachine* t1;
    TuringMachine* t2;

    Parser parser1(t1FilePath), parser2(t2FilePath);

    std::string parsingMessage1 = parser1.parse();
    std::string parsingMessage2 = parser2.parse();

    t1 = parser1.getMachine();
    t2 = parser2.getMachine();

    TuringMachine composed(t1, t2);

    CHECK(composed.start());

    composed.writeTapeOnFile(outputFilePath);

    delete t1;
    delete t2;
}

TEST_CASE("TapeCell class test") {
    TapeCell node;
    CHECK(node.getData() == ' ');
    CHECK(node.next == nullptr);
    CHECK(node.prev == nullptr);
}

TEST_CASE("Tape class test && append/prepend functionality test") {
    std::vector letters = {'a', 'b', 'c'};
    std::vector content = {'a', 'b', 'a', 'a', 'a'};

    Alphabet alphabet(letters);
    Tape tape(alphabet, content);

    letters.insert(letters.begin(), ' ');

    CHECK(tape.getAlphabet().getLetters() == letters);
}

TEST_CASE("Alphabet and checking if letter is in alphabet") {
    std::vector<char> test = {' ', 'a'};
    Alphabet a, b(test);

    a.addLetter('a');
    a.addLetter(' ');

    CHECK(a.getLetters() == test);
    CHECK(b.getLetters() == test);
    CHECK(a.hasLetter('a'));
    CHECK(b.hasLetter(' '));
    CHECK(!a.hasLetter('b'));
}

TEST_CASE("Command class test") {
    Command c;

    c.setCommand('R');
    CHECK(c.getCommand() == 'R');
}

// Uncomment the next test in order to go through
// the process of defining the state machine yourself

//TEST_CASE("Turing machine init") {
//    TuringMachine tm;
//
//    CHECK(tm.getTape().getHead() == tm.getCurrentTapeCell());
//}