#include "ChambrePatient.h"

ChambrePatient::ChambrePatient(int id,int floor,bool Visited ):Chambre(id,floor){
    IsVisited=Visited;
}
