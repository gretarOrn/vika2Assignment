#ifndef ADMINUI_H
#define ADMINUI_H

#include "DataBase.h"
#include "AdminService.h"
#include "ValidateService.h"
#include "PizzaService.h"
#include "OrderService.h"
#include <iostream>
#include <cstdlib>

class AdminUI
{
    public:
        AdminUI();
        void startUp();

    private:
        DataBase dataBase;
        AdminService adminService;
        PizzaService pizzaService;
        OrderService orderService;
        ValidateService validate;

        /// Specials
        void orderOptions();
        void displayActiveOrders();
        void displayInactiveOrders();
        //void displaySpecialsOrders();
        //void addOrders();
        //void editOrders();

        /// Pizza menu
        void pizzaOptions();
        void displayPizzaMenu();
        void addPizzas();
        //void editPizzas();

        /// Price Category
        void PriceOptions();
        void displayPriceCategory();
        void addPriceCategory();
        //void editPriceCategory();

        /// Topping
        void toppingOptions();
        void displayToppings();
        void addToppings();
        //void editToppings();

        /// Extras
        void extraOptions();
        void displayExtras();
        void addExtras();
        //void editExtras();

        /// Size
        void sizeOptions();
        void displaySizes();
        void addSize();
        //void editSize();

        /// Sauce
        void sauceOptions();
        void displaySauces();
        void addSauces();
        //void editSauces();

        /// Base
        void baseOptions();
        void displayBases();
        void addBase();
        //void editBase();

        /// Location
        void locationOptions();
        void displayLocations();
        void addLocation();
        //void editLocation();
};

#endif // ADMINUI_H
