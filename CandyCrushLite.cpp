#include "CandyCrushLite.h"

bool DoesUserRetry()
{
	char userSelection;
	std::cout << "\n\nWould you like to retry? Y/N\n\nResponse -> "; std::cin >> userSelection;

	switch (std::tolower(userSelection))
	{
	case 'Y':
		return true;
	case 'y':
		return true;
	case 'N':
		return false;
	case 'n':
		return false;
	default:
		return DoesUserRetry();
	}
}

std::vector<int> TakeUserGlobeSequence()
{
	std::cout << "Choose the number of globes the sequence will hold: ";
	int numOfGlobes; std::cin >> numOfGlobes;

	std::vector<int> vectorGlobes;
	for (int i = 0; i < numOfGlobes; i++)
	{
		system("cls");

		std::cout << "Currently in sequence: ";
		for (int k = 0; (!vectorGlobes.empty()) && k < vectorGlobes.size(); k++)
			std::cout << vectorGlobes.at(k) << ' ';

		std::cout << "\nInsert globe (a globe is a number between the 0-9 range, representing it's color): ";
		std::string globe; std::cin >> globe;
		
		bool isGlobeValid = true;
		for (int j = 0; j < globe.length(); j++)
			if (!std::isdigit(globe.at(j)))
			{
				isGlobeValid = false;
				break;
			}

		if (isGlobeValid && (std::stoi(globe) >= 0 && std::stoi(globe) <= 9))
			vectorGlobes.push_back(std::stoi(globe));
		else
			i--;
	}
	system("cls");

	return vectorGlobes;
}

int ReturnFirstIndexOfLongestSubSequence(std::vector<int> vector)
{
	std::vector<int> globeFrequencyVector(vector.size(), 1);

	for (int i = 0; i < vector.size(); i++)
		if (i != (vector.size() - 1))
			if (vector.at(i) == vector.at(i + 1))
				for (int j = i + 1; vector.at(i) == vector.at(j); j++)
					globeFrequencyVector.at(i)++;

	int maxIndex = 0;
	for (int i = 0; i < globeFrequencyVector.size(); i++)
		if (globeFrequencyVector.at(i) > globeFrequencyVector.at(maxIndex))
			maxIndex = i;
	
	if (globeFrequencyVector.at(maxIndex) < 3)
		maxIndex = -1;

	return maxIndex;
}

void RemoveSubSequenceFromVector(std::vector<int>& vector)
{
	int startingIndex = ReturnFirstIndexOfLongestSubSequence(vector);
	int lastIndex = 0;

	while (startingIndex != -1)
	{
		for (int i = startingIndex; vector.at(i) == vector.at(i + 1); i++)
			lastIndex = i + 1;

		vector.erase(vector.begin() + startingIndex, vector.begin() + (++lastIndex));
		startingIndex = ReturnFirstIndexOfLongestSubSequence(vector);

		std::cout << "SEQUENCE AFTER THE ARROW HITS: ";
		for (int i = 0; i < vector.size(); i++)
			std::cout << vector.at(i) << ' ';
		
		std::cout << "\n\nPRESS ANY KEY TO CONTIUNE...";
		system("pause>nul");
		system("cls");
	}
}
