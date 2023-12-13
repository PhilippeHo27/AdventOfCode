#include "pch.h"

#include "../Utilities/Utilities.h"
#include "PuzzleSolvers.h"

using namespace Utilities;
using namespace std;

namespace Puzzle07A
{
	enum Combos
	{
		Topcard,
		Pair,
		TwoPairs,
		Trips,
		FullHouse,
		Quads,
		Quints,
		Max
	};

	struct Hands
	{
		string cards;
		int bets = 0;
		Combos combo;
	};

	int ModifyAsciiValue(int value)
	{
		switch (value)
		{
			case 65: // 'A'
				return value * 100000;
			case 75: // 'K'
				return value * 10000;
			case 81: // 'Q'
				return value * 1000;
			case 74: // 'J'
				return value * 100;
			default:
				return value;
		}
	}

	bool CompareHands(const Hands& a, const Hands& b)
	{
		size_t minLength = std::min(a.cards.length(), b.cards.length());

		for (size_t i = 0; i < minLength; ++i)
		{
			int modifiedValueA = ModifyAsciiValue(static_cast<int>(a.cards[i]));
			int modifiedValueB = ModifyAsciiValue(static_cast<int>(b.cards[i]));

			if (modifiedValueA != modifiedValueB)
			{
				return modifiedValueA < modifiedValueB;
			}
		}
		return a.cards.length() > b.cards.length();
	}

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		vector<string> lines = ReadAllLinesInFile(inputFile);
		vector<Hands> unrankedListOfHands;

		// stored the hands into a list of structs
		for (const std::string& line : lines)
		{
			istringstream iss(line);
			Hands hand;
			iss >> hand.cards >> hand.bets;
			unrankedListOfHands.push_back(hand);
		}

		//storing combos into containers

		vector<Hands> quints;
		vector<Hands> quads;
		vector<Hands> fullHouse;
		vector<Hands> trips;
		vector<Hands> twoPairs;
		vector<Hands> pair;
		vector<Hands> topCard;

		// sort the combos
		for (auto hand : unrankedListOfHands)
		{
			unordered_map<char, int> charCount;
			for (char c : hand.cards)
			{
				charCount[c]++;
			}

			// Quint
			if (charCount.size() == 1)
			{
				hand.combo = Quints;
				quints.push_back(hand);
				continue;
			}

			if (charCount.size() == 2)
			{
				// Quad
				auto itFirst = charCount.begin();
				auto itLast = std::prev(charCount.end());

				if ((itFirst->second == 4 && std::next(itFirst)->second == 1) || (itFirst->second == 1 && itLast->second == 4))
				{
					hand.combo = Quads;
					quads.push_back(hand);
					continue;
				}
				// Full House
				else
				{
					hand.combo = FullHouse;
					fullHouse.push_back(hand);
					continue;
				}
			}

			if (charCount.size() == 3)
			{
				int pairs = 0;
				for (auto lol : charCount)
				{
					// Trips
					if (lol.second == 3)
					{
						hand.combo = Trips;
						trips.push_back(hand);
						continue;
					}
					// Find two pairs
					if (lol.second == 2)
					{
						pairs++;
					}
				}
				if (pairs == 2)
				{
					hand.combo = TwoPairs;
					twoPairs.push_back(hand);
				}
				continue;
			}

			// Pair
			if (charCount.size() == 4)
			{
				hand.combo = Pair;
				pair.push_back(hand);
				continue;
			}

			hand.combo = Topcard;
			topCard.push_back(hand);
		}

		if (!quints.empty()) std::sort(quints.begin(), quints.end(), CompareHands);
		if (!quads.empty()) std::sort(quads.begin(), quads.end(), CompareHands);
		if (!fullHouse.empty()) std::sort(fullHouse.begin(), fullHouse.end(), CompareHands);
		if (!trips.empty()) std::sort(trips.begin(), trips.end(), CompareHands);
		if (!twoPairs.empty()) std::sort(twoPairs.begin(), twoPairs.end(), CompareHands);
		if (!pair.empty()) std::sort(pair.begin(), pair.end(), CompareHands);
		if (!topCard.empty()) std::sort(topCard.begin(), topCard.end(), CompareHands);


		// make a giant vector
		vector<vector<Hands>> vectors = { topCard, pair, twoPairs, trips, fullHouse,  quads, quints };
		vector<Hands> merged = std::accumulate(
			vectors.begin(),
			vectors.end(),
			vector<Hands>(),
			[](vector<Hands> acc, const vector<Hands>& vec) -> vector<Hands>
			{
				acc.insert(acc.end(), vec.begin(), vec.end());
				return acc;
			});

		//calculate the total
		int total = 0;
		for (size_t i = 0; i < merged.size(); i++)
		{
			total += merged[i].bets * int(i+1);
		}
		cout << total;

		// sanity check
		//cout << "size of merged thing is : " << merged.size();;

		// sanity check
		//for (auto all : merged)
		//{
		//	cout << all.cards << endl;
		//}

		// sanity checks
		//for (auto all : quints)
		//{
		//	cout << all.cards << " 5" << endl;
		//}
		//for (auto all : quads)
		//{
		//	cout << all.cards << " 4" << endl;
		//}
		//for (auto all : fullHouse)
		//{
		//	cout << all.cards << " 3/2" << endl;
		//}
		//for (auto all : trips)
		//{
		//	cout << all.cards << " 3" << endl;
		//}
		//for (auto all : twoPairs)
		//{
		//	cout << all.cards << " 2/2" << endl;
		//}
		//for (auto all : pair)
		//{
		//	cout << all.cards << " 2" << endl;
		//}
		//for (auto all : topCard)
		//{
		//	cout << all.cards << " 1" << endl;
		//}
	}

} // namespace Puzzle07A
