#include "file_manager.h"



void FileManager::showDrives() {
    cout << "\nDrives:\n";
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        string drive;
        drive += letter;
        drive += ":\\";
        if (fs::exists(drive)) {
            cout << drive << endl;
        }
    }
}
void FileManager::showDirectory(string path) {
    if (!fs::exists(path)) {
        cout << "Invalid path\n";
        return;
    }
    cout << "\nContents of " << path << ":\n";
    for (const auto& curr : fs::directory_iterator(path)) {
        if (curr.is_directory()) {
            cout << "[dir]  "
                << curr.path().filename().string()
                << endl;
        }
        else {
            cout << "[file] "
                << curr.path().filename().string()
                << endl;
        }
    }
}
void FileManager::createFolder(string path) {
    try {
        if (fs::create_directory(path)) {
            cout << "Folder created.\n";
        }
        else {
            cout << "Foldr could not be created\n";
        }
    }
    catch (fs::filesystem_error e) {
        cout << e.what() << endl;
    }

}
void FileManager::createFile(string path) {
    ofstream file(path);
    if (file) {
        cout << "File created\n";
    }
    else {
        cout << "Could not create a file\n";
    }
    file.close();
}
void FileManager::remove(string path) {
    if (!fs::exists(path)) {
        cout << "Invalid path\n";
        return;
    }
    uintmax_t FilesDeleted{
        fs::remove_all(path)
    };
    cout << "Deleted" << FilesDeleted << " files or folders";
}
void FileManager::rename(string oldName, string newName) {
    if (!fs::exists(oldName)) {
        cout << "Invalid path\n";
        return;
    }
    fs::rename(oldName, newName);
    cout << "Renamed\n";
}
void FileManager::copy(string source, string to) {
    if (!fs::exists(source)) {
        cout << "Source does not exist\n";
        return;
    }
    if (fs::is_directory(source)) {
        fs::copy(source, to, fs::copy_options::recursive);
    }
    else {
        fs::copy_file(source, to, fs::copy_options::overwrite_existing);
    }
    cout << "Copied\n";
}
void FileManager::move(string source, string to) {
    if (!fs::exists(source)) {
        cout << "Source does not exist\n";
        return;
    }
    fs::rename(source, to);
    cout << "Moved\n";
}
uintmax_t FileManager::getSize(string path) {
    if (!fs::exists(path)) {
        return 0;
    }
    if (fs::is_regular_file(path)) {
        return fs::file_size(path);
    }
    uintmax_t size = 0;
    for (const auto& curr : fs::recursive_directory_iterator(path)) {
        if (fs::is_regular_file(curr)) {
            size += fs::file_size(curr);
        }
    }
    return size;
}
void FileManager::search(string path, string mask) {
    if (!fs::exists(path)) {
        cout << "Ivalid path\n";
        return;
    }
    for (const auto& curr : fs::recursive_directory_iterator(path)) {
        string name = curr.path().filename().string();
        if (mask == "*") {
            cout << curr.path() << endl;
        }
        else if (mask[0] == '*') {
            string ending = mask.substr(1);
            if (name.size() >= ending.size() && name.substr(name.size() - ending.size()) == ending) {
                cout << curr.path() << endl;
            }
        }
        else {
            if (name == mask) {
                cout << curr.path() << endl;
            }
        }
    }
}
