#include "CandyCrushLite.h"

int main()
{
    do
    {
        system("cls");
        std::vector<int> userInput{TakeUserGlobeSequence()};
        RemoveSubSequenceFromVector(userInput);
        
        if (userInput.empty())
            std::cout << "\nALL GLOBES HAVE BEEN DESTROYED!\n";
        else
        {
            std::cout << "Final Sequence: ";
            for (int i = 0; i < userInput.size(); i++)
                std::cout << userInput.at(i) << ' ';
        }
    } while (DoesUserRetry());
}