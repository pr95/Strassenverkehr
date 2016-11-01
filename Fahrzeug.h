#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(string);
	Fahrzeug(string, double);
	void vAusgabe();
	void vAbfertigung();
	~Fahrzeug();

private:
	string p_sName;
	int p_iID;
	static int p_iMaxID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;

	void vInitialisierung();
};

