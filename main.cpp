//GuessMyNumber2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int process_hint(int, int, int, int);

int main(void)
{
	int compInt, userGuess, lowNum, highNum, distance, guessMax, guessCount, range;
	srand(time(0));
	char playAgain;

	do
	{
		cout << "In this game the computer will generate a random number between two numbers of \nyour choice.\n" << endl;
		cout << "Start by choosing a low number here: ";
		cin >> lowNum;
		cout << "Now choose any number higher than " << lowNum << ": ";
		cin >> highNum;
		guessCount = 0;

		if (highNum - lowNum <= 25)
			guessMax = 5;

		else if (highNum - lowNum <= 50)
			guessMax = 10;

		else if (highNum - lowNum <= 100)
			guessMax = 15;

		else
			guessMax = 20;

		cout << "\nYou will get " << guessMax << " guesses at what the number is, and get hints along the way, then the game is over." << endl;
		cout << "\nAlright the computer generated a number between " << lowNum << " and " << highNum << "." << endl;

		compInt = rand() % (highNum - lowNum) + (lowNum); //enumerates random integer

		for (guessMax>0; guessMax--;){
			if (guessCount==0){
				cout<<"Enter your first guess: ";
				cin >> userGuess;
			}
			guessCount++;
			if (userGuess==compInt){
				cout << "\nGood job you guessed what the number was in " << guessCount << " tries!" << endl;
				cout << "You had " << guessMax << " guesses left!" << endl;
				break;
			}
			if (guessMax!=0){
				if(userGuess>compInt){
					cout << '\n' << userGuess << " is too high, ";
					distance = userGuess - compInt;
					process_hint(distance, userGuess, highNum, lowNum);
				}
				if (userGuess<compInt){
					cout << '\n' << userGuess << " is too low, ";
					distance = compInt - userGuess;
					process_hint(distance, userGuess, highNum, lowNum);
				}
			}
			if (guessMax==0){
				cout << "Out of guesses! ";
				cout << "The number was " << compInt << ".";
				cout << "\nGame Over!" << endl;
				break;
			}
			cout << "\nYou have " << guessMax << " guesses left, enter your guess: ";
			cin >> userGuess;
		}

		cout << "\nPlay Again? (y/n): ";
		cin >> playAgain;
		system("cls");

	} while (playAgain == 'y');
	return userGuess, highNum, lowNum;
}

int process_hint(int distance, int userGuess, int highNum, int lowNum)
{
	if (userGuess<lowNum || userGuess>highNum)
		cout << userGuess << " is outside of the range of the generated number.";

	else if (distance < 5)
		cout << "but you were within 5, try again.";

	else if (distance < 10)
		cout << "but you were within 10, try again.";

	else if (distance < 25)
		cout << "but you were within 25, try again.";

	else if (distance < 50)
		cout << "but you were within 50, try again.";

	else if (distance > 100)
		cout << "but you were within 100 or more, try again.";

	return distance;
}
