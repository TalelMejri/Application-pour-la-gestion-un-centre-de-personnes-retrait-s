#include "EtageCardio.h"

EtageCardio::EtageCardio(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

void EtageCardio::afficherEtage(){
      cout << "Etage Cardio - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}


