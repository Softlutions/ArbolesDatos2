#pragma once
#include "Nodo.h"

class Tree
{
private:
	Nodo *root;

	Nodo *&getRoot();
	void setRoot(Nodo *);
	void preOrder(Nodo *);
	void inOrder(Nodo *);
	void postOrder(Nodo *);
	void insertElem(int, Nodo *&);
	int SearchMax(Nodo *);
	int SearchMin(Nodo *);
	void DeleteNodo(Nodo *);
	void DeleteNodo(Nodo *, int);
	Nodo *SearchElem(Nodo *, int);
	int IsLeaf(Nodo *, int);
	void DeleteTree(Nodo *);
	int weight(Nodo *);
	int countLeaf(Nodo *);
	int isComplete(Nodo *);
	int Height(Nodo *);
	int max(int, int);
	bool Iquals(Nodo *&, Nodo *&);

public:
	Tree();
	~Tree();

	void insertElem(int);
	bool deleteElem(int);
	int weight();
	int isLeaf(int);
	int countLeaf();
	bool isEmpty();
	void printTree(int);
	int searchMax();
	int searchMin();
	Nodo *searchElem(int);
	void deleteTree();
	bool isComplete();
	int height();
	bool iquals(Tree *, Tree *);
};

