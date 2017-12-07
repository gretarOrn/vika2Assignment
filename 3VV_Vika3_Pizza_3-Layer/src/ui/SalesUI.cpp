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
    cout << "Is this working?" << endl;
    displaySizeList();
    cout << endl;
    displayTypeList();
    cout << endl;
    displaySauceList();
    cout << endl;
    displayToppingList();
    cout << endl;
    displayExtraList();
}


void SalesUI::displaySizeList() {
    cout << "Is this working?" << endl;
    PizzaSize* sizeList = data.sizeMaster;
    int length = data.getSizeID();
    for(int i = 0; i < length; i++) {
        cout << sizeList[i].getIdNumber() << ")\t"
             << setw(24) << left << sizeList[i].getName() << "\t"
             << sizeList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayTypeList() {
    cout << "Is this working?" << endl;
    PizzaType* typeList = data.typeMaster;
    int length = data.getTypeID();
    for(int i = 0; i < length; i++) {
        cout << typeList[i].getIdNumber() << ")\t"
             << setw(24) << left << typeList[i].getName() << "\t"
             << typeList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displaySauceList() {
    cout << "Is this working?" << endl;
    PizzaSauce* sauceList = data.sauceMaster;
    int length = data.getSauceID();
    for(int i = 0; i < length; i++) {
        cout << sauceList[i].getIdNumber() << ")\t"
             << setw(24) << left << sauceList[i].getName() << "\t"
             << sauceList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayToppingList() {
    cout << "Is this working?" << endl;
    Topping* toppingList = data.toppingMaster;
    int length = data.getToppingID();
    for(int i = 0; i < length; i++) {
        cout << toppingList[i].getIdNumber() << ")\t"
             << setw(24) << left << toppingList[i].getName() << "\t"
             << toppingList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayExtraList() {
    cout << "Is this working?" << endl;
    Extra* extraList = data.extraMaster;
    int length = data.getExtraID();
    for(int i = 0; i < length; i++) {
        cout << extraList[i].getIdNumber() << ")\t"
             << setw(24) << left << extraList[i].getName() << "\t"
             << extraList[i].getPriceCategory() << endl;
    }
}
