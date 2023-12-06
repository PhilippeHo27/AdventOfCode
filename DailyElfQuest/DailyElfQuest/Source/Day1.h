#pragma once
 #include <string>
#include <vector>

using namespace std;

class Day1
{
public:
	Day1();
	void SolutionDayOne();

	vector<string> ExtractWordsFromFile(const string& filename);
	int SizeOfChar(const char* str);

	vector<string> listOfWords;
	vector<int> storingNumbers;
};
