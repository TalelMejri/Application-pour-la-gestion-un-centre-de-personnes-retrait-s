#include "credentials.h"
#include <fstream>
using namespace std;

credentials credentials::CheckConnecter() {
    credentials TestConnect;
    ifstream off("BD\\reste_connecte.txt");
    if (off.is_open() && off.peek() != ifstream::traits_type::eof()) {
        off >> TestConnect.email >> TestConnect.role;
        off.close();
    } else {
        TestConnect.email = "";
        TestConnect.role = "";
    }
    return TestConnect;
}

string credentials::VerifierEmailPassword(string email, string pass) {
    fstream f("BD\\credentials.txt");
    if (!f.is_open()) exit(-1);
    credentials c;
    while (f >> c.email >> c.password >> c.role) {
        if (c.email == email && c.password == pass) {
            f.close();
            return c.role;
        }
    }
    f.close();
    return "";
}

void credentials::SaveCredentials(string email,string pas,string role){
   ofstream off("BD\\credentials.txt", ios::app);
    if (off.is_open()) {
        off << email << " " << pas  << " "<<role << endl;
        off.close();
    }
}
