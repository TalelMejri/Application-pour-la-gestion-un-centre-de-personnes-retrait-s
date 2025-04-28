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

void resteConnecte(string email,string role){
 ofstream of("BD\\reste_connecte.txt", ios::trunc);
    if (of.is_open()) {
        of << email << " " << role << endl;
        of.close();
    }
}

void MenuResponsable(Responsable res){

}

