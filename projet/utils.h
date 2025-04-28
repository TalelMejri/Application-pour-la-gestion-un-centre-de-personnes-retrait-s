#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

void afficherChargement(const char* message, int duree) ;
void LogoutUser();
void resteConnecte(string email,string role);
void MenuResponsable(Responsable& res);
void MenuMedecin(Medecin& med);
void menuInfirmier(Infirmier );
void Connexion(credentials& connectedUser, credentials& c);
template<typename T>
T GetUserDetails( string email,  string role) {
    T user;
    string filename;
    if (role == "Resident") filename = "BD\\Resident.txt";
    else if(role=="Responsable")  filename = "BD\\Responsable.txt";
    else if(role =="Medecin") filename = "BD\\Medecin.txt";
    else if (role=="Infirmier")filename = "BD\\Infirmier.txt";
    else if(role=="MedecinInfirmier") filename = "BD\\MedecinInfirmier.txt";
    ifstream f(filename);
    if (!f.is_open()) {
            cerr << "Erreur lors de louverture de "<< filename << endl;
            exit(-1);
    }
     while (f >> user) {
        if (user.getEmail() == email) {
            f.close();
            return user;
        }
    }
    f.close();
    return user;
}
#endif // UTILS_H_INCLUDED
