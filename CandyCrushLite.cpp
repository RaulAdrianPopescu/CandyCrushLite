#include "CandyCrushLite.h"

void PrintVectorContents(std::vector<int>& vector)
{
	if (vector.empty())
		return;

	for (int i = 0; i < vector.size(); i++)
		std::cout << vector.at(i) << ' ';
}

bool DoesUserRetry()
{
	std::string input;
	std::cout << "\n\nWould you like to retry? Y/N\n\nResponse -> "; std::cin >> input;

	if (input.size() > 1)
	{
		system("cls");
		return DoesUserRetry();
	}

	char userSelection = input[0];
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
		system("cls");
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
		PrintVectorContents(vectorGlobes);

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
	if (vector.empty())
		return -1;

	std::vector<int> globeFrequencyVector(vector.size(), 0);

	for (int i = 0; i < vector.size(); i++)
		for (int j = i; j < vector.size(); j++)
		{
			if (vector.at(i) == vector.at(j))
				globeFrequencyVector.at(i)++;
			else
				break;
		}

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

	while (startingIndex != -1)
	{
		int lastIndex = 0;

		for (int i = startingIndex; i < vector.size(); i++)
		{
			if (i == vector.size() - 1)
				lastIndex = i;
			else if (vector.at(i) != vector.at(i + 1))
			{
				lastIndex = i;
				break;
			}
		}

		std::cout << "SEQUENCE BEFORE THE ARROW HIT: ";
		PrintVectorContents(vector);

		if (lastIndex == vector.size() - 1)
			vector.erase(vector.begin() + startingIndex, vector.end());
		else
			vector.erase(vector.begin() + startingIndex, vector.begin() + (++lastIndex));

		if (vector.empty())
			return;

		std::cout << "\nSEQUENCE AFTER THE ARROW HIT:  ";
		PrintVectorContents(vector);
		
		std::cout << "\n\nPRESS ANY KEY TO CONTIUNE...";
		system("pause>nul");
		system("cls");

		startingIndex = ReturnFirstIndexOfLongestSubSequence(vector);
	}
}