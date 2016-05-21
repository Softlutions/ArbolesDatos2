#pragma once
#include "stdafx.h"
template<typename T>
class Nodo<T>
{
public:
	Nodo();
	~Nodo();

	Nodo(T data);

	Nodo<T> getIzq();
	void setIzq();

	Nodo<T> getDer();
	void setDer();
private:
	T data;
	Nodo<T> izq;
	Nodo<T> der;
};

