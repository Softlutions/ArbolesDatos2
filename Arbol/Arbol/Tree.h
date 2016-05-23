#pragma once
#include "Nodo.h"

class Tree
{
private:
	Nodo *root;

	Nodo *getRoot();
	void setRoot(Nodo *);
	void inOrder(Nodo *);
	void insertElem(int, Nodo *);
	int SearchMax(Nodo *);
	int SearchMin(Nodo *);
	void DeleteNodo(Nodo *);
	int DeleteMin(Nodo *);
	Nodo * SearchElem(Nodo *, int);
	bool IsLeaf(Nodo *, int);
	void DeleteTree(Nodo *);
	int CountLeaf(Nodo *, int);
public:
	Tree();
	~Tree();

	void insertElem(int);
	bool deleteElem(int);
	int weight();
	bool isLeaf();
	int countLeaf();
	bool isEmpty();
	void printTree();
	int searchMax();
	int searchMin();
	bool deleteNodo(int);
	Nodo * searchElem(int);
	bool isLeaf(int);
	void deleteTree();
};

