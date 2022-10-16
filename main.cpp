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
#include <cmath>

// Ajout d'une macro pour vider le buffer
// Tous les vidages de buffer ont été remplacés par la macro
#define CLEAR_BUF cin.ignore(numeric_limits<streamsize>::max(), '\n')

// Ajout d'une macro pour la fin de programme
#define END cout << "presser ENTREE pour quitter"; CLEAR_BUF; return EXIT_SUCCESS

using namespace std;

int main() {

   // Déclaration des constantes
   // Ajout du caractère f devant les valeurs des variables float
	const float PRISE_EN_CHARGE      = 5.0f;
	const float SURTAXE_PAR_BAGAGE   = 2.5f;
	const float TARIF_MIN_JOUR       = 1.0f;        // Ajout de constante pour le tarif jour
   const float TARIF_MIN_NUIT       = 1.6f;        // Ajout de constante pour le tarif nuit
	const int MIN_PAR_HEURE          = 60;
   const string HORAIRE_JOUR        = "8h00-20h00"; // Ajout de constante pour l'horaire du tarif jour
	const short P                    = 2;           // Variable de précision
	const short W                    = 26;          // Variable de largeur d'indentation dans le terminal
    const short W1                   = 13;          // première variable de largeur de correction de l'affichage
    const short W2                   = 28;          // deuxième variable de largeur de correction de l'affichage

   const int FIN_HORAIRE_NUIT_MIN   = 480;
   const int DEBUT_HORAIRE_NUIT_MIN = 1200;
   const int HEURE_MINUIT_MIN       = 1440;

   // Suppression de l'initialisation des variables avec valeur 0
	unsigned short nbreBagages;
	float distanceParcours;                   // en [km]
	float vitesseMoyenne;                     // en [km/h]
   unsigned int heureDepart;                 // Heure de départ souhaitée par l'utilisateur
   unsigned int minutesDepart;               // Minutes de départ souhaitées par l'utilisateur


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

   // Ajout des limites des inputs utilisateur et ajout de l'heure de départ
   cout << endl << "Votre commande" << endl
		  << "================================" << endl;
		  cout << setw(W) << left << " - nbre de bagage [0 - 4]" << ": ";
	     cin >> nbreBagages;
        CLEAR_BUF;
        // Ajout de la validation de l'entrée du nombre de bagages
        if (nbreBagages < 0 || nbreBagages > 4){
           cout << "Cette entree est invalide !" << endl;
           END;
        }
        cout << left << setw(W) <<  " - distance [km] [0 - 500]" << ": ";
		  cin >> distanceParcours;
        CLEAR_BUF;
        // Ajout de la validation de l'entrée de la distance du parcours
        if (distanceParcours < 0 || distanceParcours > 500){
           cout << "Cette entree est invalide !" << endl;
           END;
        }

		  cout << left << setw(W) << " - vitesse  [km/h] [30-120]" << ": ";
		  cin >> vitesseMoyenne;
        CLEAR_BUF;
        // Ajout de la validation de la vitesse moyenne
        if (vitesseMoyenne < 30 || vitesseMoyenne > 120){
           cout << "Cette entree est invalide !" << endl;
           END;
        }

        char c; // Caractère pour insérer et ignorer ':'
        cout << left << setw(W) << " - depart   [hh:mm] : ";
        cin >> heureDepart >> c >> minutesDepart;
        CLEAR_BUF;
        // Ajout de la validation de l'heure de départ
        if (heureDepart < 0 || heureDepart > 23 || minutesDepart < 0 || minutesDepart > 59) {
           cout << "Cette entree est invalide !" << endl;
           END;
        }


	// Calcul du prix de la course
   int dureeCourse      = ceil(distanceParcours * 60 / vitesseMoyenne);
   int departMin        = heureDepart * 60 + minutesDepart;
   int dureeCourseNuit  = 0;
   int dureeCourseJour  = 0;
   int tempCalc;  // Variable temporaire utilisée pour le calcul des courses entre horaire jour et nuit

   while(dureeCourse > 0){
      // Si le départ est dans l'horaire de nuit (0h00 - 7h59)

      if(departMin < FIN_HORAIRE_NUIT_MIN){
         // Test si la durée de la course nuit est continuée en horaire jour
         departMin + dureeCourse < FIN_HORAIRE_NUIT_MIN ? tempCalc = dureeCourse : tempCalc = FIN_HORAIRE_NUIT_MIN -
            departMin;
         dureeCourseNuit   += tempCalc;
         dureeCourseJour   -= tempCalc;
         departMin     = FIN_HORAIRE_NUIT_MIN;
      }

      // Test si le départ est durant l'horaire de jour (8h00 - 19h59)
      if(departMin < DEBUT_HORAIRE_NUIT_MIN){

         departMin + dureeCourse < DEBUT_HORAIRE_NUIT_MIN ? tempCalc = dureeCourse : tempCalc =
            DEBUT_HORAIRE_NUIT_MIN - departMin;

         dureeCourseJour += tempCalc;
         dureeCourse     -= tempCalc;
         departMin       = DEBUT_HORAIRE_NUIT_MIN;
      }

      // Test si le départ est durant l'horaire de nuit (20h00 - 23h59)
      if(departMin >= DEBUT_HORAIRE_NUIT_MIN){

         departMin + dureeCourse < HEURE_MINUIT_MIN ? tempCalc = dureeCourse : tempCalc = HEURE_MINUIT_MIN - departMin;

         dureeCourseNuit += tempCalc;
         dureeCourse     -= tempCalc;
         departMin        = 0;
      }
   }

   // Calcul du prix total
   float suppBagages       = SURTAXE_PAR_BAGAGE * nbreBagages;
   float prixCourseJour    = dureeCourseJour * TARIF_MIN_JOUR;
   float prixCourseNuit    = dureeCourseNuit * TARIF_MIN_NUIT;
   float prixTotalCourse   = PRISE_EN_CHARGE + suppBagages + prixCourseJour + prixCourseNuit;

   // Affichage du ticket
	cout << fixed << setprecision(P);
	cout << endl << "Votre ticket" << endl
		  << "==================================" << endl
		  << left << setw(W) << " - prise en charge" << ": "
		  << PRISE_EN_CHARGE << endl
		  << left << setw(W) << " - supp bagages" << ": "
		  << suppBagages << endl
		  << left << setw(W) << " - temps course" << endl
          << "       " << dureeCourseJour   << "' @ " << setw(W1) <<  TARIF_MIN_JOUR << ": "
          << prixCourseJour << endl
          << "       " << dureeCourseNuit  << "' @ " << setw(W1) <<  TARIF_MIN_NUIT << ": "
          << prixCourseNuit << endl
          << "-------------------------- ---------" << endl
          << right << setw(W2) << " TOTAL : " << prixTotalCourse << endl;

	// Fin de programme
	cout << endl << "Presser ENTER pour quitter";
	CLEAR_BUF;

	return EXIT_SUCCESS;
}
