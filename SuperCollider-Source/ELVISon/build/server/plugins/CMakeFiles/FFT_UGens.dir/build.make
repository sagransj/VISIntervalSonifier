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
include server/plugins/CMakeFiles/FFT_UGens.dir/depend.make

# Include the progress variables for this target.
include server/plugins/CMakeFiles/FFT_UGens.dir/progress.make

# Include the compile flags for this target's objects.
include server/plugins/CMakeFiles/FFT_UGens.dir/flags.make

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o: server/plugins/CMakeFiles/FFT_UGens.dir/flags.make
server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o: ../server/plugins/FFTInterfaceTable.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mikewinters/Desktop/ELVISon/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o -c /Users/mikewinters/Desktop/ELVISon/server/plugins/FFTInterfaceTable.cpp

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.i"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mikewinters/Desktop/ELVISon/server/plugins/FFTInterfaceTable.cpp > CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.i

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.s"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mikewinters/Desktop/ELVISon/server/plugins/FFTInterfaceTable.cpp -o CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.s

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.requires:
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.requires

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.provides: server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.requires
	$(MAKE) -f server/plugins/CMakeFiles/FFT_UGens.dir/build.make server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.provides.build
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.provides

server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.provides.build: server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o: server/plugins/CMakeFiles/FFT_UGens.dir/flags.make
server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o: ../server/plugins/FFT_UGens.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mikewinters/Desktop/ELVISon/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o -c /Users/mikewinters/Desktop/ELVISon/server/plugins/FFT_UGens.cpp

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.i"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mikewinters/Desktop/ELVISon/server/plugins/FFT_UGens.cpp > CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.i

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.s"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mikewinters/Desktop/ELVISon/server/plugins/FFT_UGens.cpp -o CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.s

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.requires:
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.requires

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.provides: server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.requires
	$(MAKE) -f server/plugins/CMakeFiles/FFT_UGens.dir/build.make server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.provides.build
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.provides

server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.provides.build: server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o: server/plugins/CMakeFiles/FFT_UGens.dir/flags.make
server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o: ../server/plugins/PV_UGens.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mikewinters/Desktop/ELVISon/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o -c /Users/mikewinters/Desktop/ELVISon/server/plugins/PV_UGens.cpp

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.i"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mikewinters/Desktop/ELVISon/server/plugins/PV_UGens.cpp > CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.i

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.s"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mikewinters/Desktop/ELVISon/server/plugins/PV_UGens.cpp -o CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.s

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.requires:
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.requires

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.provides: server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.requires
	$(MAKE) -f server/plugins/CMakeFiles/FFT_UGens.dir/build.make server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.provides.build
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.provides

server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.provides.build: server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o: server/plugins/CMakeFiles/FFT_UGens.dir/flags.make
server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o: ../server/plugins/PartitionedConvolution.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mikewinters/Desktop/ELVISon/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o -c /Users/mikewinters/Desktop/ELVISon/server/plugins/PartitionedConvolution.cpp

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.i"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mikewinters/Desktop/ELVISon/server/plugins/PartitionedConvolution.cpp > CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.i

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.s"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mikewinters/Desktop/ELVISon/server/plugins/PartitionedConvolution.cpp -o CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.s

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.requires:
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.requires

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.provides: server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.requires
	$(MAKE) -f server/plugins/CMakeFiles/FFT_UGens.dir/build.make server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.provides.build
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.provides

server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.provides.build: server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o

# Object files for target FFT_UGens
FFT_UGens_OBJECTS = \
"CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o" \
"CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o" \
"CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o" \
"CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o"

# External object files for target FFT_UGens
FFT_UGens_EXTERNAL_OBJECTS =

server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o
server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o
server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o
server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o
server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/build.make
server/plugins/FFT_UGens.scx: /usr/lib/libm.dylib
server/plugins/FFT_UGens.scx: server/plugins/CMakeFiles/FFT_UGens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module FFT_UGens.scx"
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FFT_UGens.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/plugins/CMakeFiles/FFT_UGens.dir/build: server/plugins/FFT_UGens.scx
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/build

server/plugins/CMakeFiles/FFT_UGens.dir/requires: server/plugins/CMakeFiles/FFT_UGens.dir/FFTInterfaceTable.cpp.o.requires
server/plugins/CMakeFiles/FFT_UGens.dir/requires: server/plugins/CMakeFiles/FFT_UGens.dir/FFT_UGens.cpp.o.requires
server/plugins/CMakeFiles/FFT_UGens.dir/requires: server/plugins/CMakeFiles/FFT_UGens.dir/PV_UGens.cpp.o.requires
server/plugins/CMakeFiles/FFT_UGens.dir/requires: server/plugins/CMakeFiles/FFT_UGens.dir/PartitionedConvolution.cpp.o.requires
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/requires

server/plugins/CMakeFiles/FFT_UGens.dir/clean:
	cd /Users/mikewinters/Desktop/ELVISon/build/server/plugins && $(CMAKE_COMMAND) -P CMakeFiles/FFT_UGens.dir/cmake_clean.cmake
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/clean

server/plugins/CMakeFiles/FFT_UGens.dir/depend:
	cd /Users/mikewinters/Desktop/ELVISon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mikewinters/Desktop/ELVISon /Users/mikewinters/Desktop/ELVISon/server/plugins /Users/mikewinters/Desktop/ELVISon/build /Users/mikewinters/Desktop/ELVISon/build/server/plugins /Users/mikewinters/Desktop/ELVISon/build/server/plugins/CMakeFiles/FFT_UGens.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/plugins/CMakeFiles/FFT_UGens.dir/depend

