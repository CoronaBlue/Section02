// Preprocessor section.
#pragma once
#include <string>

// Unreal substitutions.
using FString = std::string;
using int32 = int;

// Structures
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Enumerations
enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Invalid_Status
};

class FBullCowGame
{
public:
	// Constructor.
	FBullCowGame();

	// Constant methods.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString Guess) const; // TODO Make a more rich return value.

	// Other public functions.
	void Reset(); // TODO Make a more rich return value.
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};