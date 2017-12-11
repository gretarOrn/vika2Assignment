#include "Extra.h"
#include "DataBase.h"

#ifndef EXTRASERVICE_H
#define EXTRASERVICE_H


class ExtraService
{
    public:
        ExtraService();
        virtual ~ExtraService();
        Extra addExtra(int extraNR);

    protected:

    private:
};

#endif // EXTRASERVICE_H
