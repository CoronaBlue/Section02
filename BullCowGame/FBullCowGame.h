// Preprocessor section.
#pragma once
#include <string>

// Unreal substitutions.
using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	// Constructor.
	FBullCowGame();

	// Constant methods.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	// Other public functions.
	void Reset(); // TODO Make a more rich return value.
	bool CheckGuessValidity(FString); // TODO Make a more rich return value.
	// Provide a method for counting Bulls and Cows, and increasing turn number.

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};