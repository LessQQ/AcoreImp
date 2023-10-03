#include <iostream>

#include "Imp/Imp.h"
#include "Imp/ImpIO.h"

const std::string path("/usr/local/etc/imp");
const std::string fileName("imp.config");

bool CheckConfigFile();
void CreateBase();
void Help();

int main(int argc, char* argv[]) {
    Imp imp;

    if (CheckConfigFile()) {
        imp.LoadDataStore(path.c_str(), fileName.c_str());
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
        if (imp.Contains(argv[2])) {
            std::string result(imp.GetValue(argv[2]));
            std::cout << result << std::endl;
        }
        else {
            std::cout << "not found!" << std::endl;
        }
    }
    else if (command == "set") {
        imp.Add(argv[2],argv[3]);
        imp.SaveDataStore(path.c_str(), fileName.c_str());
    }
    else if (command == "remove") {
        imp.Remove(argv[2]);
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
    ImpIO impio;
    std::string fn = path + "/" + fileName;
    return impio.FileExist(fn.c_str());
}
void CreateBase() {
    Imp imp;

    imp.CreateDataStore(path.c_str(), fileName.c_str());
    imp.Add("authpath", "/path/to/authserver");
    imp.Add("authargs","-c /path/to/authserver.conf");
    imp.Add("worldpath", "/path/to/worldserver");
    imp.Add("worldargc","/path/to/worldserver.conf");
    imp.SaveDataStore(path.c_str(), fileName.c_str());
}
void Help() {
    std::cout << "not enough parameters!" << std::endl;
}