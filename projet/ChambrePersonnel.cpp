#include "ChambrePersonnel.h"

ChambrePersonnel::ChambrePersonnel(int id,int floor,bool mat ):Chambre(id,floor){
    estequipee=mat;
}
