# AcoreImp Project

## Overview
AcoreImp is a C++ application that provides various functionalities including authentication, world management, configuration, and database operations. The project is built using CMake, which simplifies the build process and manages dependencies effectively.

## Directory Structure
```
AcoreImp
├── CMakeLists.txt         # CMake configuration file
├── src                    # Source files
│   ├── acoreauth.cpp      # Authentication functionality
│   ├── acoreworld.cpp     # World-related functionality
│   ├── impconfig.cpp      # Configuration functionality
│   ├── impdb.cpp          # Database functionality
│   └── Imp                # Library source files
│       └── [*.cpp]       # Additional implementation files for libimp
├── bin                    # Compiled binaries
└── README.md              # Project documentation
```

## Build Instructions
1. **Install CMake**: Ensure that CMake is installed on your system.
2. **Create a Build Directory**: Navigate to the project root and create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. **Configure the Project**: Run CMake to configure the project:
   ```bash
   cmake ..
   ```
4. **Build the Project**: Compile the project using:
   ```bash
   make
   ```
5. **Install the Binaries**: Optionally, you can install the binaries to the appropriate system directories:
   ```bash
   make install
   ```

## Usage
After building the project, the compiled binaries will be located in the `bin` directory. You can run the application from there.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.