#include "file_manager.h"



int main() {

    FileManager manager;

    int choice;

    do {
        cout << "\n----------- FILE MANAGER -----------\n";
        cout << "1. Show drives\n";
        cout << "2. Show directory\n";
        cout << "3. Create folder\n";
        cout << "4. Create file\n";
        cout << "5. Delete file/folder\n";
        cout << "6. Rename\n";
        cout << "7. Copy\n";
        cout << "8. Move\n";
        cout << "9. Get size\n";
        cout << "10. Search\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;
        cin.ignore();

        string path;
        string to;
        string mask;

        switch (choice) {

        case 1:
            manager.showDrives();
            break;

        case 2:
            cout << "Enter path: ";
            getline(cin, path);
            manager.showDirectory(path);
            break;

        case 3:
            cout << "Enter folder path: ";
            getline(cin, path);
            manager.createFolder(path);
            break;

        case 4:
            cout << "Enter file path: ";
            getline(cin, path);
            manager.createFile(path);
            break;

        case 5:
            cout << "Enter path: ";
            getline(cin, path);
            manager.remove(path);
            break;

        case 6:
            cout << "Enter old path: ";
            getline(cin, path);
            cout << "Enter new path: ";
            getline(cin, to);
            manager.rename(path, to);
            break;

        case 7:
            cout << "Enter source: ";
            getline(cin, path);
            cout << "Enter to: ";
            getline(cin, to);
            manager.copy(path, to);
            break;

        case 8:
            cout << "Enter source: ";
            getline(cin, path);
            cout << "Enter new location: ";
            getline(cin, to);
            manager.move(path, to);
            break;

        case 9:
        {
            cout << "Enter path: ";
            getline(cin, path);
            uintmax_t size = manager.getSize(path);
            cout << "Size: " << size << " bytes\n";
            break;
        }


        case 10:
            cout << "Enter directory: ";
            getline(cin, path);
            cout << "Enter mask. Examples: \n*: everything\n*.txt: all .txt files\nExact name\nEnter: ";
            getline(cin, mask);
            cout << "\nSearch results:\n";
            manager.search(path, mask);
            break;

        case 0:
            cout << "Finito\n";
            break;

        default:
            cout << "Invalid\n";
        }

    } while (choice != 0);





    return 0;


}
