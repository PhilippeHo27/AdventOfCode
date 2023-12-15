#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle06B
{
	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		auto lines = ReadAllLinesInFile(inputFile);

		std::string lineOneWithoutSpaces;
		std::string lineTwoWithoutSpaces;

		// Remove spaces from line 1
		for (char c : lines[0])
		{
			if (!std::isspace(c))
			{
				lineOneWithoutSpaces += c;
			}
		}
		// Remove spaces from line 2
		for (char c : lines[1])
		{
			if (!std::isspace(c))
			{
				lineTwoWithoutSpaces += c;
			}
		}

		std::istringstream issLineOne(lineOneWithoutSpaces);
		std::istringstream issLineTwo(lineTwoWithoutSpaces);
		std::vector<std::pair<std::pair<long long unsigned int, long long unsigned int>, long long unsigned int>> timesAndDistances;

		// Temporary values to store them into container
		long long unsigned int time, distance = 0;
		while (issLineOne >> time && issLineTwo >> distance)
		{
			timesAndDistances.emplace_back(std::make_pair(std::make_pair(time, distance), 0));
		}

		for (auto& element : timesAndDistances)
		{
			long long unsigned int counter = 0;
			for (size_t i = 0; i < element.first.first; i++)
			{
				long long unsigned int distance = (element.first.first - (long long unsigned int)i) * (long long unsigned int)i;
				if (distance > element.first.second)
				{
					counter++;
				}
			}
			element.second = counter;
		}

		long long unsigned int total = 1;
		for (auto& element : timesAndDistances)
		{
			total *= element.second;
		}
		std::cout << total << std::endl;

	}
} // namespace Puzzle06B