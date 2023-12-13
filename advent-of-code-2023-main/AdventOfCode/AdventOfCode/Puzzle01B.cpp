#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle01B
{
	int ConcatenateTwoDigits(int digit1, int digit2)
	{
		return digit1 * 10 + digit2;
	}

	int SizeOfChar(const char* str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		auto listOfWords = ReadAllLinesInFile(inputFile);
		int total = 0;
		for (std::string word : listOfWords)
		{
			const char* symbols = word.c_str();
			std::vector<char> storingLetters;
			std::vector<int> foundNumbers;

			std::map<int, std::string> indexAndStringMap;

			for (int i = 0; i < SizeOfChar(symbols); i++)
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

			while (foundIndexesForOne != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForOne)] = "one";
				foundIndexesForOne = word.find("one", foundIndexesForOne + 1);
			}

			while (foundIndexesForTwo != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForTwo)] = "two";
				foundIndexesForTwo = word.find("two", foundIndexesForTwo + 1);
			}

			while (foundIndexesForThree != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForThree)] = "three";
				foundIndexesForThree = word.find("three", foundIndexesForThree + 1);
			}

			while (foundIndexesForFour != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForFour)] = "four";
				foundIndexesForFour = word.find("four", foundIndexesForFour + 1);
			}

			while (foundIndexesForFive != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForFive)] = "five";
				foundIndexesForFive = word.find("five", foundIndexesForFive + 1);
			}

			while (foundIndexesForSix != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForSix)] = "six";
				foundIndexesForSix = word.find("six", foundIndexesForSix + 1);
			}

			while (foundIndexesForSeven != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForSeven)] = "seven";
				foundIndexesForSeven = word.find("seven", foundIndexesForSeven + 1);
			}

			while (foundIndexesForEight != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForEight)] = "eight";
				foundIndexesForEight = word.find("eight", foundIndexesForEight + 1);
			}

			while (foundIndexesForNine != std::string::npos)
			{
				indexAndStringMap[int(foundIndexesForNine)] = "nine";
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

			for (size_t i = 0; i < foundNumbers.size(); i++)
			{
				std::cout << foundNumbers[i];
				if (foundNumbers[i] != 0)
				{
					IndexOfLastDigitNumber = int(i);
				}
			}

			for (size_t i = foundNumbers.size() - 1; i > -1; i--)
			{
				if (foundNumbers[i] != 0)
				{
					IndexOfFirstDigitNumber = int(i);
				}
			}
			std::cout << std::endl;
			std::map<std::string, int> stringToNumber = { { "one", 1 }, { "two", 2 },   { "three", 3 }, { "four", 4 }, { "five", 5 },
				                                { "six", 6 }, { "seven", 7 }, { "eight", 8 }, { "nine", 9 } };

			std::cout << " found first digit number is: " << foundNumbers[IndexOfFirstDigitNumber] << std::endl;
			std::cout << " found first written number is: " << stringToNumber[indexAndStringMap[IndexOfFirstWrittenNumber]] << std::endl;
			std::cout << " found last digit number is: " << foundNumbers[IndexOfLastDigitNumber] << std::endl;
			std::cout << " found last written number is: " << stringToNumber[indexAndStringMap[IndexOLastWrittenNumber]] << std::endl;

			// compare indexes and access the container of each container.
			int firstNumber = IndexOfFirstDigitNumber <= IndexOfFirstWrittenNumber
			                    ? foundNumbers[IndexOfFirstDigitNumber]
			                    : stringToNumber[indexAndStringMap[IndexOfFirstWrittenNumber]];
			int lastNumber = IndexOLastWrittenNumber <= IndexOfLastDigitNumber ? foundNumbers[IndexOfLastDigitNumber]
			                                                                   : stringToNumber[indexAndStringMap[IndexOLastWrittenNumber]];

			std::cout << " FIRST NUMBER IS::: " << firstNumber << std::endl;
			std::cout << " LAST NUMBER IS::: " << lastNumber << std::endl;
			std::cout << " combined number is: " << ConcatenateTwoDigits(firstNumber, lastNumber) << std::endl;

			int combinedNumber = ConcatenateTwoDigits(firstNumber, lastNumber);
			total += combinedNumber;
		}
		std::cout << " The total of all combined numbers is:" << total;
	}
} // namespace Puzzle01B