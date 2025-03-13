#include <iostream>
#include <vector>
#include <unistd.h>
#include "Batiment.cpp"
#include "Etage.cpp"
#include "Chambre.h"
#include "ChambrePatient.h"
#include "ChambrePersonnel.h"
#include "ChambreMultiple.h"
#include "Medicament.h"
#include "DossierMedical.h"
#include "Medecin.h"
#include "Infirmier.cpp"
#include "Resident.h"
#include "EtageCardio.h"
#include "Responsable.h"
#include "Category.h"
#include "EtageAlzheimer.h"
#include <stdio.h>

using namespace std;

void afficherChargement(const char *message, int duree) {
    printf("\n\n                                                         %s", message);
    fflush(stdout);
    for (int i = 0; i < duree; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main() {
    afficherChargement("Chargement", 5);
    system("cls");
    system("color F0");
    Batiment batiment("Centre", "Projet");
    EtageCardio etageCardio(1);
    EtageAlzheimer etageAlzheimer(2);

    batiment.ajouterEtage(&etageCardio);
    batiment.ajouterEtage(&etageAlzheimer);

    Resident* resident = new Resident(1, "TestRes", "TestRes", "123456", "TestRes@example.com", "motdepasse", "123456789", {1, 1, 1990}, 1500);
    Infirmier* infirmier = new Infirmier(2, "TestInf", "TestInf", "987654", "TestInf@example.com", "password", "987654321", {1, 1, 1990}, 2000, "Infirmier", 5);
    Medecin* medecin = new Medecin(3, "TestMed", "TestMed", "135792", "TestMed@example.com", "password", "123123123", {10, 10, 1980}, 5000, "Cardiologue");

    batiment.ajouterPersonne(resident);
    batiment.ajouterPersonne(infirmier);
    batiment.ajouterPersonne(medecin);

    int choix;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Afficher Batiment" << endl;
        cout << "2. Ajouter une personne" << endl;
        cout << "3. Ajouter un etage" << endl;
        cout << "4. Afficher les personnes du batiment" << endl;
        cout << "5. Afficher les etages du batiment" << endl;
        cout << "6. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch(choix) {
            case 1:
                batiment.afficherBatiment();
                break;
            case 2: {
                int typePersonne;
                cout << "Entrez le type de personne (1: Resident, 2: Infirmier, 3: Medecin): ";
                cin >> typePersonne;

                if (typePersonne == 1) {
                    Resident* newResident = new Resident(4, "test", "test", "112233", "test@example.com", "pass1234", "123987654", {25, 12, 1995}, 1000);
                    batiment.ajouterPersonne(newResident);
                    cout << "Resident ajouté!" << endl;
                } else if (typePersonne == 2) {
                    Infirmier* newInfirmier = new Infirmier(5, "test2", "test", "667788", "test@example.com", "password", "667788990", {15, 3, 1988}, 2200, "Infirmier",8);
                    batiment.ajouterPersonne(newInfirmier);
                    cout << "Infirmier ajouté!" << endl;
                } else if (typePersonne == 3) {
                    Medecin* newMedecin = new Medecin(6, "test3", "test", "102938", "test@example.com", "12345", "987654321", {18, 7, 1975}, 5500, "Neurologue");
                    batiment.ajouterPersonne(newMedecin);
                    cout << "Medecin ajouté!" << endl;
                } else {
                    cout << "Type de personne invalide!" << endl;
                }
                break;
            }
            case 3: {
                int typeEtage;
                cout << "Entrez le type d'etage (1: Cardio, 2: Alzheimer): ";
                cin >> typeEtage;

                if (typeEtage == 1) {
                    EtageCardio* newEtage = new EtageCardio(3);
                    batiment.ajouterEtage(newEtage);
                    cout << "Etage Cardio ajouté!" << endl;
                } else if (typeEtage == 2) {
                    EtageAlzheimer* newEtage = new EtageAlzheimer(4);
                    batiment.ajouterEtage(newEtage);
                    cout << "Etage Alzheimer ajouté!" << endl;
                } else {
                    cout << "Type d'etage invalide!" << endl;
                }
                break;
            }
            case 4:
                cout << "\nListe des personnes dans le batiment:" << endl;
                for (auto personne : batiment.getPersonnes()) {
                    personne->afficherPersonne();
                }
                break;
            case 5:
                cout << "\nListe des etages dans le batiment:" << endl;
                for (auto etage : batiment.getEtages()) {
                    etage->afficherEtage();
                }
                break;
            case 6:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    } while (choix != 6);

    delete resident;
    delete infirmier;
    delete medecin;

    return 0;
}
