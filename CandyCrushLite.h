#pragma once

#include <iostream>
#include <vector>
#include <string>

void PrintVectorContents(std::vector<int>& vector);					// The function will print all the elements found in a vector, separated by a space.
bool DoesUserRetry();												/* This function will ask the user whether or not they want to retry with 
                                                                       a new sequence or not. Calls itself recursively if the input is wrong.*/
std::vector<int> TakeUserGlobeSequence();							/* Function will create a vector based on the user's input. Input checks are in place
																	   to ensure that the user inputs only numbers between 0 and 9.*/
int ReturnFirstIndexOfLongestSubSequence(std::vector<int> vector);	/* Function will create a vector of the same lenght as the input vector provided as 
																	   argument and each element will represent how many times the element from the 
																	   corresponding index in the argument vector repeats in a sequence, 
																	   starting from it's position until the sequence is broken. 
																	   It then, finds the largest number in our newly created vector
																	   and then returns its index, which will represent our starting index to delete in the argument vector */
void RemoveSubSequenceFromVector(std::vector<int>& vector);			/* This function will remove the elements starting from the index indicated by 
																	   the function "ReturnFirstIndexOfLongestSubSequence" until the last element
																	   of that subsequence. Will also print the before deletion and after deletion vector for comparison. */