#include "Tree.h"

Tree::Tree()
{
	setRoot(nullptr);
}

Tree::~Tree()
{
}

Nodo *&Tree::getRoot()
{
	return root;
}

void Tree::setRoot(Nodo *_root)
{
	root = _root;
}

void Tree::insertElem(int data, Nodo *&a)
{
	if (a == nullptr) {
		a = new Nodo(data);
	}
	else {
		if (data < a->getData()) {
			return insertElem(data, a->getIzq());
		}
		else {
			return insertElem(data, a->getDer());
		}
	}
}

void Tree::insertElem(int data)
{
	if (isEmpty()) {
		setRoot(new Nodo(data));
	} else {
		insertElem(data, getRoot());
	}	
}

bool Tree::deleteElem(int data)
{
	Nodo *aux = searchElem(data);
	if (aux != nullptr) {
		DeleteNodo(aux);
		return true;
	}
	return false;
}

int Tree::weight(Nodo *_a) {
	if(_a != NULL)
		return 1 + weight(_a->getIzq()) + weight(_a->getDer());
	
	return 0;
}

int Tree::weight()
{
	return weight(getRoot());
}

int Tree::countLeaf(Nodo *_a) {
	if (_a != nullptr) {
		if (_a->getIzq() == nullptr && _a->getDer() == nullptr)
			return 1;
		else
			return countLeaf(_a->getIzq()) + countLeaf(_a->getDer());
	}

	return 0;
}

int Tree::countLeaf()
{
	return countLeaf(getRoot());
}

bool Tree::isEmpty()
{
	return getRoot() == nullptr;
}

void Tree::preOrder(Nodo *_a)
{
	if (_a != nullptr) {
		cout << _a->getData() << "\n";
		preOrder(_a->getIzq());
		preOrder(_a->getDer());
	}
}

void Tree::inOrder(Nodo *_a)
{
	if (_a != nullptr) {
		inOrder(_a->getIzq());
		cout << _a->getData() << "\n";
		inOrder(_a->getDer());
	}
}

void Tree::postOrder(Nodo *_a)
{
	if (_a != nullptr) {
		postOrder(_a->getIzq());
		postOrder(_a->getDer());
		cout << _a->getData() << "\n";
	}
}

/*
0: pre order
1: in order
2: post order
*/
void Tree::printTree(int order)
{
	if (order == 0)
		preOrder(getRoot());
	else if (order == 1)
		inOrder(getRoot());
	else
		postOrder(getRoot());
}

int Tree::searchMax()
{
	return SearchMax(this->getRoot());
}

int Tree::SearchMax(Nodo *a)
{
	if (a->getDer() == nullptr) {
		return a->getData();
	}
	else {
		return SearchMax(a->getDer());
	}
}

int Tree::searchMin()
{
	return SearchMin(this->getRoot());
}

int Tree::SearchMin(Nodo *a)
{
	if (a->getIzq() == nullptr) {
		return a->getData();
	} else {
		return SearchMin(a->getIzq());
	}
}

void Tree::DeleteNodo(Nodo *a, int x)
{
	if (a != NULL) {
		if (a->getData() == x) {
			delete a;
		}
		else {
			if (a->getData() > x) {
				DeleteNodo(a->getIzq(), x);
				
				if (a->getIzq()->getData() == x) {
					a->setIzq(NULL);
				}
			}
			else {
				DeleteNodo(a->getDer(), x);

				if (a->getDer()->getData() == x) {
					a->setDer(NULL);
				}
			}
		}
	}
}

void Tree::DeleteNodo(Nodo *a)
{
	Nodo *aux;
	int x;

	if (a->getIzq() == nullptr) {
		aux = a;
		a = aux->getDer();
		delete aux;
	}
	else {
		if (a->getDer() == nullptr) {
			aux = a;
			a = a->getIzq();
			delete aux;
		}
		else {
			x = SearchMin(a->getDer());
			a->setData(x);
			DeleteNodo(a->getDer(), x);
		}
	}
}

Nodo *Tree::SearchElem(Nodo *a, int data)
{
	if (a != nullptr) {
		
		if (a->getData() == data) {
			return a;
		} 
		else {
			if (data < a->getData()) {
				return SearchElem(a->getIzq(), data);
			}
			else {
				return SearchElem(a->getDer(), data);
			}
		}
	}

	return nullptr;
}

Nodo *Tree::searchElem(int data)
{
	return SearchElem(getRoot(), data);
}

int Tree::IsLeaf(Nodo *a, int data)
{
	if (a != nullptr) {
		Nodo *temp = SearchElem(getRoot(), data);

		if (temp != nullptr) {
			if (temp->getDer() == nullptr && temp->getIzq() == nullptr)
				return 1;
			else
				return 2;
		}
	}
	
	return 0;
}

// Return:
// 0 if nodo not exists
// 1 if nodo is leaf
// 2 if nodo is not leaf
int Tree::isLeaf(int data)
{
	return IsLeaf(getRoot(), data);
}

void Tree::DeleteTree(Nodo *a)
{
	if (a != nullptr) {
		DeleteTree(a->getIzq());
		DeleteTree(a->getDer());
		delete a;
	}
}

void Tree::deleteTree()
{
	DeleteTree(getRoot());
	setRoot(nullptr);
	cout << "Tree is empy." << "\n" << "\n";
}

int Tree::isComplete(Nodo *_a) {
	if (_a != nullptr) {
		if (_a->getIzq() == nullptr ^ _a->getDer() == nullptr)
			return 1;
		else
			return isComplete(_a->getIzq()) + isComplete(_a->getDer());
	}

	return 0;
}

bool Tree::isComplete()
{
	return isComplete(getRoot()) == 0;
}

int Tree::max(int data1, int data2)
{
	if (data1 >= data2)
		return data1;
	else
		return data2;
}

int Tree::Height(Nodo *a)
{
	if (a == nullptr) {
		return 0;
	} else {
		int alt = 1 + max(Height(a->getIzq()), Height(a->getDer()));
		return alt;
	}
}

int Tree::height()
{
	return Height(getRoot());
}

bool Tree::Iquals(Nodo *&a, Nodo *&b) {
	if (a == nullptr && b == nullptr)
		return true;
	else {
		if (a == nullptr || b == nullptr)
			return false;
		else {
			if (a->getData() == b->getData())
				return Iquals(a->getIzq(), b->getIzq()) && Iquals(a->getDer(), b->getDer());
			else
				return false;
		}
	}
}

bool Tree::iquals(Tree *a, Tree *b) {
	return Iquals(a->getRoot(), b->getRoot());
}
