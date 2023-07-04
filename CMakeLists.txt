cmake_minimum_required(VERSION 3.25)

project(n4basic VERSION 0.1.0)


# Find package X
find_package(Nain4 REQUIRED)

message("module ${CMAKE_MODULE_PATH}")
# Create your executable
add_executable(exe main.cxx)

# Link against package X
target_link_libraries(exe
                      PRIVATE
                      Nain4
                      ${Geant4_LIBRARIES})
