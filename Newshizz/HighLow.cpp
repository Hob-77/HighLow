#include <iostream>
#include <random>

int main()
{
	std::cout << "this game is called High Low, you guess a number between 10 and I say High or Low, simple enough!" << "\n";

	std::random_device rd; //Randomizes seed at runtime
	std::mt19937 gen(rd()); //Mersenne Twister fast
	std::uniform_int_distribution<>distrib(1, 10); //Puts our number between 1,10

	char AGAIN{ 'y' };

	while (AGAIN == 'y')
	{
		int targetNumber = distrib(gen); //targetNumber is our random number from 1,10
		int x{}; //x is the users guess

		std::cout << "Enter a number 1-10: " << "\n"; //ask user input
		std::cin >> x; //save it as x

		while (x != targetNumber) //apparently != means unless equal to idk
		{
			if (x > targetNumber) //X is larger than our targetNumber
			{
				std::cout << "High" << "\n";
			}
			else if (x < targetNumber) //X is less than our TargetNumber
			{
				std::cout << "Low" << "\n";
			}

			std::cout << "Nah:" << "\n"; //you guessed wrong
			std::cin >> x; //ask user input again
		}

		std::cout << "Correct!" << "\n"; //they are correct

		std::cout << "Want to play again(y/n):" << "\n";
		std::cin >> AGAIN;
	}

	return 0;

}