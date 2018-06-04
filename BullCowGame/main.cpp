// Preprocessor section
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Function prototypes.
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

// Global variables.
FBullCowGame BCGame;

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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	// Set up variables and constants.
	int MaxTries = BCGame.GetMaxTries();
	std::string Guess = "";

	// For number of turns...
	for (int count = 0; count < MaxTries; count++)
	{
		// Get the player's guess.
		Guess = GetGuess();

		// Repeat the guess back to the player.
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry(); // Used to store the current try.
	std::string Guess = ""; // Used to store the player's guess.

	// Prompt for a guess using console input.
	std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool PlayAgain()
{
	std::string Result = "";

	std::cout << "Do you want to play again (y/n)? ";
	std::getline(std::cin, Result);
	std::cout << std::endl;

	return (tolower(Result[0]) == 'y');
}