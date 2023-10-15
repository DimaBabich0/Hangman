#pragma once
const int ALPHABET_SIZE = 26;
const int LIFES = 6;
class Statictics
{
private:
	char alphabet[ALPHABET_SIZE];
	bool usedLetters[ALPHABET_SIZE];
	int attempts;
public:
	Statictics()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			alphabet[i] = 'A' + i;
			usedLetters[i] = false;
		}
		attempts = LIFES;
	}

	void Reset()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			usedLetters[i] = false;
		}
		attempts = LIFES;
	}
	bool CheckUsedLetter(char userLetter)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (alphabet[i] == userLetter)
			{
				if (usedLetters[i] == false)
					return false;
				else
					return true;
			}
		}
		return false;
	}

	void AddUsedLetter(char userLetter)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (alphabet[i] == userLetter)
			{
				usedLetters[i] = true;
				break;
			}
		}
	}

	void PrintAlphabet()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (i % 10 == 0 && i != 0)
				cout << endl;
			if (usedLetters[i] == true)
				cout << "_ ";
			else
				cout << alphabet[i] << " ";
		}
	}
	int GetAttempts()
	{
		return attempts;
	}
	void MinusAttempts()
	{
		attempts--;
	}
};