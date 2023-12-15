#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle06A
{
	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		auto lines = ReadAllLinesInFile(inputFile);
		std::istringstream issLineOne(lines[0]);
		std::istringstream issLineTwo(lines[1]);
		std::vector<std::pair<std::pair<int, int>,int>> timesAndDistances;

		// Temporary values to store them into container
		int time, distance = 0;
		while (issLineOne >> time && issLineTwo >> distance)
		{
			timesAndDistances.emplace_back(std::make_pair(std::make_pair(time, distance), 0));
		}

		for (auto& element : timesAndDistances)
		{
			int counter = 0;
			for (size_t i = 0; i < element.first.first; i++)
			{
				int distance = (element.first.first - (int)i) * (int)i;
				if (distance > element.first.second)
				{
					counter++;
				}
			}
			element.second = counter;
		}

		int total = 1;
		for (auto& element : timesAndDistances)
		{
			total *= element.second;
		}
		std::cout << total << std::endl;
	}
} // namespace Puzzle06A