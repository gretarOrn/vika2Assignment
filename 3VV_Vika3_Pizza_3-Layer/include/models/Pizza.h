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
        PizzaSauce getPizzaSauce() const;
        Topping* getToppings() ;

        //int getLines() const;
        //Pizza* readPizzaMenu();
        //double getPrice() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setSize(PizzaSize newSize);
        void setSause(PizzaSauce newSauce);
        void addTopping(Topping topping);
        void addToppings();

        friend istream&  operator >> (istream& in, Pizza& pizza);
        friend ostream&  operator << (ostream& out, const Pizza& pizza);
        //friend ifstream& operator >> (ifstream& fin, Pizza& pizza);
        //friend ofstream& operator << (ofstream& fout, const Pizza& pizza);

    private:


        int idNumber;
        char name[MAX_PIZZA_LENGTH];
        PizzaSize size;
        PizzaType type;
        PizzaSauce sauce;
        Topping toppings[MAX_TOPPINGS_PIZZA];

        void strToCharArr(string nameStr);
};

#endif // PIZZA_H
