# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /Applications/CMake2.8-11.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake2.8-11.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /Applications/CMake2.8-11.app/Contents/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mikewinters/Desktop/ELVISon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mikewinters/Desktop/ELVISon/build

# Include any dependencies generated for this target.
include server/plugins/CMakeFiles/GrainUGens.dir/depend.make

# Include the progress variables for this target.
include server/plugins/CMakeFiles/GrainUGens.dir/progress.make

# Include the compile flags for this target's objects.
include server/plugins/CMakeFiles/GrainUGens.dir/flags.make

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o: server/plugins/CMakeFiles/GrainUGens.dir/flags.make
server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o: ../server/plugins/GrainUGens.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mikewinters/Desktop/ELVISon/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o -c /Users/mikewinters/Desktop/ELVISon/server/plugins/GrainUGens.cpp

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrainUGens.dir/GrainUGens.cpp.i"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mikewinters/Desktop/ELVISon/server/plugins/GrainUGens.cpp > CMakeFiles/GrainUGens.dir/GrainUGens.cpp.i

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrainUGens.dir/GrainUGens.cpp.s"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mikewinters/Desktop/ELVISon/server/plugins/GrainUGens.cpp -o CMakeFiles/GrainUGens.dir/GrainUGens.cpp.s

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.requires:
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.requires

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.provides: server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.requires
	$(MAKE) -f server/plugins/CMakeFiles/GrainUGens.dir/build.make server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.provides.build
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.provides

server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.provides.build: server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o

# Object files for target GrainUGens
GrainUGens_OBJECTS = \
"CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o"

# External object files for target GrainUGens
GrainUGens_EXTERNAL_OBJECTS =

server/plugins/GrainUGens.scx: server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o
server/plugins/GrainUGens.scx: server/plugins/CMakeFiles/GrainUGens.dir/build.make
server/plugins/GrainUGens.scx: server/plugins/CMakeFiles/GrainUGens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module GrainUGens.scx"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GrainUGens.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/plugins/CMakeFiles/GrainUGens.dir/build: server/plugins/GrainUGens.scx
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/build

server/plugins/CMakeFiles/GrainUGens.dir/requires: server/plugins/CMakeFiles/GrainUGens.dir/GrainUGens.cpp.o.requires
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/requires

server/plugins/CMakeFiles/GrainUGens.dir/clean:
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && $(CMAKE_COMMAND) -P CMakeFiles/GrainUGens.dir/cmake_clean.cmake
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/clean

server/plugins/CMakeFiles/GrainUGens.dir/depend:
	cd /Users/mikewinters/Desktop/ELVISon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mikewinters/Desktop/ELVISon /Users/mikewinters/Desktop/ELVISon/server/plugins /Users/mikewinters/Desktop/ELVISon/build /Users/mikewinters/Desktop/ELVISon/build/server/plugins /Users/mikewinters/Desktop/ELVISon/build/server/plugins/CMakeFiles/GrainUGens.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/plugins/CMakeFiles/GrainUGens.dir/depend

