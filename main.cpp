#include "Fahrzeug.h"

//Uhr initialisieren (global)
double dGlobaleZeit = 0.0;

/*
Funktion zum testen der Fahrzeug-Klasse.
Erstellt Fahrzeuge, ruft die Ausgabe-Funktion auf und löscht alle Fahrzeuge wieder
*/
void vAufgabe_1()
{
	//Statisch erzeugte Objekte
	Fahrzeug tAuto1;
	Fahrzeug tAuto2("PKW", 40.0);

	//Dynamisch erzeugte Objekte
	Fahrzeug* pAuto3;
	Fahrzeug* pAuto4;
	
	//Nutzer nach Fahrzeugnamen fragen
	string sAutoname;
	cout << "Geben sie einen Fahrzeugnamen ein:" << endl;
	cin >> sAutoname;
	pAuto3 = new Fahrzeug();
	pAuto4 = new Fahrzeug(sAutoname, 30.0);

	//Ausgabe der Fahrzeuge und Daten
	cout << endl << "ID  Name   :  MaxKmh   GesamtStrecke      " << endl;
	cout << setw(42) << setfill('+') << " " << endl;
	
	for (double d = 0; d <= 2.1; d += 0.1)
	{
		dGlobaleZeit = d;
		
		tAuto1.vAbfertigung();
		tAuto2.vAbfertigung();
		pAuto3->vAbfertigung();
		pAuto4->vAbfertigung();

		cout << "Nach " << dGlobaleZeit << "h:" << endl;
		tAuto1.vAusgabe();
		cout << endl;
		tAuto2.vAusgabe();
		cout << endl;
		pAuto3->vAusgabe();
		cout << endl;
		pAuto4->vAusgabe();
		cout << endl << endl;
	}

	getchar();

	//Löschen der dynamischen Objekte
	delete pAuto4;	
	delete pAuto3;
}

/*
-!-War eine Idee, aber man müsste halt die einzelnen Objekte oder Pointer übergeben-!-
Rahmenfunktion für die Memberfunktion vAusgabe in Fahrzeug.h zur Ausgabe der Fahrzeuge und Daten

void vHauptausgabe()
{

}
*/

void vAufgabe_1_deb()
{
	Fahrzeug* pFeld[4] = { new Fahrzeug("Rot", 40.0), new Fahrzeug("Blau", 25.0),
							new Fahrzeug("Gruen", 30.0), new Fahrzeug("Gelb", 10.0) };

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

	pFeld[2] = 0;

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

}

int main()
{
	vAufgabe_1();
	//vAufgabe_1_deb();
	getchar();
	return 0;
}

