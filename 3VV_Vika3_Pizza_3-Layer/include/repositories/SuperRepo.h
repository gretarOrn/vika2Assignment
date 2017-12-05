#ifndef SUPERREPO_H
#define SUPERREPO_H

#include "Extra.h"
#include "Pizza.h"
#include "PizzaSauce.h"
#include "PizzaSize.h"
#include "Topping.h"


class SuperRepo
{
    public:
        SuperRepo();
        virtual ~SuperRepo();


        /// Topping
        int getToppingLines() const;
        Topping* readToppingFile();
        void writeToToppingFile(Topping Topping) const;

        //friend istream&  operator >> (istream& in, Topping& topping);
        //friend ostream&  operator << (ostream& out, const Topping& topping);
        friend ifstream& operator >> (ifstream& fin, Topping& topping);
        friend ofstream& operator << (ofstream& fout, const Topping& topping);

    private:
};

#endif // SUPERREPO_H
