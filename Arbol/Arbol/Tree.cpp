#include "Tree.h"

Tree::Tree()
{
	setRoot(nullptr);
}

Tree::~Tree()
{
}

Nodo *Tree::getRoot()
{
	return root;
}

void Tree::setRoot(Nodo *_root)
{
	root = _root;
}

void Tree::insertElem(int data, Nodo *a)
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
	return false;
}

int Tree::weight()
{
	return 0;
}

int Tree::countLeaf()
{
	return 0;
}

bool Tree::isEmpty()
{
	return getRoot() == nullptr;
}

void Tree::inOrder(Nodo *_a)
{
	if (_a != nullptr) {
		inOrder(_a->getIzq());
		cout << _a->getData() << "\n";
		inOrder(_a->getDer());
	}
}

void Tree::printTree()
{
	inOrder(getRoot());
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

int Tree::DeleteMin(Nodo *a)
{
	int data;

	if (a->getIzq() == nullptr) {
		if (a->getDer() != nullptr) {
			a->setData(a->getDer()->getData());
			a->setDer(a->getDer()->getDer());
		} else {
			// terminar
			data = a->getData();
			delete a;
			return data;
		}
		return a->getData();
	} else {
		return DeleteMin(a->getIzq());
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
			a->setData(DeleteMin(a->getDer()));
		}
	}
}

bool Tree::deleteNodo(int data)
{
	Nodo *aux = searchElem(data);
	if (aux != nullptr) {
		DeleteNodo(aux);
		return true;
	}
	return false;
}

Nodo * Tree::SearchElem(Nodo *a, int data)
{
	if (a != nullptr) {
		
		if (a->getData() == data) {
			return a;
		} 
		else {
			if (data < a->getData()) {
				SearchElem(a->getIzq(), data);
			}
			else {
				SearchElem(a->getDer(), data);
			}
		}
	}
	return nullptr;
}

Nodo * Tree::searchElem(int data)
{
	return SearchElem(getRoot(), data);
}

int Tree::IsLeaf(Nodo *a, int data)
{
	if (a != nullptr) {
		Nodo *temp = SearchElem(getRoot(), data);

		if (temp != nullptr) {
			if (temp->getDer() == nullptr && temp->getIzq() == nullptr) {
				return 1;
			}
		} else {
			return 2;
		}
	} else {
		return 0;
	}
}

// Return:
// 0 if tree is empy
// 1 if nodo is leaf
// 2 if nodo is not leaf
int Tree::isLeaf(int data)
{
	return IsLeaf(getRoot(), data);
}

int Tree::CountLeaf(Nodo *a, int count)
{	
	return 0;
}

int Tree::countLeaf()
{
	return 0;
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