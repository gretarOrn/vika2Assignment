#include "AdminService.h"

AdminService::AdminService()
{
    //ctor
}

AdminService::~AdminService()
{
    //dtor
}

void AdminService::addSauces() {
    ofstream fout;

    PizzaSauce sauce;

    sauce.displaySauce();

    char userInput;

    do {
        userInput = 'n';
        cout << "Add a sauce: " << endl;
        cin >> sauce;
        fout << sauce;
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}

void AdminService::addToppings() {
    ofstream fout;

    SuperRepo repo;
    Topping topping;

    int toppingMasterSize = repo.getToppingLines();
    Topping* toppingMaster = repo.readToppingFile();

    for(int i = 0; i < toppingMasterSize; i++) {
        cout << toppingMaster[i];
    }

    char userInput;

    do {
        userInput = 'n';
        cout << "Add a topping: " << endl;
        cin >> topping;
        //fout << topping;
        repo.writeToToppingFile(topping);
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}

void AdminService::addPizzas() {
    /*
    ofstream fout;

    Pizza pizza;

    int pizzaMasterSize = pizza.getLines();
    Pizza* pizzaMaster = pizza.readPizzaMenu();

    for(int i = 0; i < pizzaMasterSize; i++) {
         cout << pizzaMaster[i];
    }

    char userInput;

    do {
        userInput = 'n';
        cout << "Add an Pizza to the menu: " << endl;
        cin >> pizza;
        fout << pizza;
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    */
}

void AdminService::addExtras() {
    ofstream fout;

    Extra extra;

    int extraMasterSize = extra.getLines();
    Extra* extraMaster = extra.readFile();

    for(int i = 0; i < extraMasterSize; i++) {
        cout << (i + 1) << ")" << extraMaster[i];
    }

    char userInput;

    do {
        userInput = 'n';
        cout << "Add an extra: " << endl;
        cin >> extra;
        fout << extra;
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
