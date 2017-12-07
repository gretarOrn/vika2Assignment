#include "AdminService.h"

AdminService::AdminService()
{
    //ctor
}

AdminService::~AdminService()
{
    //dtor
}

void AdminService::addSauces(string name, int priceCat) {
    PizzaSauce sauce;
    sauce.setName(name);
    sauce.setPriceCategory(priceCat);
    repo.writeToSauceFile(sauce);
}

void AdminService::addToppings(string name, int priceCat) {
    Topping topping;
    topping.setName(name);
    topping.setPriceCategory(priceCat);
    repo.writeToToppingFile(topping);
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
/*
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
*/
}
int AdminService::sauceListSize() {
    return repo.getSauceLines();
}
int AdminService::toppingListSize() {
    return repo.getToppingLines();
}

bool AdminService::validateName(string name) {
    for(unsigned int i = 0; i < name.size(); i++) {
        if(isalpha(name.at(i))) {
            return true;
        }
    }
    return false;
}
bool AdminService::validatePrizeCategory(int cat) {
    if(cat > 0 && cat <= dataBase.getPriceID()) {
        return true;
    }
    return false;
}
