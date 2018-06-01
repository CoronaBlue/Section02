// Preprocessor section
#include <iostream>
#include <string>

using namespace std;

// Function prototypes.
void PrintIntro();
void PlayGame();
string GetGuess();
bool PlayAgain();

// Entry point.
int main()
{
	do
	{
		PrintIntro();
		PlayGame();

	} while (PlayAgain());

	return 0;
}

void PrintIntro()
{
	//Print the intro for the game.
	constexpr int WORD_LENGTH = 5; // Keeping track of the secret word length.
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I'm thinking of?\n";
	cout << endl;

	return;
}

void PlayGame()
{
	// Set up variables and constants.
	constexpr int NUMBER_OF_TURNS = 5;
	string Guess = "";

	// For number of turns...
	for (int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		// Get the player's guess.
		Guess = GetGuess();

		// Repeat the guess back to the player.
		cout << "Your guess was " << Guess << endl;
		cout << endl;
	}
}

string GetGuess()
{
	// Prompt for a guess using console input.
	string Guess = ""; // Used to store the player's guess.
	cout << "Please enter your guess: ";
	getline(cin, Guess);

	return Guess;
}

bool PlayAgain()
{
	string Result = "";

	cout << "Do you want to play again (y/n)? ";
	getline(cin, Result);
	cout << endl;

	return (tolower(Result[0]) == 'y');
}