//
// Created by robb on 8/24/23.
//

#include "ImpIO.h"

bool ImpIO::FileExist(const char *fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    return inFile.good();
}
bool ImpIO::Exists(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    return inFile.good();
}
int ImpIO::CountLines(char *filename)
{
    int count = 0;
    std::string buffer;
    std::ifstream fin(filename);
    while (std::getline(fin, buffer))
        ++count;
    fin.close();

    return count;
}

int ImpIO::NextLineNumber(char *filename)
{
    int c = CountLines(filename);
    c++;
    return c;
}

void ImpIO::WriteLine(char *filename, char *str)
{
    std::ofstream fout(filename, std::ios::app);
    fout << str << std::endl;
    fout.close();
}

std::string ImpIO::ReadFile(char *fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    return str;
}

std::string ImpIO::ReadFile(std::string fileName)
{
    ImpMisc ibm;
    char *tstr = ibm.StringToChar(fileName);
    std::string result = ReadFile(tstr);
    return result;
}

double ImpIO::WriteFile(char *filename, char *str)
{
    std::ofstream fout(filename);
    fout.write(str, sizeof(str));
    fout.close();

    return 0;
}

void ImpIO::WriteData(std::vector<std::string> data, std::string fileName)
{
    std::ofstream fout(fileName.c_str(), std::ios::trunc);
    for (size_t i = 0; i < data.size(); i++)
    {
        std::string line = data[i];
        fout << line << std::endl;
    }
    fout.close();
}

std::vector<std::string> ImpIO::ReadData(std::string fileName)
{
    //std::cout << "reading data" << std::endl;
    std::vector<std::string> result;
    //std::cout << "filename : '" << fileName << "'" << std::endl;
    std::ifstream inFile(fileName);
    std::string buffer;

    while (std::getline(inFile, buffer))
    {
        result.push_back(buffer);
    }
    //std::cout << "closing file" << std::endl;
    //std::cout << "results : '" << result << "'" << std::endl;
    inFile.close();
    return result;
}

void ImpIO::IndexLine(char *line, char *filename)
{
    std::string buffer;
    std::string newline;
    ImpMisc ibm;
    char *tok;
    int idx = CountLines(filename);
    idx += 1;
    tok = ibm.StringToChar("|");
    ImpMisc im;
    std::string index = im.IntToString(idx);
    newline.append(index);
    newline.append(tok);
    newline.append(line);
    WriteLine(filename, strdup(newline.c_str()));
}

void ImpIO::FileDelete(const char * fileName)
{
    remove(fileName);
}

void ImpIO::MakeFolder(std::string folderName)
{
#if __APPLE__
    mkdir(folderName.c_str(), 0777);
#elif __linux__
    mkdir(folderName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#elif _WIN32
    //CreateDirectory(folderName.c_str(), NULL);
    _mkdir(folderName.c_str());
#endif
}

std::string ImpIO::GetFolderName()
{
    char buf[FILENAME_MAX];
#if __APPLE__
    char* succ = getcwd(buf, FILENAME_MAX);
#endif
    char* succ = getcwd(buf, FILENAME_MAX);

    if( succ )
        return std::string(succ);
    else
        return std::string("error");
}
char* ImpIO::getCurrentDir(void)
{
    char buf[FILENAME_MAX];
    char* succ = getcwd(buf, FILENAME_MAX);
    return succ;
}