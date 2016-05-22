// Trees.cpp : Defines the entry point for the console application.
//

#include "Trees.h"

Tree *tree;

int main()
{
	tree = new Tree();
	showMenu();
	return 0;
}

void showMenu()
{
	cout << "--  Welcome to Tree --" << "\n" <<
		"Type the option: " << "\n" <<
		"1- " << "\n" <<
		"2- " << "\n" <<
		"3- " << "\n" <<
		"4- Exit." << "\n";
	executeOption();
}

void executeOption()
{
	int option;
	cin >> option;

	switch (option)
	{
	case 1: 
		break;
	case 2: 
		break;
	case 3: 
		break;
	case 4: system("pause");
		break;
	default: cout << "Invalid option." << "\n" << "\n"; showMenu();
		break;
	}
}
