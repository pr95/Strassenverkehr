#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 1;

//Standardkonstruktor
Fahrzeug::Fahrzeug()
{
	vInitialisierung();

	//cout << "Fahrzeug Name: " << p_iID << " " << p_sName << endl;
}

//Konstruktor mit Name
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;

	//cout << "Fahrzeug Name: " <<  p_iID << " " << p_sName << endl;
}

//Konstruktor mit Name und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;

	//cout << "Fahrzeug Name: " << p_iID << " " << p_sName << endl;
}

//Virtueller Destruktor
Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug " << p_iID << " " << p_sName << " wird geloescht" << endl;
}

/*
Funktion zur Initialisierung von allen Attributen und Vergabe der ID.
*/
void Fahrzeug::vInitialisierung()
{
	p_sName = "";
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0.00;
	p_dZeit = 0;

	p_iID = p_iMaxID;
	p_iMaxID++;
}

/*
Ausgabe der Objektdaten in formatierter Form
*/
void Fahrzeug::vAusgabe()
{
	cout << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << setfill(' ') 
		<< p_iID << setw(9) << setfill(' ') << p_sName << ":" << resetiosflags(ios::left) << setiosflags(ios::right) 
		<< setw(8) << setfill(' ') << p_dMaxGeschwindigkeit << setw(8) << setfill(' ') << this->dGeschwindigkeit() << setw(11) << setfill(' ') << p_dGesamtStrecke;
}

/*
Aktualisiert die Gesamtstrecke nach um die im vergangenen Zeitraum abgefahrene Strecke.
Prüft zuerst, ob Fahrzeug bereits in dem selben Zeitraum abgefertigt wurde über p_dZeit.
*/
void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit == p_dZeit && dGlobaleZeit != 0.0)
	{
		cout << "Dieses Fahrzeug wurde bereits abgefertigt in diesem Zeitschritt" << endl;
		return;
	}
	else
	{
		p_dGesamtStrecke += gZeitschritt * this->dGeschwindigkeit();
	}
	
	p_dZeit = dGlobaleZeit;
}

//Default Funktion für alle Tochterklassen
double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}