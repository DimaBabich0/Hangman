#pragma once
#include "FileWords.h"
#include "Time.h"
#include "Statictics.h"

class Game
{
private:
	FileWords file;
	string guessWord;
	string guessedLetters;
	char playerLetter;
	Statictics stats;
	Time startGame;
public:
	Game() : file("sorted_words.txt"), stats(), startGame() {}

	void PrintRules();
	void StartGame();
	void RoundGame();

	void PrintStatus();
	void EnterChar();
	void CheckChar();
	void uppercase(string& str);
	void uppercase(char& str);

	void Loss();
	void Win();

	bool CheckWin();
	bool CheckLoss();
};

void Game::PrintStatus()
{
	int temp = stats.GetAttempts();
	cout << "|     |     |" << endl;
	cout << "|     |     |" << endl;

	if (temp <= 5)
		cout << "|     0     |" << endl;
	else
		cout << "|           |" << endl;

	if (temp == 4)
		cout << "|    /|     |" << endl;
	else if (temp <= 3)
		cout << "|    /|\\    |" << endl;
	else
		cout << "|           |" << endl;

	if (temp <= 2)
		cout << "|     |     |" << endl;
	else
		cout << "|           |" << endl;

	if (temp == 1)
		cout << "|    /      |" << endl;
	else if (temp <= 0)
		cout << "|    / \\    |" << endl;
	else
		cout << "|           |" << endl;
}

void Game::PrintRules()
{
	cout << "\tRules:" << endl;

}

void Game::StartGame()
{
	guessWord = file.FindWord();
	for (int i = 0; i < guessWord.size() + 1; i++)
	{
		guessedLetters.assign(i, '_');
	}
	startGame.Record();
	stats.Reset();

	uppercase(guessWord);

	RoundGame();
}
void Game::RoundGame()
{
	while (true)
	{
		PrintStatus();
		cout << endl;

		if (CheckLoss() == true)
		{
			Loss();
			break;
		}
		else if (CheckWin() == true)
		{
			Win();
			break;
		}
		cout << "Guessed letters: " << guessedLetters << endl;
		stats.PrintAlphabet();
		cout << endl;

		EnterChar();
		CheckChar();

		system("cls");
	}
}
void Game::EnterChar()
{
	cout << "Enter letter: ";
	cin >> playerLetter;
	cin.ignore(255, '\n');
}
void Game::CheckChar()
{
	bool isMatch = false;
	uppercase(playerLetter);
	
	if (stats.CheckUsedLetter(playerLetter) == false)
		stats.AddUsedLetter(playerLetter);
	else
	{
		cout << "You used that letter";
		return;
	}

	for (int i = 0; i < guessWord.length(); i++)
	{
		if (playerLetter == guessWord[i])
		{
			guessedLetters[i] = playerLetter;
			isMatch = true;
		}
	}
	if (!isMatch)
		stats.MinusAttempts();
}

void Game::uppercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}
void Game::uppercase(char& ch)
{
	ch = toupper(ch);
}

void Game::Loss()
{
	cout << "\tYou loss" << endl;
	cout << "The word is " << guessWord << endl;
}

void Game::Win()
{
	cout << "\tYou win" << endl;
	cout << "The word is " << guessWord << endl;
	cout << "You got the word in ";
	startGame.CountTime();
	cout << " and " << LIFES - stats.GetAttempts() << " tries";
}

bool Game::CheckWin()
{
	if (strcmp(guessWord.c_str(), guessedLetters.c_str()) == 0)
		return true;
	return false;
}
bool Game::CheckLoss()
{
	if (stats.GetAttempts() == 0)
		return true;
	return false;
}