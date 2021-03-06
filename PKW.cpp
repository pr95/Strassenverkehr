#include "PKW.h"


//Standardkonstruktor
PKW::PKW() : Fahrzeug()
{
}

//Konstruktor mit allen Attributen
PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen):Fahrzeug(sName, dMaxGeschwindigkeit)
{
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
}

//Destruktor (virtuell)
PKW::~PKW()
{
}

//Gibt den Gesamtverbrauch zur�ck
double PKW::dVerbrauch()
{
	return p_dVerbrauch*p_dGesamtStrecke;
}

/*
Funktion zum betanken des PKWs. Defaultparameter ist auf 666 gesetzt als gen�gend gro�e Zahl zum volltanken
egal wie gro� der Tank ist.
Es wird die tats�chlich getankte Menge zur�ckgegeben.
*/
double PKW::dTanken(double dMenge)
{
	double dTankDif = p_dTankvolumen - p_dTankinhalt;

	if (dMenge >= dTankDif)
	{
		cout << "Das Fahrzeug " << p_sName << " wurde mit " << dTankDif << "l voll getankt!" << endl;
		p_dTankinhalt = p_dTankvolumen;
		
		return dTankDif;
	}
	else
	{
		p_dTankinhalt += dMenge;
		cout << "Das Fahrzeug " << p_sName << " wurde mit " << dMenge << "l auf " << p_dTankinhalt << "l aufgef�llt!" << endl;
		
		return dMenge;
	}

	return 0;
}

/*
Funktion zur speziellen Abfertigung von PKW. Erst wird geschaut, ob der PKW �berhaupt noch Tankinhalt hat,
danach wird erst die allgemeine Abfertigung aufgerufen, wobei der alte Streckenstand gespeichert wird zur
Berechnung der nur im letzten Schritt abgelegten Strecke
*/
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double dGesamtstreckeAlt = p_dGesamtStrecke;
		
		Fahrzeug::vAbfertigung();

		p_dTankinhalt -= (p_dVerbrauch/100) *(p_dGesamtStrecke - dGesamtstreckeAlt);

		if (p_dTankinhalt < 0)
		{
			p_dTankinhalt = 0;
		}
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(17) << setfill(' ') << dVerbrauch() << setw(15) << setfill(' ') << p_dTankinhalt;
}

double PKW::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}