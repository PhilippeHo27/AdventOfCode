#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle15B
{
	auto ReadInput(const std::filesystem::path& inputFile)
	{
		auto input = ReadAllLinesInFile(inputFile);

		return input;
	}

	struct Box
	{
		std::string stepsName;
		int focalLength;
	};

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

		std::vector<std::vector<Box>> boxes(256);

		// fill the array of boxes!
		for (auto s : steps)
		{
			// find the step's codename
			std::string stepsName;
			std::size_t firstSymbolIndex = s.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
			if (firstSymbolIndex != std::string::npos)
			{
				stepsName = s.substr(0, firstSymbolIndex);
			}

			int boxNumber = 0;
			for (char c : stepsName)
			{
				//finds the box #
				boxNumber += (int)c;
				boxNumber *= 17;
				boxNumber = boxNumber % 256;
			}

			// find instructions, = or - ?
			auto foundEqual = s.find('=');
			auto foundSubstract = s.find('-');

			if (foundEqual != std::string::npos) // if =
			{
				// find the lense
				auto lensNumber = s[s.size() - 1] - '0';

				auto& box = boxes[boxNumber];
				auto it = std::find_if(box.begin(), box.end(), [&stepsName](const Box& lens) { return lens.stepsName == stepsName; });
				if (it != box.end())
				{
					// Lens with stepsName found, update focal length
					it->focalLength = lensNumber;
				}
				else
				{
					// Lens not found, add new lens
					box.push_back({ stepsName, lensNumber });
				}
			}
			else if (foundSubstract != std::string::npos) // if -
			{
				// Remove lens with the label stepsName from the box
				auto& lensesInBox = boxes[boxNumber];
				lensesInBox.erase(
					std::remove_if(
						lensesInBox.begin(), lensesInBox.end(), [&stepsName](const Box& lens) { return lens.stepsName == stepsName; }),
					lensesInBox.end());
			}
		}

		int totalSum = 0;

		for (size_t i = 0; i < boxes.size(); i++)
		{
			for (size_t j = 0; j < boxes[i].size(); j++)
			{
				//std::cout << boxes[i][j].focalLength << "<--- focal lenght" << std::endl;
				//std::cout << ((int)i + 1) * ((int)j + 1) << "<-------    i + 1 * j + 1.." << std::endl;
				//std::cout << i  << " <---- what is i?" << std::endl;
				//std::cout << j  << " <---- what is j?" << std::endl;

				totalSum += ((int)i + 1) * ((int)j + 1) * boxes[i][j].focalLength;
			}
		}
		std::cout << totalSum;
	}
} // namespace Puzzle15B