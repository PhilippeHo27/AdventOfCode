#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Day1.h"

using namespace std;

vector<string> Day1::ExtractWordsFromFile(const string& filename) {
    vector<string> lines;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

int Day1::SizeOfChar(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void Day1::SolutionDayOne()
{
    vector<string> listOfWords = ExtractWordsFromFile("LutinDeMarde.txt");
    int Total = 0;

    for (string word : listOfWords)
    {
        const char* symbols = word.c_str();
        vector<int> storingNumbers;

        for (int i = 0; i < SizeOfChar(symbols); i++)
        {
            if (int(symbols[i]) >= 48 && int(symbols[i]) <= 57)
            {
                storingNumbers.push_back(symbols[i]);
            }
        }

        char numberCreated[] = { storingNumbers[0] ,storingNumbers[storingNumbers.size() - 1] , '\0' };
        int number = stoi(numberCreated);
        Total += number;
    }
    cout << " The total is:  " << Total << endl;
}
