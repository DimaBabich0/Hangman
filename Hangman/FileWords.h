#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class FileWords
{
private:
	string path;
public:
	FileWords(const char* userPath);
    string FindWord();
};

FileWords::FileWords(const char* userPath)
{
    path = userPath;
}

string FileWords::FindWord()
{
    srand((unsigned)time(NULL));
    ifstream in;
    in.open(path, ios::in);
    if (in)
    {
        int countWords;
        in >> countWords;

        int randomWord = (2 + rand() % (countWords - 2));
        int index = 0;

        const int SIZE = 30;
        char buffer[SIZE] = {};
        while (in.getline(buffer, SIZE))
        {
            index++;
            if (index == randomWord)
                break;
        }
        in.close();

        return string(buffer);
    }
    else
        cout << "Could not open the file" << endl;
    return "empty";
}