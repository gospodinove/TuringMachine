# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gospodinove/Projects/TuringMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gospodinove/Projects/TuringMachine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Turing_Machine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Turing_Machine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Turing_Machine.dir/flags.make

CMakeFiles/Turing_Machine.dir/main.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Turing_Machine.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/main.cpp.o -c /Users/gospodinove/Projects/TuringMachine/main.cpp

CMakeFiles/Turing_Machine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/main.cpp > CMakeFiles/Turing_Machine.dir/main.cpp.i

CMakeFiles/Turing_Machine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/main.cpp -o CMakeFiles/Turing_Machine.dir/main.cpp.s

CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o: ../src/turingMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o -c /Users/gospodinove/Projects/TuringMachine/src/turingMachine.cpp

CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/src/turingMachine.cpp > CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.i

CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/src/turingMachine.cpp -o CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.s

CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o: ../src/tapeCell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o -c /Users/gospodinove/Projects/TuringMachine/src/tapeCell.cpp

CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/src/tapeCell.cpp > CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.i

CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/src/tapeCell.cpp -o CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.s

CMakeFiles/Turing_Machine.dir/src/tape.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/src/tape.cpp.o: ../src/tape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Turing_Machine.dir/src/tape.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/src/tape.cpp.o -c /Users/gospodinove/Projects/TuringMachine/src/tape.cpp

CMakeFiles/Turing_Machine.dir/src/tape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/src/tape.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/src/tape.cpp > CMakeFiles/Turing_Machine.dir/src/tape.cpp.i

CMakeFiles/Turing_Machine.dir/src/tape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/src/tape.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/src/tape.cpp -o CMakeFiles/Turing_Machine.dir/src/tape.cpp.s

CMakeFiles/Turing_Machine.dir/src/command.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/src/command.cpp.o: ../src/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Turing_Machine.dir/src/command.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/src/command.cpp.o -c /Users/gospodinove/Projects/TuringMachine/src/command.cpp

CMakeFiles/Turing_Machine.dir/src/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/src/command.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/src/command.cpp > CMakeFiles/Turing_Machine.dir/src/command.cpp.i

CMakeFiles/Turing_Machine.dir/src/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/src/command.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/src/command.cpp -o CMakeFiles/Turing_Machine.dir/src/command.cpp.s

CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o: CMakeFiles/Turing_Machine.dir/flags.make
CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o: ../src/alphabet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o -c /Users/gospodinove/Projects/TuringMachine/src/alphabet.cpp

CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gospodinove/Projects/TuringMachine/src/alphabet.cpp > CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.i

CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gospodinove/Projects/TuringMachine/src/alphabet.cpp -o CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.s

# Object files for target Turing_Machine
Turing_Machine_OBJECTS = \
"CMakeFiles/Turing_Machine.dir/main.cpp.o" \
"CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o" \
"CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o" \
"CMakeFiles/Turing_Machine.dir/src/tape.cpp.o" \
"CMakeFiles/Turing_Machine.dir/src/command.cpp.o" \
"CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o"

# External object files for target Turing_Machine
Turing_Machine_EXTERNAL_OBJECTS =

Turing_Machine: CMakeFiles/Turing_Machine.dir/main.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/src/turingMachine.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/src/tapeCell.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/src/tape.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/src/command.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/src/alphabet.cpp.o
Turing_Machine: CMakeFiles/Turing_Machine.dir/build.make
Turing_Machine: CMakeFiles/Turing_Machine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Turing_Machine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Turing_Machine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Turing_Machine.dir/build: Turing_Machine

.PHONY : CMakeFiles/Turing_Machine.dir/build

CMakeFiles/Turing_Machine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Turing_Machine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Turing_Machine.dir/clean

CMakeFiles/Turing_Machine.dir/depend:
	cd /Users/gospodinove/Projects/TuringMachine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gospodinove/Projects/TuringMachine /Users/gospodinove/Projects/TuringMachine /Users/gospodinove/Projects/TuringMachine/cmake-build-debug /Users/gospodinove/Projects/TuringMachine/cmake-build-debug /Users/gospodinove/Projects/TuringMachine/cmake-build-debug/CMakeFiles/Turing_Machine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Turing_Machine.dir/depend

