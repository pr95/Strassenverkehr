#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 1;

Fahrzeug::Fahrzeug()
{
	vInitialisierung();

	cout << "Fahrzeug Name: " << p_iID << " " << p_sName << endl;
}

Fahrzeug::Fahrzeug(string aName)
{
	vInitialisierung();
	p_sName = aName;

	cout << "Fahrzeug Name: " <<  p_iID << " " << p_sName << endl;
}

Fahrzeug::Fahrzeug(string aName, double aMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = aName;
	p_dMaxGeschwindigkeit = aMaxGeschwindigkeit;

	cout << "Fahrzeug Name: " << p_iID << " " << p_sName << endl;
}

Fahrzeug::~Fahrzeug()
{
	cout << "Fahrzeug " << p_iID << " " << p_sName << " wird geloescht" << endl;
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
		<< p_iID << setw(7) << setfill(' ') << p_sName << ":" << resetiosflags(ios::left) << setiosflags(ios::right) 
		<< setw(8) << setfill(' ') << p_dMaxGeschwindigkeit << setw(11) << setfill(' ') << p_dGesamtStrecke;
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
	}
	else
	{
		p_dGesamtStrecke = (dGlobaleZeit*p_dMaxGeschwindigkeit);
	}
	
	p_dZeit = dGlobaleZeit;
}