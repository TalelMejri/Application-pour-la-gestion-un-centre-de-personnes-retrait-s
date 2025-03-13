#include "ChambreMultiple.h"
#include <iostream>
using namespace std;

ChambreMultiple::ChambreMultiple(int id, string type, bool occupied) :
                ChambrePatient(id), ChambrePersonnel(id), isOccupiedByPatient(occupied) {}


