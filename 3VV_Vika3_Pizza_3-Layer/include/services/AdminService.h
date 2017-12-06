#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "SuperRepo.h"

class AdminService
{
    public:
        AdminService();
        virtual ~AdminService();

        void addSauces();
        void addToppings();
        void addPizzas();
        void addExtras();

    private:

};

#endif // ADMINSERVICE_H
