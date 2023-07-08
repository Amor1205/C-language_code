#include "huffman.hpp"
#include "compress.hpp"

void menu()
{
    cout << "***************************************" << endl;
    cout << "****** 1. huffman Compress   **********" << endl;
    cout << "****** 2. huffman Decompress **********" << endl;
    cout << "******      0. exit          **********" << endl;
    cout << "***************************************" << endl;
}
int main()
{
    int input = 0;
    bool isQuit = false;
    FileCompress fc;
    string fileName;
    cin >> input;
    while (1)
    {
        menu();
        cin >> input;
        switch (input)
        {
        case 0:
            isQuit = true;
            break;
        case 1:
            cout << "Please enter the name of the zip file:>";
            cin >> fileName;
            fc.file_compression(fileName);
            break;
        case 2:
            cout << "Please enter the name of the file you want to unzip:>";
            cin >> fileName;
            fc.file_decompression(fileName);
            break;
        }
        if (isQuit)
            break;
    }

    // Test();
    // FileCompress f;
    // f.file_compression("txt.txt");
    // f.file_decompression("txt.hz");
    return 0;
}
