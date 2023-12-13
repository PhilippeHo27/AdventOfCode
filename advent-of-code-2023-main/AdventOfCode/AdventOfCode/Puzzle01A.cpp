#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle01A
{

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		std::vector<std::string> lines = ReadAllLinesInFile(inputFile);
		int total = 0;

		for (const std::string& word : lines)
		{
			const char* symbols = word.c_str();
			std::vector<int> storingNumbers;

			for (int i = 0; symbols[i] != '\0'; ++i)
			{
				if (int(symbols[i]) >= 48 && int(symbols[i]) <= 57)
				{
					storingNumbers.push_back(symbols[i]);
				}
			}

			if (!storingNumbers.empty())
			{
				//char numberCreated[] = { storingNumbers[0], storingNumbers[storingNumbers.size() - 1], '\0' };
				char numberCreated[] = { static_cast<char>(storingNumbers[0]),
					                     static_cast<char>(storingNumbers[storingNumbers.size() - 1]),
					                     '\0' };

				int number = std::stoi(numberCreated);
				total += number;
			}
		}

		std::cout << "The total is: " << total << std::endl;
	}
} // namespace Puzzle01A