# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/chiara/Apps/CLion-2017.2.3/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/chiara/Apps/CLion-2017.2.3/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug

# Include any dependencies generated for this target.
include tests/google-test/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include tests/google-test/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/google-test/CMakeFiles/gtest_main.dir/flags.make

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: tests/google-test/CMakeFiles/gtest_main.dir/flags.make
tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../tests/google-test/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/tests/google-test/src/gtest_main.cc

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/tests/google-test/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/tests/google-test/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f tests/google-test/CMakeFiles/gtest_main.dir/build.make tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/build.make
tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/google-test/CMakeFiles/gtest_main.dir/build: tests/google-test/libgtest_main.a

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/build

tests/google-test/CMakeFiles/gtest_main.dir/requires: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/requires

tests/google-test/CMakeFiles/gtest_main.dir/clean:
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/clean

tests/google-test/CMakeFiles/gtest_main.dir/depend:
	cd /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/tests/google-test /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test /home/chiara/Documents/UBA/AED2/Labo/taller4_trie/alumnos/cmake-build-debug/tests/google-test/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/depend
