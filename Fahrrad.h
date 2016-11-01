#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{

public:
	Fahrrad();
	Fahrrad(string, double);
	~Fahrrad();

private:
	double dGeschwindigkeit();
};

