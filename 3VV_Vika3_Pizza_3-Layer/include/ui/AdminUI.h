#ifndef ADMINUI_H
#define ADMINUI_H

#include "AdminService.h"
#include "Extra.h"
#include "Pizza.h"
#include "DataBase.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;



class AdminUI
{
    public:
        AdminUI();
        virtual ~AdminUI();

        void startUp();
        //1
        void addSauces();
        void addToppings();
        void addPizzas();
        void addExtras();
        //6
        void addPriceCategory();
        //DataBase dataBase;
        AdminService adminService;

    private:
};

#endif // ADMINUI_H
