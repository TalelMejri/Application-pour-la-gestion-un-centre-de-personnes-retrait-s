#include "EtageAlzheimer.h"


EtageAlzheimer::EtageAlzheimer(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

void EtageAlzheimer::afficherEtage(){
      cout << "Etage Alzheimer - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}




