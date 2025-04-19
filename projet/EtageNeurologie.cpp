#include "EtageNeurologie.h"

EtageNeurologie::EtageNeurologie(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

void EtageNeurologie::afficherEtage(){
      cout << "Etage Neurologie - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}


