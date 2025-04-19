#include "ChambreMultiple.h"
#include <iostream>
using namespace std;

ChambreMultiple::ChambreMultiple(int id, int floor,bool visit,bool mat, bool occupied) :
                ChambrePatient(id,floor,visit), ChambrePersonnel(id,floor,mat){
                    isOccupiedByPatient=occupied;
    }


  void ChambreMultiple::afficherChambreMultiple() {
        ChambrePatient::afficherChambre();
        if (isOccupiedByPatient) {
            cout << "Cette chambre est occupée par un patient." << endl;
        } else {
            cout << "Cette chambre est libre." << endl;
        }
    }


