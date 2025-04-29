cmake_minimum_required(VERSION 3.10)

project(AcoreImp)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files
set(SOURCES
    src/acoreauth.cpp
    src/acoreworld.cpp
    src/impconfig.cpp
    src/impdb.cpp
    src/Imp/*.cpp
)

# Create the shared library
add_library(libimp SHARED ${SOURCES})

# Create the executable targets
add_executable(impauth src/acoreauth.cpp)
add_executable(impworld src/acoreworld.cpp)
add_executable(impconfig src/impconfig.cpp)
add_executable(impdb src/impdb.cpp)

# Link the shared library to the executables
target_link_libraries(impauth libimp)
target_link_libraries(impworld libimp)
target_link_libraries(impconfig libimp)
target_link_libraries(impdb libimp)

# Specify the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)