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
CMAKE_SOURCE_DIR = /home/chiara/Documents/UBA/AED2/alumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/horario_gtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/horario_gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/horario_gtest.dir/flags.make

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o: CMakeFiles/horario_gtest.dir/flags.make
CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o: ../tests/test_horario.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o -c /home/chiara/Documents/UBA/AED2/alumnos/tests/test_horario.cpp

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiara/Documents/UBA/AED2/alumnos/tests/test_horario.cpp > CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.i

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiara/Documents/UBA/AED2/alumnos/tests/test_horario.cpp -o CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.s

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.requires:

.PHONY : CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.requires

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.provides: CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.requires
	$(MAKE) -f CMakeFiles/horario_gtest.dir/build.make CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.provides.build
.PHONY : CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.provides

CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.provides.build: CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o


# Object files for target horario_gtest
horario_gtest_OBJECTS = \
"CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o"

# External object files for target horario_gtest
horario_gtest_EXTERNAL_OBJECTS =

horario_gtest: CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o
horario_gtest: CMakeFiles/horario_gtest.dir/build.make
horario_gtest: tests/google-test/libgtest.a
horario_gtest: tests/google-test/libgtest_main.a
horario_gtest: tests/google-test/libgtest.a
horario_gtest: CMakeFiles/horario_gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable horario_gtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/horario_gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/horario_gtest.dir/build: horario_gtest

.PHONY : CMakeFiles/horario_gtest.dir/build

CMakeFiles/horario_gtest.dir/requires: CMakeFiles/horario_gtest.dir/tests/test_horario.cpp.o.requires

.PHONY : CMakeFiles/horario_gtest.dir/requires

CMakeFiles/horario_gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/horario_gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/horario_gtest.dir/clean

CMakeFiles/horario_gtest.dir/depend:
	cd /home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiara/Documents/UBA/AED2/alumnos /home/chiara/Documents/UBA/AED2/alumnos /home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug /home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug /home/chiara/Documents/UBA/AED2/alumnos/cmake-build-debug/CMakeFiles/horario_gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/horario_gtest.dir/depend

