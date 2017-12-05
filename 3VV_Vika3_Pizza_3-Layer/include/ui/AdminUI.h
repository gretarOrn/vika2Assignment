#ifndef ADMINUI_H
#define ADMINUI_H

#include "SuperRepo.h"
#include "Extra.h"
#include "Pizza.h"

#include <iostream>
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
        //7

    private:
};

#endif // ADMINUI_H
