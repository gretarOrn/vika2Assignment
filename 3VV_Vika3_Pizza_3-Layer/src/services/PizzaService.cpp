#include "PizzaService.h"

PizzaService::PizzaService() {
    //ctor
}

PizzaSauce PizzaService::addSauce(int sauceNR) {
    PizzaSauce pizzaSauce;
    DataBase database;
    pizzaSauce.setIdNumber(database.sauceMaster[sauceNR - 1].getIdNumber());
    pizzaSauce.setName(database.sauceMaster[sauceNR - 1].getName());
    pizzaSauce.setPriceCategory(database.sauceMaster[sauceNR - 1].getPriceCategory());

    return pizzaSauce;

}
PizzaSize PizzaService::addSize(int sizeNR) {
    PizzaSize pizzaSize;
    DataBase database;
    pizzaSize.setIdNumber(database.sizeMaster[sizeNR - 1].getIdNumber());
    pizzaSize.setName(database.sizeMaster[sizeNR - 1].getName());
    pizzaSize.setPriceCategory(database.sizeMaster[sizeNR - 1].getPriceCategory());

    return pizzaSize;

}
PizzaType PizzaService::addType(int typeNR) {
    PizzaType pizzaType;
    DataBase database;
    pizzaType.setIdNumber(database.typeMaster[typeNR - 1].getIdNumber());
    pizzaType.setName(database.typeMaster[typeNR - 1].getName());
    pizzaType.setPriceCategory(database.typeMaster[typeNR - 1].getPriceCategory());

    return pizzaType;
}

Topping* PizzaService::addTopping(int *arr, Pizza& pizza) {
    DataBase database;
    int counter = 0;
    for (int i = 0; arr[i] != 0; i++) {
        counter ++;
    }
    for (int i = 0; arr[i] != 0; i++) {
        pizza.getToppings()[i].setIdNumber(database.toppingMaster[arr[i] - 1].getIdNumber());
        pizza.getToppings()[i].setName(database.toppingMaster[arr[i] - 1].getName());
        pizza.getToppings()[i].setPriceCategory(database.toppingMaster[arr[i] - 1].getPriceCategory());
    }
    return pizza.getToppings();


}
/*void Pizza::addSause() {

    int lines = sauce.getLines();
    PizzaSauce* sauceMaster = sauce.readFile();

    for(int i = 0; i < lines; i++) {
        if(sauceMaster[i].getActive()) {
            cout << sauceMaster[i];
        }
    }

    int userInput;
    cin >> userInput;
    sauce.setIdNumber(sauceMaster[userInput - 1].getIdNumber());
    sauce.setName(sauceMaster[userInput - 1].getName());
    sauce.setPriceCategory(sauceMaster[userInput - 1].getPriceCategory());
}
*/
//PizzaService::addTopping(topping) {

//}
