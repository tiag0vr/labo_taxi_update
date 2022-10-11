/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Vanessa Rodrigues, Vitória Oliveira
Date creation : 29.09.2022
Description : Ce programme calcule le prix d'une course de taxi en €. L'utilisateur
				  est prié de saisir quelques informations pour le calcul du prix, puis
				  lui présente un ticket complet.
Remarque(s) : Le ticket est imprimé selon un format imposé dans la consigne.
 				  La saisie utilisateur n'est pas controlée.
Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {

	const float PRISE_EN_CHARGE = 5.0;
	const float SURTAXE_PAR_BAGAGE = 2.5;
	const float TARIF_PAR_MIN = 1.2;
	const int MIN_PAR_HEURE = 60; //Mieux mettre en float por éviter des conversions ?
	const short P = 2; // précision
	const short W = 26; // witdh (largeur), choisir un autre nom?

	unsigned short nbreBagages = 0;
	float distanceParcours = 0; // en [km]
	float vitesseMoyenne = 0;  // en [km/h]


	/*Présentation du ticket de caisse à l'utilisateur*/
	cout << endl << "Bonjour, ce programme calcule le" << endl
		  << "prix de votre course de taxi." << endl
		  << "Voici les conditions:" << endl
		  << "================================" << endl;

	cout << fixed << setprecision(P);
	cout << left << setw(W) << " - prise en charge" << ": "
	     << PRISE_EN_CHARGE << endl
		  << left << setw(W)<< " - supp par bagage" << ": "
		  << SURTAXE_PAR_BAGAGE << endl
		  << left << setw(W) << " - tarif/minute" << ": "
		  << TARIF_PAR_MIN << endl;

	cout << endl << "Votre commande" << endl
		  << "================================" << endl
		  << setw(W) << " - nbre de bagage" << ": ";
	     cin >> nbreBagages;
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');

		  cout << left << setw(W) <<  " - distance [km]" << ": ";
		  cin >> distanceParcours;
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');

		  cout << left << setw(W) << " - vitesse [km/h]" << ": ";
		  cin >> vitesseMoyenne;
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');

	/*Calcul du supplément de bagages*/
	float suppBagages = SURTAXE_PAR_BAGAGE * nbreBagages;

	/*Calcul du prix de la course*/
	float prixCourse = distanceParcours / vitesseMoyenne * MIN_PAR_HEURE
							 * TARIF_PAR_MIN;

	/*Calcul du prix total*/
	float total = PRISE_EN_CHARGE + suppBagages + prixCourse;

	cout << fixed << setprecision(P);
	cout << endl << "Votre ticket" << endl
		  << "================================" << endl
		  << left << setw(W) << " - prise en charge" << ": "
		  << PRISE_EN_CHARGE << endl
		  << left << setw(W) << " - supp bagages" << ": "
		  << suppBagages << endl
		  << left << setw(W) << " - prix de la course" << ": "
		  << prixCourse << endl
		  << " TOTAL : " << total << endl;

	/*Fin de programme*/
	cout << endl << "Presser ENTER pour quitter";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return EXIT_SUCCESS;
}
