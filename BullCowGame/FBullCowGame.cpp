// Preprocessor section.
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

// Unreal substitutions.
using FString = std::string;
using int32 = int;

// Constructor implementation.
FBullCowGame::FBullCowGame()
{
	Reset();
}

// Getter methods.
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const
{
	// Alter the difficulty of the game, based on the length of the hidden word.
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };

	return WordLengthToMaxTries[GetHiddenWordLength()];
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	/*if (!IsIsogram(Guess)) // If the guess isn't an isogram.
	{
		return EGuessStatus::Not_Isogram;
	}
	else*/ if (!IsLowercase(Guess)) // If the guess isn't lowercase.
	{
		return EGuessStatus::Not_Lowercase;
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	FBullCowCount BullCowCount;

	MyCurrentTry++;

	// Loop through all letters in the guess, assuming equal word length.
	for (int32 i = 0; i < GetHiddenWordLength(); i++)
	{
		// Compare letters against the hidden word.
		for (int32 j = 0; j < GetHiddenWordLength(); j++)
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

	// Check for a win.
	if (BullCowCount.Bulls == GetHiddenWordLength())
	{
		bGameWon = true;
	}
	else
	{
		bGameWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Set up the map.
	TMap<char, bool> LetterSeen;

	// Treat empty strings, and 1 letter words as isograms.
	if (Guess.length() <= 1) { return true; }

	for (auto Letter : Guess) // For all letters in Guess...
	{
		if (LetterSeen[tolower(Letter)]) // If the letter has been seen before...
		{
			return false; // The guess is not an isogram.
		}
		else // Otherwise...
		{
			LetterSeen[tolower(Letter)] = true;
		}	
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess) // For all letters in Guess...
	{
		if (!islower(Letter)) // If the letter is uppercase...
		{
			return false;
		}
	}
	return true;
}
