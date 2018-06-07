/* This is the console executable that makes use of the FBullCowGame class.
This acts as the view in an MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCowGame class.
*/

// Preprocessor section
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Unreal text substitutions.
using FText = std::string;
using int32 = int;

// Function prototypes.
void PrintIntro();
void PlayGame();
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 5; // Keeping track of the secret word length.
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	// Reset the game.
	BCGame.Reset();

	// Set up variables and constants.
	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	// For number of turns...
	// TODO Change the for loop to a while loop.
	for (int32 count = 0; count < MaxTries; count++)
	{
		// Get the player's guess.
		Guess = GetGuess(); // TODO Check for valid guesses.

		// Submit valid guess to the game.
		// Print the number of Bulls and Cows.

		// Repeat the guess back to the player.
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Summarize the game.
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry(); // Used to store the current try.
	FText Guess = ""; // Used to store the player's guess.

	// Prompt for a guess using console input.
	std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool PlayAgain()
{
	FText Result = "";

	std::cout << "Do you want to play again (y/n)? ";
	std::getline(std::cin, Result);
	std::cout << std::endl;

	return (tolower(Result[0]) == 'y');
}