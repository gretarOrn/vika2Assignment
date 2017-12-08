#include "AdminUI.h"

AdminUI::AdminUI() {
    //ctor
}

void AdminUI::startUp() {
    char c;

    while(c != 'q') {
        system("CLS");
        cout << "Please select an admin option:" << endl;
        cout << "1)\t" << "Special menu" << endl;
        cout << "2)\t" << "Pizza menu" << endl;
        cout << "3)\t" << "Price category" << endl;
        cout << "4)\t" << "Pizza topping" << endl;
        cout << "5)\t" << "Extra" << endl;
        cout << "6)\t" << "Pizza size" << endl;
        cout << "7)\t" << "Pizza sauce" << endl;
        cout << "8)\t" << "Pizza base" << endl;
        cout << "9)\t" << "Location" << endl;
        cout << "q)\t" << "Go back" << endl;

        cin >> c;
               if (c == '1') {
            orderOptions();
        } else if (c == '2') {
            pizzaOptions();
        } else if (c == '3') {
            PriceOptions();
        } else if (c == '4') {
            toppingOptions();
        } else if (c == '5') {
            extraOptions();
        } else if (c == '6') {
            sizeOptions();
        } else if (c == '7') {
            sauceOptions();
        } else if (c == '8') {
            baseOptions();
        } else if (c == '9') {
            locationOptions();
        }
    }
    system("CLS");
}

/// Specials
void AdminUI::orderOptions() {

}
void AdminUI::displayActiveOrders() {

}
void AdminUI::displayInactiveOrders() {

}
void AdminUI::addOrders() {

}
void AdminUI::editOrders() {

}
void AdminUI::removeOrders() {

}

/// Pizza menu
void AdminUI::pizzaOptions() {

}
void AdminUI::displayPizzaMenu() {

}
void AdminUI::addPizzas() {

}
void AdminUI::editPizzas() {

}
void AdminUI::removePizzas() {

}

