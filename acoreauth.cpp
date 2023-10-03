#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <vector>

/**
 * Starts a Linux program in the background.
 *
 * @param program The name or path of the program to start.
 * @param args An array of strings representing the command-line arguments for the program.
 * @throws std::invalid_argument if the program or any of the arguments are empty.
 * @throws std::runtime_error if the program fails to start.
 */
void startProgramInBackground(const std::string& program, const std::vector<std::string>& args) {
    // Check if the program name is empty
    if (program.empty()) {
        throw std::invalid_argument("Program name cannot be empty.");
    }

    // Check if any of the arguments are empty
    for (const std::string& arg : args) {
        if (arg.empty()) {
            throw std::invalid_argument("Arguments cannot be empty.");
        }
    }

    // Convert the program name and arguments to C-style strings
    char* programName = const_cast<char*>(program.c_str());
    std::vector<char*> argList;
    for (const std::string& arg : args) {
        argList.push_back(const_cast<char*>(arg.c_str()));
    }
    argList.push_back(nullptr);

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Forking failed
        throw std::runtime_error("Failed to start the program.");
    } else if (pid == 0) {
        // Child process
        // Start the program in the background
        int result = execvp(programName, argList.data());

        if (result == -1) {
            // execvp failed
            std::cerr << "Failed to start the program." << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        // Do nothing and return
    }
}

int main() {
    try {
        // Example usage: Start the "ls" command in the background
        std::string program = "/home/robb/AzerothCore/azeroth-server/bin/authserver";
        std::vector<std::string> args = {"-c /home/robb/AzerothCore/azeroth-server/etc/authserver.conf"};

        startProgramInBackground(program, args);

        std::cout << "Program started in the background." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}