#include<iostream>
#include<cstdlib>

int main()
{
    int num,guess;
    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;
    
    while(1)
    {
        num=rand()%100+1;
        std::cout<<"Enter your guess:";
        std::cin>>guess;
        if (num==guess)
        {
            std::cout<<"Congratulations, Your guess is right!";
            break;
        }
        else if(num<guess)
        {
            std::cout<<"Your guess is too high, Try again!";
        }
        else
        {
            std::cout<<"Your guess is too low, Try again!";
        }
    }
    
    return 0;
}

