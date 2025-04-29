//
// Created by robb on 8/24/23.
//

#ifndef IMP_IMPIO_H
#define IMP_IMPIO_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <sys/stat.h>
#include <cstring>

#if __APPLE__
#include <stdlib.h>
#include <unistd.h>
#elif __linux__
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#elif _WIN32
#include <Windows.h>
#include <direct.h>
#endif

#include "ImpMisc.h"

class ImpIO {
    public:
        bool FileExist(const char *fileName);
        bool Exists(std::string fileName);
        int CountLines(char *filename);
        int NextLineNumber(char *filename);
        void WriteLine(char *filename, char *str);
        std::string ReadFile(char *fileName);
        std::string ReadFile(std::string fileName);
        double WriteFile(char *filename, char *str);
        void IndexLine(char *line, char *filename);
        void FileDelete(const char *fileName);

        void MakeFolder(std::string folderName);
        char* getCurrentDir(void);
        std::string GetFolderName();

        void WriteData(std::vector<std::string> data, std::string fileName);
        std::vector<std::string> ReadData(std::string fileName);
};


#endif //IMP_IMPIO_H
