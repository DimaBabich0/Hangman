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
	Statictics statictics;
	Time time;

	void RoundGame();
	void PrintHangman();
	void EnterChar();
	void CheckChar();

	bool CheckWin();
	bool CheckLoss();

	void Win();
	void Loss();

	void Uppercase(string& str);
	void Uppercase(char& str);
public:
	Game() : file("sorted_words.txt"), statictics(), time() {}

	void PrintRules();
	void StartGame();
};

void Game::PrintRules()
{
	cout << "\t\t\tRules:" << endl;
	cout << "In this game you need to guess the word entering letters." << endl;
	cout << "If the letter is present in the word, its location is revealed." << endl;
	cout << "If the letter is missing, a piece of the human body appears on the hangman." << endl;
	cout << "If you enter a letter you entered earlier or another symbol, you will not lose your attempt." << endl;
	cout << "You have " << LIFES << " tries before a man forms on the gallows and you lose." << endl;
	cout << "\t\tGood luck and have fun : )" << endl;
}
void Game::StartGame()
{
	try
	{
		guessWord = file.FindWord();
	}
	catch (string message)
	{
		cout << message << endl;
		return;
	}
	
	for (int i = 0; i < guessWord.size() + 1; i++)
	{
		guessedLetters.assign(i, '_');
	}

	time.Record();
	statictics.Reset();

	Uppercase(guessWord);

	RoundGame();
}

void Game::RoundGame()
{
	while (true)
	{
		PrintHangman();
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
		statictics.PrintAlphabet();
		cout << endl;

		EnterChar();
		CheckChar();

		system("cls");
	}
}
void Game::PrintHangman()
{
	int temp = statictics.GetAttempts();
	cout << "|     |     |" << endl;

	if (temp <= 6)
		cout << "|     0     |" << endl;
	else
		cout << "|           |" << endl;

	if (temp == 5)
		cout << "|     |     |" << endl;
	else if (temp == 4)
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
	cout << "|           |" << endl;
	cout << "|           |" << endl;
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
	Uppercase(playerLetter);

	if (playerLetter < 'A' || playerLetter > 'Z')
		return;

	if (statictics.CheckUsedLetter(playerLetter) == false)
		statictics.AddUsedLetter(playerLetter);
	else
		return;

	for (int i = 0; i < guessWord.length(); i++)
	{
		if (playerLetter == guessWord[i])
		{
			guessedLetters[i] = playerLetter;
			isMatch = true;
		}
	}
	if (!isMatch)
		statictics.MinusAttempts();
}

bool Game::CheckWin()
{
	if (strcmp(guessWord.c_str(), guessedLetters.c_str()) == 0)
		return true;
	return false;
}
bool Game::CheckLoss()
{
	if (statictics.GetAttempts() == 0)
		return true;
	return false;
}

void Game::Win()
{
	cout << "\tYou win : )" << endl;
	cout << "The word is " << guessWord << endl;
	cout << "You got the word in ";
	time.CountTime();
	cout << " and " << LIFES - statictics.GetAttempts() << " tries";
}
void Game::Loss()
{
	cout << "\tYou loss : (" << endl;
	cout << "The word is " << guessWord << endl;
}

void Game::Uppercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = str[i] - 'a' + 'A';
}
void Game::Uppercase(char& ch)
{
	if ((ch >= 'a') && (ch <= 'z'))
		ch = ch - 'a' + 'A';
}