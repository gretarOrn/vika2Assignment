#include "ExtraService.h"

ExtraService::ExtraService()
{
    //ctor
}

ExtraService::~ExtraService()
{
    //dtor
}
Extra ExtraService::addExtra(int extraNR) {
    Extra extra;
    DataBase database;
    extra.setIdNumber(database.extraMaster[extraNR - 1].getIdNumber());
    extra.setName(database.extraMaster[extraNR - 1].getName());
    extra.setPriceCategory(database.extraMaster[extraNR - 1].getPriceCategory());

    return extra;
}
