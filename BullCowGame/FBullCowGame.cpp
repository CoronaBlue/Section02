// Preprocessor section.
#include "FBullCowGame.h"

// Unreal substitutions.
using FString = std::string;
using int32 = int;

// Constructor implementation.
FBullCowGame::FBullCowGame()
{
	Reset();
}

// Getter methods.
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	// To avoid using "magic" numbers.
	// I don't agree with this implementation, but I'm sticking with the tutorial.
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // If the guess isn't an isogram.
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (GetHiddenWordLength() != Guess.length()) // If the guess isn't the correct length.
	{
		return EGuessStatus::Wrong_Length;
	}
	else // Otherwise...
	{
		return EGuessStatus::OK;
	}
}

// Receives a VALID guess, increments the turn count, and returns the Bull/Cow count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the turn count.
	MyCurrentTry++;

	//Set up a return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.
	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		// Compare letters against the hidden word.
		for (int32 j = 0; j < MyHiddenWord.length(); j++)
		{
			// Increment Bulls if they are in the same place.
			if (MyHiddenWord[i] == Guess[j] && i == j)
			{
				BullCowCount.Bulls++;
			}
			else if (MyHiddenWord[i] == Guess[j]) // Increment Cows if not.
			{
				BullCowCount.Cows++;
			}
		}
	}

	return BullCowCount;
}