/// Price Category
void AdminUI::PriceOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a price category" << endl;
        cout << "2)\t" << "Edit a price category" << endl;
        cout << "3)\t" << "Display price categories" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            addPriceCategory();
        } else if (c == '2') {
            editPriceCategory();
        } else if (c == '3') {
            displayPriceCategory();
        }
    }
}
void AdminUI::displayPriceCategory() {
    dataBase.refreshPrice();
    PriceList* priceList = dataBase.priceMaster;
    if(priceList != 0) {
        cout << "Price categories in current list: " << endl;
        for (int i = 0; i < adminService.repo.getPriceLines(); i++) {
            cout << priceList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << priceList[i].getName();
            cout << " | " << setw(5) << right << priceList[i].getPrice() << "kr | ";
            if(priceList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addPriceCategory() {
    char userInput;
    string nameInput;
    double PriceInput;
    bool valid;
    do {
        system("CLS");
        displayPriceCategory();
        cout << "Add a price category:" << endl;
        do {
            cout << "Enter price category name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);

        do {
            cout << "\nEnter category price:    ";
            cin >> PriceInput;
            valid = adminService.validatePrice(PriceInput);
        } while(!valid);

        adminService.addPriceCategory(nameInput, PriceInput);

        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editPriceCategory() {

}
void AdminUI::removePriceCategory() {

}

/// Topping
void AdminUI::toppingOptions() {
    char c;
    while(c != 'q') {
        DataBase dataBase;
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a topping" << endl;
        cout << "2)\t" << "Edit a topping" << endl;
        cout << "3)\t" << "Display a toppings" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addToppings();
        }
    }
}
void AdminUI::displayToppings() {
    Topping* toppingList = dataBase.toppingMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(toppingList != 0) {
        cout << "Toppings in current list: " << endl;
        for (int i = 0; i < adminService.repo.getToppingLines(); i++) {
            cout << toppingList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << toppingList[i].getName();
            cout << " | " << setw(16) << left << priceList[toppingList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[toppingList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(toppingList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addToppings() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displayToppings();
        cout << "Add a topping: " << endl;
        do{
            cout << "Enter topping name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);
        displayPriceCategory();
        do {
            cout << "Select a price category: ";
            cin >> priceInput;
            valid = adminService.validatePriceCategory(priceInput);
        } while(!valid);
        adminService.addTopping(nameInput, priceInput);
        dataBase.refreshTopping();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editToppings() {

}
void AdminUI::removeToppings() {

}

/// Extras
void AdminUI::extraOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Extra options" << endl;
        cout << "1)\t" << "Add a extra" << endl;
        cout << "2)\t" << "Edit a extra" << endl;
        cout << "3)\t" << "Display extras" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            addExtras();
        } else if (c == '2') {
            editExtras();
        } else if (c == '3') {
            displayExtras();
        }
    }
}
void AdminUI::displayExtras() {
    Extra* extraList = dataBase.extraMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(extraList != 0) {
        cout << "Extras in current list: " << endl;
        for (int i = 0; i < adminService.repo.getExtraLines(); i++) {
            cout << extraList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << extraList[i].getName();
            cout << " | " << setw(16) << left << priceList[extraList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[extraList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(extraList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addExtras() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displayExtras();
        cout << "Add an extra: " << endl;
        do{
            cout << "Enter extra name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);
        displayPriceCategory();
        do {
            cout << "Select a price category: ";
            cin >> priceInput;
            valid = adminService.validatePriceCategory(priceInput);
        } while(!valid);
        adminService.addExtra(nameInput, priceInput);
        dataBase.refreshExtra();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editExtras() {

}
void AdminUI::removeExtras() {

}

/// Size
void AdminUI::sizeOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Size options" << endl;
        cout << "1)\t" << "Add a size" << endl;
        cout << "2)\t" << "Edit a size" << endl;
        cout << "3)\t" << "Display sizes" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            addSize();
        } else if (c == '2') {
            editSize();
        } else if (c == '3') {
            displaySizes();
        }
    }
}
void AdminUI::displaySizes() {
    PizzaSize* sizeList = dataBase.sizeMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sizeList != 0) {
        cout << "Extras in current list: " << endl;
        for (int i = 0; i < adminService.repo.getSizeLines(); i++) {
            cout << sizeList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << sizeList[i].getName();
            cout << " | " << setw(16) << left << priceList[sizeList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[sizeList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(sizeList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addSize() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displaySizes();
        cout << "Add a pizza size: " << endl;
        do{
            cout << "Enter size name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);
        displayPriceCategory();
        do {
            cout << "Select a price category: ";
            cin >> priceInput;
            valid = adminService.validatePriceCategory(priceInput);
        } while(!valid);
        adminService.addSize(nameInput, priceInput);
        dataBase.refreshSize();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editSize() {

}
void AdminUI::removeSize() {

}

/// Sauce
void AdminUI::sauceOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a sauce" << endl;
        cout << "2)\t" << "Edit a sauce" << endl;
        cout << "3)\t" << "Display sauces" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addSauces();
        } else if (c == '2') {
            editSauces();
        } else if (c == '3') {
            displaySauces();
        }
    }
    system("CLS");
}
void AdminUI::displaySauces() {
    PizzaSauce* sauceList = dataBase.sauceMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sauceList != 0) {
        cout << "Sauces in current list: " << endl;
        for (int i = 0; i < adminService.repo.getSauceLines(); i++) {
            cout << sauceList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << sauceList[i].getName();
            cout << " | " << setw(16) << left << priceList[sauceList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[sauceList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(sauceList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addSauces() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displaySauces();
        cout << "Add a sauce: " << endl;
        do {
            cout << "Enter sauce name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);

        displayPriceCategory();

        do {
            cout <<"Select price category for new sauce: ";
            cin >> priceInput;
            valid = adminService.validatePriceCategory(priceInput);
        } while(!valid);

        adminService.addSauce(nameInput, priceInput);
        dataBase.refreshSauce();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editSauces() {

}
void AdminUI::removeSauces() {

}

/// Base
void AdminUI::baseOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Pizza base options" << endl;
        cout << "1)\t" << "Add a base" << endl;
        cout << "2)\t" << "Edit a base" << endl;
        cout << "3)\t" << "Display bases" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addBase();
        } else if (c == '2') {
            editBase();
        } else if (c == '3') {
            displayBases();
        }
    }
    system("CLS");
}
void AdminUI::displayBases() {
    PizzaType* typeList = dataBase.typeMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(typeList != 0) {
        cout << "Sauces in current list: " << endl;
        for (int i = 0; i < adminService.repo.getTypeLines(); i++) {
            cout << typeList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << typeList[i].getName();
            cout << " | " << setw(16) << left << priceList[typeList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << priceList[typeList[i].getPriceCategory()-1].getPrice() << "kr | ";
            if(typeList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addBase() {
    char userInput;
    string nameInput;
    int priceInput;
    bool valid;
    do {
        system("CLS");
        displayBases();
        cout << "Add a pizza base: " << endl;
        do {
            cout << "Enter base name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);

        displayPriceCategory();

        do {
            cout <<"Select a price category: ";
            cin >> priceInput;
            valid = adminService.validatePriceCategory(priceInput);
        } while(!valid);

        adminService.addType(nameInput, priceInput);
        dataBase.refreshType();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editBase() {

}
void AdminUI::removeBase() {

}

/// Location
void AdminUI::locationOptions() {
    char c;
    while(c != 'q') {
        system("CLS");
        cout << "Location options" << endl;
        cout << "1)\t" << "Add a location" << endl;
        cout << "2)\t" << "Edit a location" << endl;
        cout << "3)\t" << "Display locations" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addLocation();
        } else if (c == '2') {
            editLocation();
        } else if (c == '3') {
            displayLocations();
        }
    }
    system("CLS");
}
void AdminUI::displayLocations() {
    Location* locList = dataBase.locationMaster;
    if(locList != 0) {
        cout << "Sauces in current list: " << endl;
        for (int i = 0; i < adminService.repo.getLocationLines(); i++) {
            cout << locList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << locList[i].getName();
            cout << " | " << setw(24) << left << locList[i].getAddress();
            cout << " | ";
            if(locList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << endl;
        }
    }
}
void AdminUI::addLocation() {
    char userInput;
    string nameInput;
    string addressInput;
    bool valid;
    do {
        system("CLS");
        displayLocations();
        cout << "Add a location: " << endl;
        do {
            cout << "Enter location name: ";
            cin >> ws;
            getline(cin, nameInput);
            valid = adminService.validateName(nameInput);
        } while(!valid);
        do {
            cout << "Enter address: ";
            cin >> ws;
            getline(cin, addressInput);
            valid = adminService.validateName(addressInput);
        } while(!valid);

        adminService.addLocation(nameInput, addressInput);
        dataBase.refreshLocation();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
}
void AdminUI::editLocation() {

}
void AdminUI::removeLocation() {

}
