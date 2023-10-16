#pragma once
const int ALPHABET_SIZE = 26;
const int LIFES = 7;
class Statictics
{
private:
	char alphabet[ALPHABET_SIZE];
	bool usedLetters[ALPHABET_SIZE];
	int attempts;
public:
	Statictics();
	void Reset();

	void PrintAlphabet() const;
	bool CheckUsedLetter(char userLetter);
	void AddUsedLetter(char userLetter);

	void MinusAttempts();
	int GetAttempts() const;
};

Statictics::Statictics()
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		alphabet[i] = 'A' + i;
	}
}
void Statictics::Reset()
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		usedLetters[i] = false;
	}
	attempts = LIFES;
}

void Statictics::PrintAlphabet() const
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
bool Statictics::CheckUsedLetter(char userLetter)
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
void Statictics::AddUsedLetter(char userLetter)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (alphabet[i] == userLetter)
		{
			usedLetters[i] = true;
			return;
		}
	}
}

void Statictics::MinusAttempts()
{
	attempts--;
}
int Statictics::GetAttempts() const
{
	return attempts;
}