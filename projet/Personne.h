#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include "Date.h"
#include <iostream>
using namespace std;

class Personne{
    protected:
        static int idCounter;
        int id;
        string nom;
        string prenom;
        string cinn;
        string email;
        string password;
        string tlf;
        DatePerso date_naissance;

    public:
        Personne();
        Personne(int, string, string, string, string, string, string, DatePerso);
        Personne(const Personne&);
        virtual ~Personne();
        virtual void afficherPersonne();
        virtual void modifier()=0;
        void saisir_personne();
        friend ostream& operator <<(ostream&,const Personne &);
        friend istream& operator >>(istream& ,Personne&);
        friend ostream& operator <<(ostream&,const Personne *);
        friend istream& operator >>(istream& ,Personne*);
        Personne & operator=(const Personne&) ;

        int getId()const{ return id; }
        string getNom()const{ return nom; }
        string getPrenom()const{ return prenom; }
        string getCIN(){ return cinn; }
        string getEmail(){ return email; }
        string getPassword(){ return password; }
        string getTlf(){ return tlf; }
        DatePerso getDateNaissance(){ return date_naissance; }

        void setId(int idVal){ id = idVal; }
        void setNom(string nomVal){ nom = nomVal; }
        void setPrenom(string prenomVal){ prenom = prenomVal; }
        void setCIN(string cinnVal){ cinn = cinnVal; }
        void setEmail(string emailVal){ email = emailVal; }
        void setPassword(string passwordVal){ password = passwordVal; }
        void setTlf(string tlfVal){ tlf = tlfVal; }
        void setDateNaissance(DatePerso dateVal){ date_naissance = dateVal; }

};

#endif // PERSONNE_H_INCLUDED
