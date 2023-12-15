#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle15A
{
	auto ReadInput(const std::filesystem::path& inputFile)
	{
		auto input = ReadAllLinesInFile(inputFile);

		return input;
	}

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		auto input = ReadInput(inputFile);
		std::string bigString;
		for (auto s : input)
		{
			bigString = input[0];
		}
		std::istringstream iss(bigString);
		std::vector<std::string> steps;
		std::string smallString;
		while (std::getline(iss, smallString, ','))
		{
			steps.push_back(smallString);
		}

		//for (auto a : steps)
		//{
		//	std::cout << a << std::endl;
		//}

		int valueOfStep = 0;
		for (auto s : steps)
		{
			int value = 0;
			for (char c : s)
			{
				//std::cout << " before algo " << value << std::endl;

				value += (int)c;
				value *= 17;
				value = value%256;
				//std::cout << value << std::endl;
			}
			valueOfStep += value;
		}

		std::cout << valueOfStep << std::endl;
	}
} // namespace Puzzle15A