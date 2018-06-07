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


void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = 8;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
