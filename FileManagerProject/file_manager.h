#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = filesystem;

class FileManager {
public:
    void showDrives();
    void showDirectory(string path);
    void createFolder(string path);
    void createFile(string path);
    void remove(string path);
    void rename(string oldPath, string newPath);
    void copy(string source, string to);
    void move(string source, string to);
    uintmax_t getSize(string path);
    void search(string path, string mask);
};
