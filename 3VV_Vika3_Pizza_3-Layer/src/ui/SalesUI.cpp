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
            cout << "bla" << endl;
            createOrder();
        } else if(c == '2') {

        } else if(c == '3') {

        } else if(c != 'q') {

        }
    }
    system("CLS");
}

void SalesUI::createOrder() {
    system("CLS");
   // cout << "Is this working?" << endl;
  //  displaySizeList();
   // cout << endl;
 //   displayTypeList();
   // cout << endl;
    Order order;
    Pizza pizza;
    PizzaService pizzaservice;
    ExtraService extraservice;
    OrderService orderservice;
    cout << endl;
    cout << "create a pizza" << endl;
    int i = 0;
    char c;
    int input;
    do {
        displaySauceList();
        cout << "select sauce" << endl;

        cin >> input;
        order.getPizzas()[i].setSauce(pizzaservice.addSauce(input));
        cout << endl;

        displaySizeList();
        cout << "select size" << endl;
        cin >> input;
        order.getPizzas()[i].setSize(pizzaservice.addSize(input));
        cout << endl;

        displayTypeList();
        cout << "select type" << endl;
        cin >> input;
        order.getPizzas()[i].setType(pizzaservice.addType(input));
        cout << endl;

        displayToppingList();
        cout << "select toppings (type 0 to stop)" << endl;
        int counter = 0;
        int arr[pizza.MAX_TOPPINGS_PIZZA];
        for (int j = 0; j < pizza.MAX_TOPPINGS_PIZZA; j++) {
            cin >> arr[j];
            counter ++;
            if (arr[j] == 0) break;
        }
        order.getPizzas()[i].addToppings(pizzaservice.addTopping(arr, order.getPizzas()[i]));
        cout << endl;

        printPizza(order.getPizzas()[i], counter);
        i++;
        cout << "wanna add another pizza (y/n)" << endl;

        cin >> c;
    } while (c == 'y');
    for (int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        cout << "want another extra?(y/n)" << endl;
        cin >> c;
        if (c != 'y') {
            break;
        }
        displayExtraList();
        cin >> input;
        order.getExtras()[i].addExtra(extraservice.addExtra(input));
        cout << endl;
        printExtra(order.getExtras()[i]);


    }
    orderservice.addToOrder(order);

    return;




    //displayExtraList();
}
void SalesUI::printPizza(Pizza pizza, int counter) {
    cout << "name: " << pizza.getName() << endl;
    cout << "size: " << pizza.getSize().getName() << endl;
    cout << "sauce: " << pizza.getPizzaSauce().getName() << endl;
    cout << "type: " << pizza.getType().getName() << endl;
    cout << "Toppings: ";
    for (int i = 0; i < (counter - 1); i++) {
        cout << pizza.getToppings()[i].getName() << " ";
    }
    cout << endl;
    cout << endl;


}
void SalesUI::printExtra(const Extra& extra) {
    cout << "name: " << extra.getName() << endl;
    cout << "price: " << extra.getPriceCategory() << endl;
}


void SalesUI::displaySizeList() {
   // cout << "Is this working?" << endl;
    PizzaSize* sizeList = data.sizeMaster;
    int length = data.getSizeID();
    for(int i = 0; i < length; i++) {
        cout << sizeList[i].getIdNumber() << ")\t"
             << setw(24) << left << sizeList[i].getName() << "\t"
             << sizeList[i].getPriceCategory() << endl;
    }
    cout << endl;
}

void SalesUI::displayTypeList() {
 //   cout << "Is this working?" << endl;
    PizzaType* typeList = data.typeMaster;
    int length = data.getTypeID();
    for(int i = 0; i < length; i++) {
        cout << typeList[i].getIdNumber() << ")\t"
             << setw(24) << left << typeList[i].getName() << "\t"
             << typeList[i].getPriceCategory() << endl;
    }
    cout << endl;
}

void SalesUI::displaySauceList() {
 //   cout << "Is this working?" << endl;
    PizzaSauce* sauceList = data.sauceMaster;
    int length = data.getSauceID();
    for(int i = 0; i < length; i++) {
        cout << sauceList[i].getIdNumber() << ")\t"
             << setw(24) << left << sauceList[i].getName() << "\t"
             << sauceList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayToppingList() {
   // cout << "Is this working?" << endl;
    Topping* toppingList = data.toppingMaster;
    int length = data.getToppingID();
    for(int i = 0; i < length; i++) {
        cout << toppingList[i].getIdNumber() << ")\t"
             << setw(24) << left << toppingList[i].getName() << "\t"
             << toppingList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayExtraList() {
 //   cout << "Is this working?" << endl;
    Extra* extraList = data.extraMaster;
    int length = data.getExtraID();
    for(int i = 0; i < length; i++) {
        cout << extraList[i].getIdNumber() << ")\t"
             << setw(24) << left << extraList[i].getName() << "\t"
             << extraList[i].getPriceCategory() << endl;
    }
    cout << endl;
}
