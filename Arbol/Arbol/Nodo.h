#pragma once
#include "stdafx.h"

class Nodo
{
private:
	int data;
	Nodo *izq;
	Nodo *der;

public:
	Nodo();
	~Nodo();

	Nodo(int);

	int getData();
	void setData(int);

	Nodo *&getIzq();
	void setIzq(Nodo *);

	Nodo *&getDer();
	void setDer(Nodo *);
};