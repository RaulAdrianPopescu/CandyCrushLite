#include "CandyCrushLite.h"

int main()
{
    do
    {
        system("cls");
        std::vector<int> userInput{TakeUserGlobeSequence()};
        RemoveSubSequenceFromVector(userInput);
        
        if (userInput.empty())
            std::cout << "\nALL THE GLOBES HAVE BEEN DESTROYED!";
        else
        {
            std::cout << "Final Sequence: ";
            PrintVectorContents(userInput);
        }
    } while (DoesUserRetry());
}