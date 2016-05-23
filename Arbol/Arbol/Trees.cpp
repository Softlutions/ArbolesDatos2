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
		"1- Insert" << "\n" <<
		"2- Print tree" << "\n" <<
		"3- Search min" << "\n" <<
		"4- Search max" << "\n" <<
		"5- Exit." << "\n";
	executeOption();
}

void executeOption()
{
	int option;
	cin >> option;

	switch (option)
	{
	case 1: insert(); showMenu();
		break;
	case 2: printTree(); showMenu();
		break;
	case 3: searchMin(); showMenu();
		break;
	case 4: searchMax(); showMenu();
		break;
	case 5: system("pause");
		break;
	default: cout << "Invalid option." << "\n" << "\n"; showMenu();
		break;
	}
}

void insert()
{
	int data;

	cout << "Type data: " << "\n" << "\n";
	cin >> data;

	tree->insertElem(data);
}

void printTree()
{
	tree->printTree();
}

void searchMin()
{
	cout << "Manimum data: " << tree->searchMin() << "\n" << "\n";
}

void searchMax()
{
	cout << "Maximum data: " << tree->searchMax() << "\n" << "\n";
	
}
