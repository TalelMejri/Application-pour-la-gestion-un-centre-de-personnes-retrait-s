#include "env.h"

void afficherChargement(const char* message, int duree) {
    printf("\n\n%60s", message);
    fflush(stdout);
    for (int i = 0; i < duree; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void LogoutUser() {
    ofstream off("BD\\reste_connecte.txt", ios::trunc);
    if (off.is_open()) {
        off.close();
        cout << " Deconnexion reussie." << endl;
    } else {
        cout << "Erreur lors de la deconnexion." << endl;
    }
}

void resteConnecte(string email, string role) {
    ofstream of("BD\\reste_connecte.txt", ios::trunc);
    if (of.is_open()) {
        of << email << " " << role << endl;
        of.close();
    }
}

void Connexion(credentials& connectedUser, credentials& c) {
    string email, password;
    int choix;
    do {
        cout << "\n----- Bienvenue -----" << endl;
        cout << "1. Se connecter" << endl;
        cout << "2. S'inscrire" << endl;
        cout << "3. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        if (choix == 1) {
            cout << "\n--- Connexion ---" << endl;
            cout << "Email: ";
            cin >> email;
            cout << "Mot de passe: ";
            cin >> password;

            string role = c.VerifierEmailPassword(email, password);
            if (role != "") {
                cout << "\nConnexion reussie en tant que " << role << endl;
                int checkRes;
                cout << "\nVoulez-vous rester connecte ? (1 = Oui, 0 = Non): ";
                cin >> checkRes;
                if (checkRes == 1) resteConnecte(email, role);
                connectedUser.email = email;
                connectedUser.role = role;
                return;
            } else {
                cout << "\nCompte introuvable. Voulez-vous vous inscrire ? (1 = Oui, 0 = Non): ";
                int reponse;
                cin >> reponse;
                if (reponse == 1) {
                    Resident res;
                    cin >> res;
                    res.ecrirerResidentDansFichier();
                    afficherChargement("Enregistrement", 1);
                } else {
                    cout << "Retour au menu principal.\n";
                }
            }
        } else if (choix == 2) {
            Resident res;
            cin >> res;
            res.ecrirerResidentDansFichier();
            c.SaveCredentials(res.getEmail(), res.getPassword(), "Resident");
            afficherChargement("Enregistrement", 1);
            cout << "\nInscription réussie ! Vous pouvez maintenant vous connecter.\n";
        } else if (choix == 3) {
            afficherChargement("Au Revoir", 2);
            exit(0);
        } else {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
        cout << "\nAppuyez sur Entrée pour continuer...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (true);
}

void MenuResponsable(Responsable& responsable) {
    int choix;

    do {
        cout << "\n===== MENU RESPONSABLE =====" << endl;
        cout << "1. Ajouter un employe" << endl;
        cout << "2. Supprimer un employe" << endl;
        cout << "3. Modifier un employe" << endl;
        cout << "4. Afficher tous les employes" << endl;
        cout << "6. Supprimer un resident" << endl;
        cout << "7. Modifier un resident" << endl;
        cout << "8. Afficher tous les residents" << endl;
        cout << "9. Afficher informations du batiment" << endl;
        cout << "10. Gerer les etages (ajouter, supprimer, afficher)" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int typePersonnel;
                cout << "Quel type d'employe voulez-vous ajouter ?" << endl;
                cout << "1. Medecin\n2. MedecinInfirmier\nVotre choix : ";
                cin >> typePersonnel;

                Personnel* emp = nullptr;

                if (typePersonnel == 1) {
                    emp = new Medecin();
                    cin >> *(dynamic_cast<Medecin*>(emp));
                } else if (typePersonnel == 2) {
                    emp = new MedecinInfirmier();
                    cin >> *(dynamic_cast<MedecinInfirmier*>(emp));
                } else {
                    cout << "Type d employe invalide. Operation annulee.\n";
                    break;
                }

                responsable.ajouterEmploye(emp);
                cout << "Employe ajoute avec succes.\n";
                break;
            }
            case 2: {
                int id;
                cout << "ID de l'employe a supprimer : ";
                cin >> id;
                responsable.supprimerEmploye(id);
                break;
            }
            case 3: {
                int id;
                cout << "ID de l'employe a modifier : ";
                cin >> id;
                responsable.modifier(id);
                break;
            }
            case 4: {
                responsable.afficherEmployes();
                break;
            }
            case 6: {
                int id;
                cout << "ID du resident a supprimer : ";
                cin >> id;
                responsable.SupprimerResident(id);
                break;
            }
            case 7: {
                int id;
                cout << "ID du resident a modifier : ";
                cin >> id;
                responsable.ModifierResident(id);
                break;
            }
            case 8: {
                responsable.AfficherResident();
                break;
            }
            case 9: {
                cin >> responsable.batiment;
                cout << "Adresse : " << responsable.batiment.getAdresse() << " Nom : " << responsable.batiment.getNom();
                break;
            }
            case 10: {
                int sousChoix;
                cout << "\nGestion des etages :" << endl;
                cout << "1. Ajouter un etage" << endl;
                cout << "2. Supprimer un etage" << endl;
                cout << "3. Afficher tous les etages" << endl;
                cout << "Votre choix : ";
                cin >> sousChoix;

                if (sousChoix == 1) {
                    cout << "Quel type d'etage voulez-vous ajouter ?" << endl;
                    cout << "1. Etage Alzheimer\n2. Etage Cardio\n3. Etage Neurologie\nVotre choix : ";
                    int typeEtage;
                    cin >> typeEtage;
                    cout << "Donner le nombre de chambres : ";
                    int nbr_chambre;
                    cin >> nbr_chambre;

                    string typeStr;
                    Etage* nouvelEtage = nullptr;

                    if (typeEtage == 1) {
                        typeStr = "Alzheimer";
                        nouvelEtage = new EtageAlzheimer(-1, nbr_chambre, typeStr);
                    } else if (typeEtage == 2) {
                        typeStr = "Cardio";
                        nouvelEtage = new EtageCardio(-1, nbr_chambre, typeStr);
                    } else if (typeEtage == 3) {
                        typeStr = "Neurologie";
                        nouvelEtage = new EtageNeurologie(-1, nbr_chambre, typeStr);
                    } else {
                        cout << "Type d'etage invalide." << endl;
                        break;
                    }

                    responsable.batiment.ajouterEtage(typeStr, nouvelEtage);
                    responsable.batiment.enregistrerEtages();
                    cout << "Etage ajoute avec succes." << endl;

                } else if (sousChoix == 2) {
                    responsable.batiment.afficherEtage();
                    cout << "Entrez le type d'etage a supprimer : ";
                    string type;
                    cin >> type;
                    cout << "Entrez l'ID de l'etage a supprimer : ";
                    int id;
                    cin >> id;
                    responsable.batiment.supprimerEtage(type, id);
                } else if (sousChoix == 3) {
                    responsable.batiment.afficherEtage();
                }
                break;
            }
            case 0:
                LogoutUser();
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Essayez encore." << endl;
        }

    } while (choix != 0);
}

void MenuMedecin(Medecin& med) {
    int choix;
    do {
        system("cls");
        cout << "\n===== MENU MEDECIN =====" << endl;
        cout << "1. Afficher mes informations" << endl;
        cout << "2. Ajouter Dossier Medical " << endl;
        cout << "3. Gerer les infirmiers " << endl;
        cout << "4. Gerer mes categories" << endl;
        cout << "5. Afficher Reclamations" << endl;
        cout << "6. Deconnexion" << endl;
        cout << "Votre choix: ";
        cin >> choix;
        vector<Infirmier*> listeInfirmiers=med.getinfirmiersAssignes();
        switch (choix) {
            case 1: {
                system("cls");
                cout << "\n--- Mes Informations ---\n";
                med.afficherPersonne();
                cout << "\nAppuyez sur Entree pour continuer...";
                cin.ignore();
                cin.get();
                break;
            }
             case 2:
                    med.ajouterDossierMedicalResident();
                    break;
            case 3: {
                int sousChoix;
                do {
                    system("cls");
                    cout << "\n--- Gerer les infirmiers assignes ---\n";
                    cout << "1. Afficher les infirmiers assignes" << endl;
                    cout << "2. Ajouter un nouvel infirmier" << endl;
                    cout << "3. Modifier un infirmier assigne" << endl;
                    cout << "4. Supprimer un infirmier assigne" << endl;
                    cout << "5. Retour au menu principal" << endl;
                    cout << "Votre choix: ";
                    cin >> sousChoix;

                    switch (sousChoix) {
                        case 1:
                            med.afficherInfirmiersAssignes();
                            break;
                        case 2: {
                                Infirmier* nouvelInfirmier = new Infirmier();
                                cout << "\n--- Ajouter un nouvel infirmier ---\n";
                                cin >> *nouvelInfirmier;
                                med.assignerInfirmier(nouvelInfirmier);
                                nouvelInfirmier->ecrirerInfirmierDansFichier();
                                credentials c;
                                c.SaveCredentials(nouvelInfirmier->getEmail(), nouvelInfirmier->getPassword(), "Infirmier");
                                cout << "Infirmier ajouté et assigné avec succès!\n";
                                break;
                        }
                        case 3:
                            med.modifierInfirmierAssignes();
                            break;
                        case 4:
                            med.supprimerInfirmierAssignes();
                            break;
                        case 5:
                            cout << "Retour au menu medecin...\n";
                            break;
                        default:
                            cout << "Choix invalide. Reessayez.\n";
                    }

                    if (sousChoix != 5) {
                        cout << "\nAppuyez sur Entree pour continuer...";
                        cin.ignore();
                        cin.get();
                    }
                } while (sousChoix != 5);
                break;
            }
            case 4: {
                int sousChoix;
                do {
                    system("cls");
                    cout << "\n--- Gerer les categories ---\n";
                    cout << "1. Afficher mes categories" << endl;
                    cout << "2. Ajouter une categorie" << endl;
                    cout << "3. Modifier une categorie" << endl;
                    cout << "4. Supprimer une categorie" << endl;
                    cout << "5. Retour au menu principal" << endl;
                    cout << "Votre choix: ";
                    cin >> sousChoix;

                    switch (sousChoix) {
                        case 1:
                            med.afficherCategories();
                            break;
                        case 2: {
                            Category cat;
                            cout << "\n--- Ajouter une categorie ---\n";
                            cin >> cat;
                            med.ajouterCategory(cat);
                            cout << "Categorie ajoutee !" << endl;
                            break;
                        }
                        case 3:
                            med.afficherCategories();
                            if (!med.getCategories().empty()) {
                                int pos;
                                cout << "\nEntrez la position de la categorie a modifier : ";
                                cin >> pos;
                                med.ModifierCategory(pos - 1);
                            }
                            break;
                        case 4:
                            med.afficherCategories();
                            if (!med.getCategories().empty()) {
                                int pos;
                                cout << "\nEntrez la position de la categorie a supprimer : ";
                                cin >> pos;
                                med.SupprimerCategory(pos - 1);
                            }
                            break;
                        case 5:
                            cout << "Retour au menu medecin...\n";
                            break;
                        default:
                            cout << "Choix invalide. Reessayez.\n";
                    }

                    if (sousChoix != 5) {
                        cout << "\nAppuyez sur Entree pour continuer...";
                        cin.ignore();
                        cin.get();
                    }
                } while (sousChoix != 5);
                break;
            }
            case 5:{
                med.AfficherReclamations();
                break;
            }
            case 6:
                LogoutUser();
                cout << "Deconnexion reussie." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
                cin.ignore();
                cin.get();
        }
    } while (choix != 6);
}


void menuInfirmier(Infirmier infirmier) {
    int choix;

    do {
        cout << "\n--- Menu Infirmier ---" << endl;
        cout << "1. Donner une Reclamation" << endl;
        cout << "2. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                string reclamation;
                cin.ignore();
                cout << "Entrez votre reclamation : ";
                getline(cin, reclamation);

                ofstream fichier("BD/reclamations.txt", ios::app);
                if (fichier.is_open()) {
                    fichier << reclamation << endl;
                    fichier.close();
                    cout << "Reclamation enregistree avec succes !" << endl;
                } else {
                    cerr << "Erreur lors de louverture du fichier de relamations !" << endl;
                }
                break;
            }
            case 2:
                cout << "Retour au menu principal..." << endl;
                LogoutUser();
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    } while (choix != 2);
}
