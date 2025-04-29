//
// Created by robb on 8/24/23.
//

#include "Imp.h"

double Imp::CreateDataStore(const char *path, const char *fileName)
{
    std::string strPath = path;
    std::string strFileName = fileName;
    std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
    _fileName = fileName;
    double result = CreateDS(fqn.c_str());
    return result;
}
double Imp::LoadDataStore(const char *path, const char *fileName)
{
    std::string strPath = path;
    std::string strFileName = fileName;
    std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
    double result = LoadDS(fqn.c_str());
    return result;
}
double Imp::SaveDataStore(const char *path, const char *fileName)
{
    std::string strPath = path;
    std::string strFileName = fileName;
    std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
    double result = SaveDS(fqn.c_str());
    return result;
}

bool Imp::CreateDS(const char *fileName)
{
    std::string fn = fileName;
    _dataStore.SetFileName(fn);
    _dataStore.Clear();
    _dataStore.Save();
    return _ibIO.FileExist(fileName);
}

int Imp::LoadDS(const char *fileName)
{
    if (!_ibIO.FileExist(fileName))
        return false;

    std::string fn = fileName;
    _dataStore.Load(fn);

    return true;
}
int Imp::SaveDS(const char *fileName)
{
    std::string fn = fileName;
    _dataStore.Save(fn);
    return true;
}
bool Imp::Save()
{
    std::cout << "saving to '" + _fileName + "'" << std::endl;
    std::cout << "contains " << _dataStore.Count() << " entries" << std::endl;
    _dataStore.Save(_fileName.c_str());
    return true;
}
int Imp::Contains(const char *key)
{
    bool result = _dataStore.Contains(key);
    return result;
}
void Imp::Add(const char *key, const char *value)
{
    std::string data = key;
    std::string node = value;
    _dataStore.Add(data, node);
}
void Imp::Update(const char *key, const char *value)
{
    std::string data = key;
    std::string node = value;
    _dataStore.Update(data, node);
}
const char *Imp::Get(const char *key)
{
    std::string data = key;
    std::string node = _dataStore.Get(data);
    return node.c_str();
}
std::string Imp::GetValue(std::string key)
{
    std::string node = _dataStore.Get(key);
    return node;
}
void Imp::Remove(const char *key)
{
    if (!Contains(key))
        return;
    std::string data = key;
    _dataStore.Remove(data);
}
void Imp::LoadIDS(std::string fn)
{
    if(_ibIO.FileExist(fn.c_str()))
    {
        _dataStore.Load(fn);
    }
    else
    {
        std::cout << "unable to find '" << fn << "'" << std::endl;
    }
}

// Added on some fileName stuff
void Imp::SetFileName(std::string fileName)
{
    std::cout << "File Name: '" << fileName << "'" << std::endl;
    _fileName = fileName;
}
void Imp::SetFileName(const char *fileName)
{
    std::string str(fileName);
    SetFileName(str);
}
const char *Imp::GetFileName()
{
    return _fileName.c_str();
}
// *********** App stuff **********
bool Imp::Contains(std::string key)
{
    bool result = Contains(key.c_str());
    return result;
}
void Imp::Add(std::string key, std::string svalue)
{
    Add(key.c_str(), svalue.c_str());
}
void Imp::Update(std::string key, std::string svalue)
{
    Update(key.c_str(), svalue.c_str());
}
std::string Imp::Get(std::string key)
{
    std::string result = Get(key.c_str());
    return result;
}
void Imp::Remove(std::string key)
{
    Remove(key.c_str());
}
std::vector<std::string> Imp::ListData(std::string fileName, KVData kvd)
{
    std::vector<std::string> buffer;
    std::vector<std::string> data = _dataStore.ListDS(fileName);

    for (size_t i = 0; i < data.size(); i++)
    {
        std::string line = data[i];
        DataNode dn = _ibHelp.StringToDataNode(line);
        if (kvd == Key)
            buffer.push_back(dn._Key);
        else if (kvd == Value)
            buffer.push_back(dn._Value);
        else
            buffer.push_back(line);
    }
    return buffer;
}
