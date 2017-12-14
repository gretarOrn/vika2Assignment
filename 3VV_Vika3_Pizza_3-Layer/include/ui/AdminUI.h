#ifndef ADMINUI_H
#define ADMINUI_H

#include "DataBase.h"
#include "AdminService.h"
<<<<<<< HEAD

#include "ValidateService.h"

#include "PizzaService.h"
=======
#include "PizzaService.h"
#include "ValidateService.h"
>>>>>>> c64e225b4932874fe5e069fa1e72ee8dafa64ad9

#include <iostream>
#include <cstdlib>

class AdminUI
{
    public:
        AdminUI();
        void startUp();

    private:
<<<<<<< HEAD
=======
<<<<<<< HEAD
        AdminService adminService;
        PizzaService pizzaService;
        DataBase dataBase;
        ValidateService validate;

=======
        DataBase dataBase;
>>>>>>> 49bfc3e00dd137b0d642feddb8ee4362bba9e9e2
        AdminService adminService;
        DataBase dataBase;
        PizzaService pizzaService;
        ValidateService validate;

<<<<<<< HEAD
=======


>>>>>>> c64e225b4932874fe5e069fa1e72ee8dafa64ad9
>>>>>>> 49bfc3e00dd137b0d642feddb8ee4362bba9e9e2
        /// Specials
        void orderOptions();
        void displayActiveOrders();
        void displayInactiveOrders();
        void displaySpecialsOrders();
        void addOrders();
        void editOrders();
        void removeOrders();

        /// Pizza menu
        void pizzaOptions();
        void displayPizzaMenu();
        void addPizzas();
        void editPizzas();
        void removePizzas();

        /// Price Category
        void PriceOptions();
        void displayPriceCategory();
        void addPriceCategory();
        void editPriceCategory();
        void removePriceCategory();

        /// Topping
        void toppingOptions();
        void displayToppings();
        void addToppings();
        void editToppings();
        void removeToppings();

        /// Extras
        void extraOptions();
        void displayExtras();
        void addExtras();
        void editExtras();
        void removeExtras();

        /// Size
        void sizeOptions();
        void displaySizes();
        void addSize();
        void editSize();
        void removeSize();

        /// Sauce
        void sauceOptions();
        void displaySauces();
        void addSauces();
        void editSauces();
        void removeSauces();

        /// Base
        void baseOptions();
        void displayBases();
        void addBase();
        void editBase();
        void removeBase();

        /// Location
        void locationOptions();
        void displayLocations();
        void addLocation();
        void editLocation();
        void removeLocation();
};

#endif // ADMINUI_H
