/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Vanessa Rodrigues, Vitória Oliveira, Tiago De Oliveira Jorge, Guillaume Ecuey
Date creation : 29.09.2022 / Date de reprise : 11.10.2022
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

// Ajout d'une macro pour vider le buffer
// Tous les vidages de buffer ont été remplacés par la macro
#define CLEAR_BUF cin.ignore(numeric_limits<streamsize>::max(), '\n')

// Ajout d'une macro pour la fin de programme
#define END cout << "presser ENTREE pour quitter"; CLEAR_BUF; return EXIT_SUCCESS

using namespace std;

int main() {

   // Déclaration des constantes
   // Ajout du caractère f devant les valeurs des variables float
	const float PRISE_EN_CHARGE = 5.0f;
	const float SURTAXE_PAR_BAGAGE = 2.5f;
	const float TARIF_MIN_JOUR = 1.0f;        // Ajout de constante pour le tarif jour
   const float TARIF_MIN_NUIT = 1.6f;        // Ajout de constante pour le tarif nuit
	const int MIN_PAR_HEURE = 60;
   const string HORAIRE_JOUR = "8h00-20h00"; // Ajout de constante pour l'horaire du tarif jour
	const short P = 2;                        // Variable de précision
	const short W = 26;                       // Variable de largeur d'indentation dans le terminal

   // Suppression de l'initialisation des variables avec valeur 0
	unsigned short nbreBagages;
	float distanceParcours;                   // en [km]
	float vitesseMoyenne;                     // en [km/h]
   string heureDepart;                            // Heure de départ souhaitée par l'utilisateur


	// Présentation du ticket de caisse à l'utilisateur
	cout << endl << "Bonjour, ce programme calcule le" << endl
		  << "prix de votre course de taxi."            << endl
		  << "Voici les conditions:"                    << endl
		  << "================================"         << endl;

	cout << fixed << setprecision(P);                           // Configuration de la précision des nombres
	cout << left << setw(W) << " - prise en charge" << ": "
	     << PRISE_EN_CHARGE << endl
		  << left << setw(W)<< " - supp par bagage" << ": "
		  << SURTAXE_PAR_BAGAGE << endl
		  << left << setw(W) << " - tarif/minute (jour)" << ": " // Modification en tarif jour
		  << TARIF_MIN_JOUR << endl
        << left << setw(W) << " - tarif/minute (nuit)" << ": " //Modificaton en tarif nuit
        << TARIF_MIN_NUIT << endl
        << left << setw(W) << " - tarif jour" << ": "          // Ajout de l'horaire jour
        << HORAIRE_JOUR << endl;

   // Affichage de la commande de l'utilisateur
   // Ajout des limites des inputs utilisateur et ajout de l'heure de départ
	cout << endl << "Votre commande" << endl
		  << "================================" << endl
		  << setw(W) << " - nbre de bagage              [0 - 4]" << ": ";
	     cin >> nbreBagages;
        CLEAR_BUF;
        // Ajout de la validation de l'entrée du nombre de bagages
        if (nbreBagages < 0 || nbreBagages > 4){
           cout << "Cette entrée est invalide !" << endl;
           END;
        }

		  cout << left << setw(W) <<  " - distance [km] [0 - 500]" << ": ";
		  cin >> distanceParcours;
        CLEAR_BUF;
        // Ajout de la validation de l'entrée de la distance du parcours
        if (distanceParcours < 0 || distanceParcours > 500){
           cout << "Cette entrée est invalide !" << endl;
           END;
        }

		  cout << left << setw(W) << " - vitesse   [km/h] [30-120]" << ": ";
		  cin >> vitesseMoyenne;
        CLEAR_BUF;
        // Ajout de la validation de la vitesse moyenne
        if (vitesseMoyenne < 30 || vitesseMoyenne > 120){
           cout << "Cette entrée est invalide !" << endl;
           END;
        }

        cout << left << setw(W) << " - depart    [hh:mm]" << ": ";
        cin >> heureDepart;
        CLEAR_BUF;
        ///// A CONTINUER VALIDATION DE L'HEURE DE DEPART
        // Ajout de la validation de l'heure de départ
        if (heureDepart < ? || heureDepart > ?){
           cout << "Cette entrée est invalide !" << endl;
           END;
        }

	// Calcul du supplément de bagages
	float suppBagages = SURTAXE_PAR_BAGAGE * nbreBagages;

	// Calcul du prix de la course
   /// A CORRIGER
	float prixCourse = distanceParcours / vitesseMoyenne * MIN_PAR_HEURE
							 * TARIF_MIN_JOUR;

	// Calcul du prix total
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

	// Fin de programme
	cout << endl << "Presser ENTER pour quitter";
	CLEAR_BUF;

	return EXIT_SUCCESS;
}
