# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/jakub/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jakub/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakub/WAT/Kryptologia/Ciphers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cryptology.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cryptology.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cryptology.dir/flags.make

CMakeFiles/Cryptology.dir/main.cpp.o: CMakeFiles/Cryptology.dir/flags.make
CMakeFiles/Cryptology.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cryptology.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Cryptology.dir/main.cpp.o -c /home/jakub/WAT/Kryptologia/Ciphers/main.cpp

CMakeFiles/Cryptology.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cryptology.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/WAT/Kryptologia/Ciphers/main.cpp > CMakeFiles/Cryptology.dir/main.cpp.i

CMakeFiles/Cryptology.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cryptology.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/WAT/Kryptologia/Ciphers/main.cpp -o CMakeFiles/Cryptology.dir/main.cpp.s

# Object files for target Cryptology
Cryptology_OBJECTS = \
"CMakeFiles/Cryptology.dir/main.cpp.o"

# External object files for target Cryptology
Cryptology_EXTERNAL_OBJECTS =

Cryptology: CMakeFiles/Cryptology.dir/main.cpp.o
Cryptology: CMakeFiles/Cryptology.dir/build.make
Cryptology: CMakeFiles/Cryptology.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cryptology"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cryptology.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cryptology.dir/build: Cryptology

.PHONY : CMakeFiles/Cryptology.dir/build

CMakeFiles/Cryptology.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cryptology.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cryptology.dir/clean

CMakeFiles/Cryptology.dir/depend:
	cd /home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/WAT/Kryptologia/Ciphers /home/jakub/WAT/Kryptologia/Ciphers /home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug /home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug /home/jakub/WAT/Kryptologia/Ciphers/cmake-build-debug/CMakeFiles/Cryptology.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cryptology.dir/depend

