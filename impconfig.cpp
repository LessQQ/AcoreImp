#include <iostream>

#include "Imp/Imp.h"
#include "Imp/ImpIO.h"

const std::string path("/usr/local/etc/imp");
const std::string fileName("imp.config");

bool CheckConfigFile();
void CreateBase();
void Help();

int main(int argc, char* argv[]) {
    Imp iberia;

    if (CheckConfigFile()) {
        iberia.LoadDataStore(path.c_str(), fileName.c_str());
    }
    else {
        std::cout << path << "/" << fileName << std::endl;
        std::cout << "imp.config not found!" << std::endl;
        CreateBase();
    }

    if (argc < 2) {
        Help();
        exit(1);
    }

    std::string command(argv[1]);

    if (command == "create") {
        CreateBase();
    }
    else if (command == "get") {
        if (iberia.Contains(argv[2])) {
            std::string result(iberia.GetValue(argv[2]));
            std::cout << result << std::endl;
        }
        else {
            std::cout << "not found!" << std::endl;
        }
    }
    else if (command == "set") {
        iberia.Add(argv[2],argv[3]);
        iberia.SaveDataStore(path.c_str(), fileName.c_str());
    }
    else if (command == "remove") {
        iberia.Remove(argv[2]);
    }
    else if (command == "version") {
        std::cout << "impconfig v0.2" << std::endl;
    }
    else {
        std::cout << "unknown parameter!" << std::endl;
        exit(1);
    }
    return 0;
}
bool CheckConfigFile() {
    ImpIO iberiaIo;
    std::string fn = path + "/" + fileName;
    return iberiaIo.FileExist(fn.c_str());
}
void CreateBase() {
    Imp iberia;

    iberia.CreateDataStore(path.c_str(), fileName.c_str());
    iberia.Add("errors", "/home/robb/.imp/error.log");
    iberia.Add("bank","/home/robb/.imp/bank.ids");
    iberia.Add("release", "/home/robb/.imp/release");
    iberia.Add("tmp","/home/robb/.imp/tmp");
    iberia.SaveDataStore(path.c_str(), fileName.c_str());
}
void Help() {
    std::cout << "not enough parameters!" << std::endl;
}