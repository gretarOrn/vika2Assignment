#ifndef VALIDATESERVICE_H
#define VALIDATESERVICE_H

#include "DataBase.h"
#include "InvalidLocationException.h"

class ValidateService
{
    public:
        ValidateService();
        void validateLocationID(int ID);

    private:
        DataBase dataBase;
};

#endif // VALIDATESERVICE_H
