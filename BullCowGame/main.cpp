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

	// For number of turns...
	// TODO Change the for loop to a while loop.
	for (int32 count = 0; count < MaxTries; count++)
	{
		// Get the player's guess.
		Guess = GetValidGuess();

		// Submit valid guess to the game, and receive counts.
		BullCowCount = BCGame.SubmitValidGuess(Guess);

		// Print the number of Bulls and Cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		// Repeat the guess back to the player.
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Summarize the game.
}

FText GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry(); // Used to store the current try.
	FText Guess = ""; // Used to store the player's guess.
	EGuessStatus Status = EGuessStatus::Invalid_Status; // Validity status of the guess.

	do
	{
		// Prompt for a guess using console input.
		std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
		std::getline(std::cin, Guess);

		// Check guess validity.
		Status = BCGame.CheckGuessValidity(Guess);

		// Give feedback.
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "The guess must be all lowercase.\n";
			break;
		default:
			// Assume that the guess is valid.
			break;
		}

		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);

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