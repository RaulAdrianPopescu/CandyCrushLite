#pragma once

#include <iostream>
#include <vector>
#include <string>

void PrintVectorContents(std::vector<int>& vector);
bool DoesUserRetry();
std::vector<int> TakeUserGlobeSequence();
int ReturnFirstIndexOfLongestSubSequence(std::vector<int> vector);
void RemoveSubSequenceFromVector(std::vector<int>& vector);