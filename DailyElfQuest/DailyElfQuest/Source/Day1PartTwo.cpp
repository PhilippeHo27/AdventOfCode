#include "Day1.h"
#include "Day1PartTwo.h"
#include "iostream"
#include "algorithm"
#include <map>

using namespace std;

void Day1PartTwo::SolutionDayTwo()
{
	int total = 0;
	for (string word : Day1.listOfWords)
	{
		const char* symbols = word.c_str();
		vector<char> storingLetters;
		vector<int> foundNumbers;

		map<int, string> indexAndStringMap;

		for (int i = 0; i < Day1.SizeOfChar(symbols); i++)
		{
			if (int(symbols[i]) >= 48 && int(symbols[i]) <= 57)
			{
				char character = static_cast<char>(symbols[i]);
				foundNumbers.push_back(character - '0');
			}
			else
			{
				foundNumbers.push_back(false);
			}
		}

		size_t foundIndexesForOne = word.find("one");
		size_t foundIndexesForTwo = word.find("two");
		size_t foundIndexesForThree = word.find("three");
		size_t foundIndexesForFour = word.find("four");
		size_t foundIndexesForFive = word.find("five");
		size_t foundIndexesForSix = word.find("six");
		size_t foundIndexesForSeven = word.find("seven");
		size_t foundIndexesForEight = word.find("eight");
		size_t foundIndexesForNine = word.find("nine");

		while (foundIndexesForOne != string::npos)
		{
			indexAndStringMap[foundIndexesForOne] = "one";
			foundIndexesForOne = word.find("one", foundIndexesForOne + 1);
		}

		while (foundIndexesForTwo != string::npos)
		{
			indexAndStringMap[foundIndexesForTwo] = "two";
			foundIndexesForTwo = word.find("two", foundIndexesForTwo + 1);
		}

		while (foundIndexesForThree != string::npos)
		{
			indexAndStringMap[foundIndexesForThree] = "three";
			foundIndexesForThree = word.find("three", foundIndexesForThree + 1);
		}

		while (foundIndexesForFour != string::npos)
		{
			indexAndStringMap[foundIndexesForFour] = "four";
			foundIndexesForFour = word.find("four", foundIndexesForFour + 1);
		}

		while (foundIndexesForFive != string::npos)
		{
			indexAndStringMap[foundIndexesForFive] = "five";
			foundIndexesForFive = word.find("five", foundIndexesForFive + 1);
		}

		while (foundIndexesForSix != string::npos)
		{
			indexAndStringMap[foundIndexesForSix] = "six";
			foundIndexesForSix = word.find("six", foundIndexesForSix + 1);
		}

		while (foundIndexesForSeven != string::npos)
		{
			indexAndStringMap[foundIndexesForSeven] = "seven";
			foundIndexesForSeven = word.find("seven", foundIndexesForSeven + 1);
		}

		while (foundIndexesForEight != string::npos)
		{
			indexAndStringMap[foundIndexesForEight] = "eight";
			foundIndexesForEight = word.find("eight", foundIndexesForEight + 1);
		}

		while (foundIndexesForNine != string::npos)
		{
			indexAndStringMap[foundIndexesForNine] = "nine";
			foundIndexesForNine = word.find("nine", foundIndexesForNine + 1);
		}

		// This section finds the written numbers
		int IndexOfFirstWrittenNumber = 999999;
		int IndexOLastWrittenNumber = 0;

		auto it = indexAndStringMap.begin();
		if (it != indexAndStringMap.end())
		{
			IndexOfFirstWrittenNumber = it->first;
		}

		if (!indexAndStringMap.empty())
		{
			auto lastElementMap = *indexAndStringMap.rbegin();
			IndexOLastWrittenNumber = lastElementMap.first;
		}

		// This section finds the digit numbers
		int IndexOfFirstDigitNumber = 0;
		int IndexOfLastDigitNumber = 0;

		for (int i = 0; i < foundNumbers.size(); i++)
		{
			cout << foundNumbers[i];
			if (foundNumbers[i] != 0)
			{
				IndexOfLastDigitNumber = i;
			}
		}

		for (int i = foundNumbers.size()-1; i > -1; i--)
		{
			if (foundNumbers[i] != 0)
			{
				IndexOfFirstDigitNumber = i;
			}
		}
		cout << endl;
		map<string, int> stringToNumber = { {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9} };

		cout << " found first digit number is: " << foundNumbers[IndexOfFirstDigitNumber] << endl;
		cout << " found first written number is: " << stringToNumber[indexAndStringMap[IndexOfFirstWrittenNumber]] << endl;
		cout << " found last digit number is: " << foundNumbers[IndexOfLastDigitNumber] << endl;
		cout << " found last written number is: " << stringToNumber[indexAndStringMap[IndexOLastWrittenNumber]] << endl;

		// compare indexes and access the container of each container.
		int firstNumber = IndexOfFirstDigitNumber <= IndexOfFirstWrittenNumber ? foundNumbers[IndexOfFirstDigitNumber] : stringToNumber[indexAndStringMap[IndexOfFirstWrittenNumber]];
		int lastNumber = IndexOLastWrittenNumber <= IndexOfLastDigitNumber ? foundNumbers[IndexOfLastDigitNumber] : stringToNumber[indexAndStringMap[IndexOLastWrittenNumber]];

		cout << " FIRST NUMBER IS::: " << firstNumber << endl;
		cout << " LAST NUMBER IS::: " << lastNumber << endl;
		cout << " combined number is: " << ConcatenateTwoDigits(firstNumber, lastNumber ) << endl;

		int combinedNumber = ConcatenateTwoDigits(firstNumber, lastNumber);
		total += combinedNumber;
	}
	cout << " The total of all combined numbers is:" << total;
}

int Day1PartTwo::ConcatenateTwoDigits(int digit1, int digit2)
{
	return digit1 * 10 + digit2;
}
