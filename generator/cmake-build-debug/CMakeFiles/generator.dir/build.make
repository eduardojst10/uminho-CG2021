# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/eduardo/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/eduardo/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eduardo/Desktop/CG2021-OFICIAL/generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/main.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/main.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/main.cpp

CMakeFiles/generator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/main.cpp > CMakeFiles/generator.dir/main.cpp.i

CMakeFiles/generator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/main.cpp -o CMakeFiles/generator.dir/main.cpp.s

CMakeFiles/generator.dir/models/plano.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/models/plano.cpp.o: ../models/plano.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generator.dir/models/plano.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/models/plano.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/plano.cpp

CMakeFiles/generator.dir/models/plano.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/models/plano.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/plano.cpp > CMakeFiles/generator.dir/models/plano.cpp.i

CMakeFiles/generator.dir/models/plano.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/models/plano.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/plano.cpp -o CMakeFiles/generator.dir/models/plano.cpp.s

CMakeFiles/generator.dir/models/box.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/models/box.cpp.o: ../models/box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/generator.dir/models/box.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/models/box.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/box.cpp

CMakeFiles/generator.dir/models/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/models/box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/box.cpp > CMakeFiles/generator.dir/models/box.cpp.i

CMakeFiles/generator.dir/models/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/models/box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/box.cpp -o CMakeFiles/generator.dir/models/box.cpp.s

CMakeFiles/generator.dir/models/sphere.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/models/sphere.cpp.o: ../models/sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/generator.dir/models/sphere.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/models/sphere.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/sphere.cpp

CMakeFiles/generator.dir/models/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/models/sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/sphere.cpp > CMakeFiles/generator.dir/models/sphere.cpp.i

CMakeFiles/generator.dir/models/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/models/sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/sphere.cpp -o CMakeFiles/generator.dir/models/sphere.cpp.s

CMakeFiles/generator.dir/models/cone.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/models/cone.cpp.o: ../models/cone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/generator.dir/models/cone.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/models/cone.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/cone.cpp

CMakeFiles/generator.dir/models/cone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/models/cone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/cone.cpp > CMakeFiles/generator.dir/models/cone.cpp.i

CMakeFiles/generator.dir/models/cone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/models/cone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/cone.cpp -o CMakeFiles/generator.dir/models/cone.cpp.s

CMakeFiles/generator.dir/models/bezierPatch.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/models/bezierPatch.cpp.o: ../models/bezierPatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/generator.dir/models/bezierPatch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/models/bezierPatch.cpp.o -c /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/bezierPatch.cpp

CMakeFiles/generator.dir/models/bezierPatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/models/bezierPatch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/bezierPatch.cpp > CMakeFiles/generator.dir/models/bezierPatch.cpp.i

CMakeFiles/generator.dir/models/bezierPatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/models/bezierPatch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/CG2021-OFICIAL/generator/models/bezierPatch.cpp -o CMakeFiles/generator.dir/models/bezierPatch.cpp.s

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/main.cpp.o" \
"CMakeFiles/generator.dir/models/plano.cpp.o" \
"CMakeFiles/generator.dir/models/box.cpp.o" \
"CMakeFiles/generator.dir/models/sphere.cpp.o" \
"CMakeFiles/generator.dir/models/cone.cpp.o" \
"CMakeFiles/generator.dir/models/bezierPatch.cpp.o"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator: CMakeFiles/generator.dir/main.cpp.o
generator: CMakeFiles/generator.dir/models/plano.cpp.o
generator: CMakeFiles/generator.dir/models/box.cpp.o
generator: CMakeFiles/generator.dir/models/sphere.cpp.o
generator: CMakeFiles/generator.dir/models/cone.cpp.o
generator: CMakeFiles/generator.dir/models/bezierPatch.cpp.o
generator: CMakeFiles/generator.dir/build.make
generator: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: generator

.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	cd /home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/CG2021-OFICIAL/generator /home/eduardo/Desktop/CG2021-OFICIAL/generator /home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug /home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug /home/eduardo/Desktop/CG2021-OFICIAL/generator/cmake-build-debug/CMakeFiles/generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generator.dir/depend

