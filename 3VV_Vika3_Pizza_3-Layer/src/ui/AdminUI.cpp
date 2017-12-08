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
    displayPriceCategory();
    do {
        cout << "Add a PriceCategory:" << endl;
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
            string nameinput;
            int prizeinput;
            bool valid;
            Topping* listi = dataBase.toppingMaster;
            cout << "Sacues in current list: " << endl;
            for (int i = 0; i < adminService.repo.getToppingLines(); i++) {
                cout << listi[i].getIdNumber();
                cout << ")\t" << listi[i].getName();
                cout << "\t|" << listi[i].getPriceCategory();
                cout <<endl;
            }
            do{
            cout << "\nEnter name of new topping: ";
            cin >>nameinput;
            valid = adminService.validateName(nameinput);
            }while(!valid);
            do{
                cout <<"\nEnter prize catagory for new topping: ";
                cin >>prizeinput;
                valid = adminService.validatePriceCategory(prizeinput);
            }while(!valid);
                /// prenta út lista af sósum nú þegar í lista. (sem að hann nær í úr admin service, sem að nær sjálfur í listann úr database);
                /// cin'a nafn á sósu
                /// validate'a nafn í service
                /// cin'a integer og validate'a
                /// adda ef allt er valid þá senda sósuna í listann hérna
            adminService.addToppings(nameinput, prizeinput);
        }
    }
}
void AdminUI::addToppings() {

}
void AdminUI::displayToppings() {

}
void AdminUI::editToppings() {

}
void AdminUI::removeToppings() {

}

/// Extras
void AdminUI::extraOptions() {

}
void AdminUI::displayExtras() {

}
void AdminUI::addExtras() {

}
void AdminUI::editExtras() {

}
void AdminUI::removeExtras() {

}

/// Size
void AdminUI::sizeOptions() {

}
void AdminUI::displaySizes() {

}
void AdminUI::addSize() {

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
        cout << "3)\t" << "Display a sauce" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addSauces();
        }
        if (c == '2') {

        }
        if (c == '3') {
            displaySauces();
        }
    }
    system("CLS");
}
void AdminUI::displaySauces() {
    dataBase.refreshSauce();
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
    string nameInput;
    int priceInput;
    bool valid;
    displaySauces();
    do {
        cout << "Enter sauce name: ";
        cin >> ws;
        getline(cin, nameInput);
        valid = adminService.validateName(nameInput);
    } while(!valid);

    displayPriceCategory();

    do {
        cout <<"\nSelect prize category for new sauce: ";
        cin >> priceInput;
        valid = adminService.validatePriceCategory(priceInput);
    }while(!valid);
        /// prenta út lista af sósum nú þegar í lista. (sem að hann nær í úr admin service, sem að nær sjálfur í listann úr database);
        /// cin'a nafn á sósu
        /// validate'a nafn í service
        /// cin'a integer og validate'a
        /// adda ef allt er valid þá senda sósuna í listann hérna
    adminService.addSauces(nameInput, priceInput);
}
void AdminUI::editSauces() {

}
void AdminUI::removeSauces() {

}

/// Base
void AdminUI::baseOptions() {

}
void AdminUI::displayBases() {

}
void AdminUI::addBase() {

}
void AdminUI::editBase() {

}
void AdminUI::removeBase() {

}

/// Location
void AdminUI::locationOptions() {

}
void AdminUI::displayLocations() {

}
void AdminUI::addLocation() {

}
void AdminUI::editLocation() {

}
void AdminUI::removeLocation() {

}




/*
void AdminUI::addPizzas() {

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
*/
