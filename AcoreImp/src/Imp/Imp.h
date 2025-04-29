//
// Created by robb on 8/24/23.
//

#ifndef IMP_IMP_H
#define IMP_IMP_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "Global.h"

#include "Enums.h"
#include "Structs.h"
#include "ImpIO.h"
#include "ImpMisc.h"
#include "ImpConfigData.h"

class Imp {
    public:
        ImpConfigData _dataStore;
        ImpIO _ibIO;
        ImpMisc _ibHelp;

        ImpConfigData _runningConfig;

        std::string _fileName;

        // These are the ones that should be used during game development
        double CreateDataStore(const char *path, const char *fileName);
        double LoadDataStore(const char *path, const char *fileName);
        double SaveDataStore(const char *path, const char *fileName);

        // For use in apps
        bool Save();

        // Not really needed. Use the ones with paths
        // instead. Keeping around in case.
        bool CreateDS(const char *fileName);
        int  LoadDS(const char *fileName);
        int  SaveDS(const char *fileName);

        // For game engine interface
        int  Contains(const char *key);
        void Add(const char *key, const char *value);
        void Update(const char *key, const char *value);
        const char *Get(const char *key);
        std::string GetValue(std::string key);
        void Remove(const char *key);

        std::vector<std::string> ListData(std::string fileName, KVData kvd);

        // For app interface
        bool Contains(std::string key);
        void Add(std::string key, std::string svalue);
        void Update(std::string key, std::string svalue);
        std::string Get(std::string key);
        void Remove(std::string key);

        void LoadIDS(std::string sfile);

        // Utility type stuff
        void SetFileName(std::string fileName);
        void SetFileName(const char *fileName);
        const char *GetFileName();
};


#endif //IMP_IMP_H
