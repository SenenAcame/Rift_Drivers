# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build

# Include any dependencies generated for this target.
include CMakeFiles/libModulos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libModulos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libModulos.dir/flags.make

CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o: CMakeFiles/libModulos.dir/flags.make
CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o: ../ej_modulos/mimodulo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o -c /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo.cpp

CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo.cpp > CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.i

CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo.cpp -o CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.s

CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o: CMakeFiles/libModulos.dir/flags.make
CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o: ../ej_modulos/mimodulo2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o -c /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo2.cpp

CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo2.cpp > CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.i

CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/ej_modulos/mimodulo2.cpp -o CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.s

# Object files for target libModulos
libModulos_OBJECTS = \
"CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o" \
"CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o"

# External object files for target libModulos
libModulos_EXTERNAL_OBJECTS =

liblibModulos.a: CMakeFiles/libModulos.dir/ej_modulos/mimodulo.cpp.o
liblibModulos.a: CMakeFiles/libModulos.dir/ej_modulos/mimodulo2.cpp.o
liblibModulos.a: CMakeFiles/libModulos.dir/build.make
liblibModulos.a: CMakeFiles/libModulos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblibModulos.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libModulos.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libModulos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libModulos.dir/build: liblibModulos.a

.PHONY : CMakeFiles/libModulos.dir/build

CMakeFiles/libModulos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libModulos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libModulos.dir/clean

CMakeFiles/libModulos.dir/depend:
	cd /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build /home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/build/CMakeFiles/libModulos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libModulos.dir/depend

