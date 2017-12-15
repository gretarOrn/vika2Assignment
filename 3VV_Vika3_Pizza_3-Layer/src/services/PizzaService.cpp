#include "PizzaService.h"

PizzaService::PizzaService() {
    //ctor
}

Pizza PizzaService::createPizza(int sizeSelction, int typeSelction, int sauceSelction, int toppingSelction[]) {
    Pizza pizza;
    pizza.setSize(dataBase.sizeMaster[sizeSelction - 1]);
    pizza.setType(dataBase.typeMaster[typeSelction - 1]);
    pizza.setSauce(dataBase.sauceMaster[sauceSelction - 1]);

    for (int i = 0; toppingSelction[i] != 0; i++) {
        pizza.getToppings()[i] = dataBase.toppingMaster[toppingSelction[i] - 1];
    }
    return pizza;
}

double PizzaService::getPrice(Pizza pizza) {
    PriceList* priceList = dataBase.priceMaster;
    if(pizza.getTotalPrice() == 0.0) {
        double num = 0;
        double mult = pizza.getSize().getToppingMult();
        double off = pizza.getSize().getToppingOffset();
        for (int i = 0; pizza.getToppings()[i].getName() != ""; i++) {
            num += priceList[pizza.getToppings()[i].getPriceCategory()-1].getPrice() * mult + off;
        }
        num += priceList[pizza.getSize().getPriceCategory() - 1].getPrice();
        num += pizza.getType().getPriceOffset() * mult;

        return  num;
    } else {
        return pizza.getTotalPrice();
    }
}


