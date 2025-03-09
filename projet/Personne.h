#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct date{
    int jour;
    int mois;
    int anne;
} DATE;

class Personne{
    protected:
        int id;
        string nom;
        string prenom;
        string cinn;
        string email;
        string password;
        string tlf;
        DATE date_naissance;

    public:
        Personne();
        Personne(int, string, string, string, string, string, string, DATE);
        Personne(const Personne&);
        virtual ~Personne();
        virtual void afficherPersonne()=0;
        virtual void modifier()=0;
        void saisir_personne();

        int getId(){ return id; }
        string getNom(){ return nom; }
        string getPrenom(){ return prenom; }
        string getCIN(){ return cinn; }
        string getEmail(){ return email; }
        string getPassword(){ return password; }
        string getTlf(){ return tlf; }
        DATE getDateNaissance(){ return date_naissance; }

        void setId(int idVal){ id = idVal; }
        void setNom(string nomVal){ nom = nomVal; }
        void setPrenom(string prenomVal){ prenom = prenomVal; }
        void setCIN(string cinnVal){ cinn = cinnVal; }
        void setEmail(string emailVal){ email = emailVal; }
        void setPassword(string passwordVal){ password = passwordVal; }
        void setTlf(string tlfVal){ tlf = tlfVal; }
        void setDateNaissance(DATE dateVal){ date_naissance = dateVal; }

};

#endif // PERSONNE_H_INCLUDED
