#include "ValidateService.h"

ValidateService::ValidateService()
{
    //ctor
}

void ValidateService::validateLocationID(int ID) {
    if(ID > dataBase.getLocationID()) {
        throw(InvalidLocationException());
    }
}
