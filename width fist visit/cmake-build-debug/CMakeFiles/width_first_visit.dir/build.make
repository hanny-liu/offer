# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/lhw/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lhw/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/lhw/workspace/c++/width fist visit"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lhw/workspace/c++/width fist visit/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/width_first_visit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/width_first_visit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/width_first_visit.dir/flags.make

CMakeFiles/width_first_visit.dir/main.cpp.o: CMakeFiles/width_first_visit.dir/flags.make
CMakeFiles/width_first_visit.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lhw/workspace/c++/width fist visit/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/width_first_visit.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/width_first_visit.dir/main.cpp.o -c "/home/lhw/workspace/c++/width fist visit/main.cpp"

CMakeFiles/width_first_visit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/width_first_visit.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lhw/workspace/c++/width fist visit/main.cpp" > CMakeFiles/width_first_visit.dir/main.cpp.i

CMakeFiles/width_first_visit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/width_first_visit.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lhw/workspace/c++/width fist visit/main.cpp" -o CMakeFiles/width_first_visit.dir/main.cpp.s

# Object files for target width_first_visit
width_first_visit_OBJECTS = \
"CMakeFiles/width_first_visit.dir/main.cpp.o"

# External object files for target width_first_visit
width_first_visit_EXTERNAL_OBJECTS =

width_first_visit: CMakeFiles/width_first_visit.dir/main.cpp.o
width_first_visit: CMakeFiles/width_first_visit.dir/build.make
width_first_visit: CMakeFiles/width_first_visit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lhw/workspace/c++/width fist visit/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable width_first_visit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/width_first_visit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/width_first_visit.dir/build: width_first_visit

.PHONY : CMakeFiles/width_first_visit.dir/build

CMakeFiles/width_first_visit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/width_first_visit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/width_first_visit.dir/clean

CMakeFiles/width_first_visit.dir/depend:
	cd "/home/lhw/workspace/c++/width fist visit/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lhw/workspace/c++/width fist visit" "/home/lhw/workspace/c++/width fist visit" "/home/lhw/workspace/c++/width fist visit/cmake-build-debug" "/home/lhw/workspace/c++/width fist visit/cmake-build-debug" "/home/lhw/workspace/c++/width fist visit/cmake-build-debug/CMakeFiles/width_first_visit.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/width_first_visit.dir/depend

