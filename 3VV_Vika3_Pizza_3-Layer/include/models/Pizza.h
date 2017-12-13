#ifndef PIZZA_H
#define PIZZA_H

//#include "DataBase.h"
//#include "SuperRepo.h"

#include "Topping.h"
#include "PizzaSauce.h"
#include "PizzaSize.h"
#include "PizzaType.h"

class Pizza
{
    public:
        static const int MAX_TOPPINGS_PIZZA = 10;
        static const int MAX_PIZZA_LENGTH = 24;

        Pizza();

        int getIdNumber() const;
        string getName() const;
        PizzaSize getSize() const;
        PizzaType getType() const;
        PizzaSauce getSauce() const;
        Topping* getToppings();
        double getTotalPrice() const;
        bool getActiveState() const;
        //Topping getTopping(int index);

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setSize(const PizzaSize& newSize);
        void setType(const PizzaType& newType);
        void setSauce(const PizzaSauce& newSauce);
        void addTopping(const Topping& topping);
        void addToppings(Topping* arr);
        void setTotalPrice(double newPrice);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, Pizza& pizza);
        friend ostream&  operator << (ostream& out, const Pizza& pizza);

    private:
        int idNumber;
        char name[MAX_PIZZA_LENGTH];
        PizzaSize size;
        PizzaType type;
        PizzaSauce sauce;
        Topping toppings[MAX_TOPPINGS_PIZZA];
        double totalPrice;
        bool isActive;

        void strToCharArr(string nameStr);
};

#endif // PIZZA_H
