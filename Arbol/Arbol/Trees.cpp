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
		"5- Is leaf" << "\n" <<
		"6- Is empty" << "\n" <<
		"7- Weight" << "\n" <<
		"8- Count leaf" << "\n" <<
		"9- Clear tree" << "\n" <<
		"10- Delete" << "\n" <<
		"11- Is complete" << "\n" <<
		"12- Height" << "\n" <<
		"13- Iquals tree" << "\n" <<
		"14- Exit." << "\n";
	executeOption();
}

void executeOption()
{
	int option;
	cin >> option;

	switch (option)
	{
	case 1: insert();
		break;
	case 2: printTree();
		break;
	case 3: searchMin();
		break;
	case 4: searchMax();
		break;
	case 5: isLeaf();
		break;
	case 6: isEmpty();
		break;
	case 7: weight();
		break;
	case 8: countLeaf();
		break;
	case 9: clearTree();
		break;
	case 10: deleteNodo();
		break;
	case 11: isComplete();
		break;
	case 12: height();
		break;
	case 13: iqualsTree();
		break;
	case 14: system("pause");
		break;
	default: cout << "Invalid option." << "\n" << "\n";
		break;
	}

	if (option != 14) {
		showMenu();
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
	int order;
	cout << "0 - pre  order\n";
	cout << "1 - in   order\n";
	cout << "2 - post order\n";
	cout << "Type a value: \n\n";
	cin >> order;

	if (order >= 0 && order <= 2)
		tree->printTree(order);
	else
		cout << "Invalid order\n";
}

void searchMin()
{
	cout << "Manimum data: " << tree->searchMin() << "\n" << "\n";
}

void searchMax()
{
	cout << "Maximum data: " << tree->searchMax() << "\n" << "\n";
	
}

void isLeaf() {
	int value, result;
	cout << "Type a value" << "\n";
	cin >> value;

	result = tree->isLeaf(value);

	if (result == 0)
		cout << "The element not exists" << "\n";
	else
		cout << (result == 1 ? "Y" : "N") << "\n";
}

void isEmpty() {
	cout << (tree->isEmpty() ? "Y" : "N") << "\n";
}

void weight() {
	cout << "Wight: " << tree->weight() << "\n";
}

void countLeaf() {
	cout << "Total leaf: " << tree->countLeaf() << "\n";
}

void clearTree() {
	tree->deleteTree();
}

void deleteNodo() {
	int value;
	cout << "Type a value to delete: ";
	cin >> value;

	bool result = tree->deleteElem(value);
	cout << (result ? "Success" : "Error") << "\n\n";
}

void isComplete()
{
	cout << (tree->isComplete() ? "Tree is complete." : "Tree is not complete.") << "\n\n";
}

void height()
{
	cout << "The height is: " << tree->height() << "\n\n";
}

void iqualsTree()
{
	cout << (tree->iquals(tree, tree) ? "Trees are iquals." : "Trees are not iquals.") << "\n\n";
}
