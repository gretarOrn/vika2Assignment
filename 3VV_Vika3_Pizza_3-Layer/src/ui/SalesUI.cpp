#include "SalesUI.h"

SalesUI::SalesUI()
{
    //ctor
}

void SalesUI::startUp() {
    char c;
    while (c != 'q') {
        //system("CLS");
        cout << "Sales:" << endl;
        cout << "1)\t" << "Create an order" << endl;
        cout << "2)\t" << "Edit an order" << endl;
        cout << "3)\t" << "..............." << endl;
        cout << "q)\t" << "Go back" << endl;

        cin >> c;
        if(c == '1') {
            createOrder();
        } else if(c == '2') {

        } else if(c == '3') {

        } else if(c != 'q') {

        }
    }
    system("CLS");
}

void SalesUI::createOrder() {
    Order order;
    char c;
    while (c != 'q') {
        //system("CLS");
        cout << "Sales:" << endl;
        cout << "1)\t" << "Add pizza from menu" << endl;
        cout << "2)\t" << "Create custom pizza" << endl;
        cout << "3)\t" << "Add an Extra" << endl;
        cout << "q)\t" << "Cancel order" << endl;

        cin >> c;
        if(c == '1') {
            addPizzaFromMenu(order);
        } else if(c == '2') {
            createCustomPizza(order);
        } else if(c == '3') {

        } else if(c != 'q') {

        }
    }
    system("CLS");
}

void SalesUI::addPizzaFromMenu(Order& order) {
    char c;
    int input;
    for (int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        cout << "want another extra?(y/n)" << endl;
        cin >> c;
        if (c != 'y') {
            break;
        }
        displayExtraList();
        cin >> input;
        order.getExtras()[i].addExtra(extraSer.addExtra(input));
        cout << endl;
        printExtra(order.getExtras()[i]);


    }
    orderSer.addToOrder(order);

    return;




    //displayExtraList();
}

void SalesUI::createCustomPizza(Order& order) {
    system("CLS");

    cout << "Create a pizza" << endl;
    int i = 0;
    char c;
    int input;
    do {
        displaySizeList();
        cout << "Select size: ";
        cin >> input;
        order.getPizzas()[i].setSize(pizzaSer.addSize(input));
        cout << endl;

        displayTypeList();
        cout << "Select type: ";
        cin >> input;
        order.getPizzas()[i].setType(pizzaSer.addType(input));
        cout << endl;

        displaySauceList();
        cout << "Select sauce: " << endl;
        cin >> input;
        order.getPizzas()[i].setSauce(pizzaSer.addSauce(input));
        cout << endl;

        displayToppingList();
        cout << "Select toppings (type 0 to stop)" << endl;
        int counter = 0;
        int arr[dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA];
        for (int j = 0; j < dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA; j++) {
            cin >> arr[j];
            counter ++;
            if (arr[j] == 0) break;
        }
        order.getPizzas()[i].addToppings(pizzaSer.addTopping(arr, order.getPizzas()[i]));
        cout << endl;

        printPizza(order.getPizzas()[i], counter);
        i++;
        cout << "Wanna add another pizza (y/n) " << endl;

        cin >> c;
    } while (c == 'y');

}

void SalesUI::printPizza(Pizza pizza, int counter) {
    PizzaService pizzaService;
    cout << "name: " << pizza.getName() << endl;
    cout << "size: " << pizza.getSize().getName() << endl;
    cout << "sauce: " << pizza.getSauce().getName() << endl;
    cout << "type: " << pizza.getType().getName() << endl;
    cout << "Toppings: ";
    for (int i = 0; i < (counter - 1); i++) {
        cout << pizza.getToppings()[i].getName() << " ";
    }
    cout << endl;
    cout << "Total Price of Pizza: " << pizzaService.getPrice(pizza) << endl;

    cout << endl;


}
void SalesUI::printExtra(const Extra& extra) {
    cout << "name: " << extra.getName() << endl;
    cout << "price: " << extra.getPriceCategory() << endl;
}


void SalesUI::displaySizeList() {
    PizzaSize* sizeList = dataBase.sizeMaster;
    int length = dataBase.getSizeID();
    for(int i = 0; i < length; i++) {
        cout << sizeList[i].getIdNumber() << ")\t"
             << setw(24) << left << sizeList[i].getName() << "\t"
             << sizeList[i].getPriceCategory() << endl;
    }
    cout << endl;
}

void SalesUI::displayTypeList() {
    PizzaType* typeList = dataBase.typeMaster;
    int length = dataBase.getTypeID();
    for(int i = 0; i < length; i++) {
        cout << typeList[i].getIdNumber() << ")\t"
             << setw(24) << left << typeList[i].getName() << "\t"
             << typeList[i].getPriceOffset() << endl;
    }
    cout << endl;
}

void SalesUI::displaySauceList() {
    PizzaSauce* sauceList = dataBase.sauceMaster;
    int length = dataBase.getSauceID();
    for(int i = 0; i < length; i++) {
        cout << sauceList[i].getIdNumber() << ")\t"
             << setw(24) << left << sauceList[i].getName() << "\t"
             << sauceList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayToppingList() {
    Topping* toppingList = dataBase.toppingMaster;
    int length = dataBase.getToppingID();
    for(int i = 0; i < length; i++) {
        cout << toppingList[i].getIdNumber() << ")\t"
             << setw(24) << left << toppingList[i].getName() << "\t"
             << toppingList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayExtraList() {
    Extra* extraList = dataBase.extraMaster;
    int length = dataBase.getExtraID();
    for(int i = 0; i < length; i++) {
        cout << extraList[i].getIdNumber() << ")\t"
             << setw(24) << left << extraList[i].getName() << "\t"
             << extraList[i].getPriceCategory() << endl;
    }
    cout << endl;
}
