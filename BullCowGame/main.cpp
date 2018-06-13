/* This is the console executable that makes use of the FBullCowGame class.
This acts as the view in an MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCowGame class.
*/

// Preprocessor section
#include <iostream>
#include <algorithm>
#include <string>
#include "FBullCowGame.h"

// Unreal text substitutions.
using FText = std::string;
using int32 = int;

// Function prototypes.
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |----- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram that I'm thinking of?\n";
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
	FBullCowCount BullCowCount;

	// Ask for guesses while the game is not won, and there are still tries remaining...
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		// Get the player's guess.
		Guess = GetValidGuess();

		// Submit valid guess to the game, and receive counts.
		BullCowCount = BCGame.SubmitValidGuess(Guess);

		// Print the number of Bulls and Cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		// Repeat the guess back to the player.
		std::cout << std::endl;
	}

	// Summarize the game.
	PrintGameSummary();

	return;
}

FText GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry(); // Used to store the current try.
	FText Guess = ""; // Used to store the player's guess.
	EGuessStatus Status = EGuessStatus::Invalid_Status; // Validity status of the guess.

	do
	{
		// Prompt for a guess using console input.
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Please enter your guess: ";
		std::getline(std::cin, Guess);

		// Check guess validity.
		Status = BCGame.CheckGuessValidity(Guess);

		// Give feedback.
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "The guess must be all lowercase letters.\n\n";
			break;
		default:
			// Assume that the guess is valid.
			break;
		}

	} while (Status != EGuessStatus::OK);

	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations! You win!\n";
	}
	else
	{
		std::cout << "Sorry, you lose. Better luck next time.\n";
	}

	std::cout << std::endl;

	return;
}

bool PlayAgain()
{
	FText Result = "";

	std::cout << "Do you want to play again using the same word (y/n)? ";
	std::getline(std::cin, Result);
	std::cout << std::endl;

	return (tolower(Result[0]) == 'y');
}