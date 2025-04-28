#include "env.h"
using namespace std;

int main() {
    afficherChargement("CenterX", 2);
    system("cls");
    system("color F0");

    credentials c;
    credentials connectedUser;

    while (true) {
        connectedUser = c.CheckConnecter();

        if (connectedUser.email == "") {
            Connexion(connectedUser, c);
        }
        if (connectedUser.role == "Resident") {
            Resident r = GetUserDetails<Resident>(connectedUser.email, connectedUser.role);
            MenuResident(r);
        } else if (connectedUser.role == "Infirmier") {
            Infirmier inf = GetUserDetails<Infirmier>(connectedUser.email, connectedUser.role);
            menuInfirmier(inf);
        } else if (connectedUser.role == "Medecin") {
            Medecin med = GetUserDetails<Medecin>(connectedUser.email, connectedUser.role);
            vector<Resident> residents;
            try{
                ifstream of("BD\\Resident.txt");
                Resident r;
                while (of >> r) {
                        residents.push_back(r);
                }
                of.close();
            }catch(exception e){
                    cerr<<"Erreur"<<e.what();
            }
            MenuMedecin(med,residents);
        }  else if (connectedUser.role == "Responsable") {
            Responsable res = GetUserDetails<Responsable>(connectedUser.email, connectedUser.role);
            MenuResponsable(res);
        }
        connectedUser.email = "";
        connectedUser.role = "";
    }

    return 0;
}

/*else if (connectedUser.role == "MedecinInfirmier") {
            MedecinInfirmier medInf = GetUserDetails<MedecinInfirmier>(connectedUser.email, connectedUser.role);
            // MenuMedecinInfirmier(medInf);
}*/
