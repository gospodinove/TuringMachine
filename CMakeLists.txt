cmake_minimum_required(VERSION 3.15)
project(Turing_Machine)

set(CMAKE_CXX_STANDARD 17)

add_executable(Turing_Machine main.cpp doctest.h tapeCell.h src/turingMachine.cpp turingMachine.h src/tapeCell.cpp tape.h src/tape.cpp command.h src/command.cpp alphabet.h src/alphabet.cpp parser.h src/parser.cpp executionChoice.h src/executionChoice.cpp)