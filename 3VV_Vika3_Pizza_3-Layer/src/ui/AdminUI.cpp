#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

AdminUI::~AdminUI()
{
    //dtor
}

void AdminUI::startUp() {
    char c;

    while(c != 'q') {
        cout << "type 1 to add size" << endl;
        cout << "type 2 to add sauce" << endl;
        cout << "type 3 to add topping" << endl;
        cout << "type 4 to add pizza to menu" << endl;
        cout << "type 5 to add extras" << endl;
        cout << "type 6 to add price" << endl;
        cout << "type 7 to add location" << endl;
        cout << "type q to add quit" << endl;

        cin >> c;
        if (c == '1') {

        }
        if (c == '2') {
            addSauces();
        }
        if (c == '3') {
            addToppings();
        }
        if (c == '4') {
            addPizzas();
        }
        if (c == '5') {
            addExtras();
        }
        if (c == '6') {

        }
        if (c == '7') {

        }
    }
}

void AdminUI::addSauces() {
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

void AdminUI::addToppings() {
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

void AdminUI::addPizzas() {
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

void AdminUI::addExtras() {
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
