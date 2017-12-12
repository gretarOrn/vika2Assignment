#include "PizzaService.h"

PizzaService::PizzaService() {
    //ctor
}

PizzaSauce PizzaService::addSauce(int sauceNR) {
    PizzaSauce pizzaSauce;
    pizzaSauce.setIdNumber(dataBase.sauceMaster[sauceNR - 1].getIdNumber());
    pizzaSauce.setName(dataBase.sauceMaster[sauceNR - 1].getName());
    pizzaSauce.setPriceCategory(dataBase.sauceMaster[sauceNR - 1].getPriceCategory());
    pizzaSauce.setActiveState(dataBase.sauceMaster[sauceNR - 1].getActiveState());
    return pizzaSauce;

}
PizzaSize PizzaService::addSize(int sizeNR) {
    PizzaSize pizzaSize;
    pizzaSize.setIdNumber(dataBase.sizeMaster[sizeNR - 1].getIdNumber());
    pizzaSize.setName(dataBase.sizeMaster[sizeNR - 1].getName());
    pizzaSize.setPriceCategory(dataBase.sizeMaster[sizeNR - 1].getPriceCategory());
    //pizzaSize.setActiveState(dataBase.pizzaMaster[sizeNR - 1].getActiveState());
    return pizzaSize;

}
PizzaType PizzaService::addType(int typeNR) {
    PizzaType pizzaType;
    pizzaType.setIdNumber(dataBase.typeMaster[typeNR - 1].getIdNumber());
    pizzaType.setName(dataBase.typeMaster[typeNR - 1].getName());
    pizzaType.setPriceCategory(dataBase.typeMaster[typeNR - 1].getPriceCategory());
    pizzaType.setActiveState(dataBase.typeMaster[typeNR - 1].getActiveState());
    return pizzaType;
}

Topping* PizzaService::addTopping(int *arr, Pizza& pizza) {
    int counter = 0;
    for (int i = 0; arr[i] != 0; i++) {
        counter ++;
    }
    for (int i = 0; arr[i] != 0; i++) {
        pizza.getToppings()[i].setIdNumber(dataBase.toppingMaster[arr[i] - 1].getIdNumber());
        pizza.getToppings()[i].setName(dataBase.toppingMaster[arr[i] - 1].getName());
        pizza.getToppings()[i].setPriceCategory(dataBase.toppingMaster[arr[i] - 1].getPriceCategory());
        pizza.getToppings()[i].setActiveState(dataBase.toppingMaster[arr[i] - 1].getActiveState());
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
