#include "Game.h"
#include <iostream>
using namespace std;

enum actionsCodeMain
{
	codeStartGame = 1, codePrintRules, codeExitProgram
};
void PrintMenu()
{
	cout << "\tMenu" << endl;
	cout << "[" << codeStartGame << "] - Start game" << endl;
	cout << "[" << codePrintRules << "] - Print rules" << endl;
	cout << "[" << codeExitProgram << "] - Exit the program" << endl;
}

int main()
{
	Game point;
	int userChoice;
	bool isExit = false;

	while (!isExit)
	{
		PrintMenu();
		cout << "\nChoose option: ";
		cin >> userChoice;
		system("cls");

		switch (userChoice)
		{
		case codeStartGame:
			point.StartGame();
			break;
		case codePrintRules:
			point.PrintRules();
			break;
		case codeExitProgram:
			cout << "Thanks for using our program!" << endl;
			isExit = true;
			break;
		default:
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			cout << "You entered the wrong action code. Try again" << endl;
		}

		if (!isExit)
		{
			system("pause");
			system("cls");
		}
	}
}