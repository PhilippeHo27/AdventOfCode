#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle13A
{

	Grid2d<char> CreateGridFromLines(const std::vector<std::string>& lines)
	{
		int width = static_cast<int>(lines[0].size());
		int height = static_cast<int>(lines.size());
		Grid2d<char> grid(width, height);

		for (int y = 0; y < height; ++y)
		{
			const auto& line = lines[y];
			for (int x = 0; x < width; ++x)
			{
				grid.at(x, y) = line[x];
			}
		}

		return grid;
	}

	std::vector<Grid2d<char>> ReadMultipleGrids(const std::filesystem::path& path)
	{
		std::vector<std::string> allLines = ReadAllLinesInFile(path);
		std::vector<Grid2d<char>> grids;
		std::vector<std::string> currentGridLines;

		for (const auto& line : allLines)
		{
			if (!line.empty())
			{
				currentGridLines.push_back(line);
			}
			else
			{
				if (!currentGridLines.empty())
				{
					grids.push_back(CreateGridFromLines(currentGridLines));
					currentGridLines.clear();
				}
			}
		}

		// Handle the last grid
		if (!currentGridLines.empty())
		{
			grids.push_back(CreateGridFromLines(currentGridLines));
		}

		return grids;
	}

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{

		auto input = ReadMultipleGrids(inputFile);



		// sanitycheck
		//for (auto things : input)
		//{
		//	std::cout  << things << std::endl << std::endl;
		//}
	}
} // namespace Puzzle13A