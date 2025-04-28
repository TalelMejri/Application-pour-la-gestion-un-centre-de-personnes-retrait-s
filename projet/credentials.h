#ifndef CREDENTIALS_H_INCLUDED
#define CREDENTIALS_H_INCLUDED

#include <string>
using namespace std;

class credentials {
public:
    string email;
    string password;
    string role;
public:
    string VerifierEmailPassword(string , string );
    void resteConnecte(string ,string );
    credentials CheckConnecter();
    void  SaveCredentials(string ,string,string );
};

#endif // CREDENTIALS_H_INCLUDED
