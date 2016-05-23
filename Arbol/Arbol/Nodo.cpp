#include "stdafx.h"
#include "Nodo.h"

Nodo::Nodo()
{
	this->setData(NULL);
	this->setIzq(nullptr);
	this->setDer(nullptr);
}

Nodo::~Nodo()
{
}

Nodo::Nodo(int _data)
{
	this->setData(_data);
	this->setIzq(nullptr);
	this->setDer(nullptr);
}

int Nodo::getData()
{
	return data;
}

void Nodo::setData(int _data)
{
	data = _data;
}

Nodo * Nodo::getIzq()
{
	return izq;
}

void Nodo::setIzq(Nodo *_izq)
{
	izq = _izq;
}

Nodo * Nodo::getDer()
{
	return der;
}

void Nodo::setDer(Nodo *_der)
{
	der = _der;
}
