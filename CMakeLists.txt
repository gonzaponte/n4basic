cmake_minimum_required(VERSION 3.25)

project(n4basic VERSION 0.1.0)

add_executable(exe main.cxx)


###########################
# Set Nain4 as a dependency
###########################

set(N4_PREFIX ${CMAKE_BINARY_DIR}/external/Nain4)
set(N4_SRC_PREFIX ${N4_PREFIX}/src/Nain4External)
set(N4_INSTALL ${N4_SRC_PREFIX}/install)
set(N4_SRC ${N4_SRC_PREFIX}/nain4)

include(ExternalProject)

ExternalProject_Add(
    Nain4External
    PREFIX ${N4_PREFIX}
    GIT_REPOSITORY https://github.com/gonzaponte/nain4.git
    GIT_TAG origin/cmake_export
    GIT_PROGRESS true
#    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${N4_INSTALL_PREFIX}
    SOURCE_SUBDIR nain4
#    INSTALL_COMMAND ""
)

add_dependencies(exe Nain4External)

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})


target_include_directories(exe PRIVATE ${N4_INSTALL}/include)
target_link_directories(exe PRIVATE ${N4_INSTALL}/lib)
target_link_libraries(exe PRIVATE Nain4 ${Geant4_LIBRARIES})
