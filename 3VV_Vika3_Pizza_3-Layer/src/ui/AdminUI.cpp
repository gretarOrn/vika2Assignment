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
    char c;
    while(c != 'q') {
        cout << "Special options" << endl;
        cout << "1)\t" << "Add a special" << endl;
        cout << "2)\t" << "Edit a special" << endl;
        cout << "3)\t" << "Display specials" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            addOrders();
        } else if (c == '2') {
            editOrders();
        } else if (c == '3') {
            displaySpecialsOrders();
        }
        system("CLS");
    }
}
void AdminUI::displayActiveOrders() {

}
void AdminUI::displayInactiveOrders() {

}
void AdminUI::displaySpecialsOrders() {

}
void AdminUI::addOrders() {

}
void AdminUI::editOrders() {

}
void AdminUI::removeOrders() {

}

/// Pizza menu
void AdminUI::pizzaOptions() {
    char c;
    while(c != 'q') {
        cout << "Pizza menu options" << endl;
        cout << "1)\t" << "Add a pizza to the menu" << endl;
        cout << "2)\t" << "Edit a pizza in the menu" << endl;
        cout << "3)\t" << "Display pizza menu" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
               if (c == '1') {
            system("CLS");
            addPizzas();
            system("CLS");
        } else if (c == '2') {
            system("CLS");
            editPizzas();
            system("CLS");
        } else if (c == '3') {
            system("CLS");
            displayPizzaMenu();
        }

    }
}
void AdminUI::displayPizzaMenu() {
    Pizza* pizzaList = dataBase.pizzaMaster;
    if(pizzaList != 0) {
        cout << "Pizzas in current menu: " << endl;
        for (int i = 0; i < adminService.repo.getPizzaLines(); i++) {
            cout << pizzaList[i].getIdNumber();
            cout << ")\t" << /* setw(pizzaList[0].MAX_PIZZA_LENGTH) << left << */ pizzaList[i].getName() << endl;
            cout << "\t  " << /* setw(pizzaList[0].getSize().MAX_STRING_LENGTH) << left << */ setw(9) << pizzaList[i].getSize().getName();
            cout << " | " << /* setw(pizzaList[0].getType().MAX_STRING_LENGTH) << left << */ pizzaList[i].getType().getName() + " base";
            cout << " | " << /* setw(pizzaList[0].getSauce().MAX_STRING_LENGTH) << left << */ pizzaList[i].getSauce().getName() + " sauce" << endl;
            cout << "\t  " << "Toppings: | ";
            for(int j = 0; j < pizzaList[0].MAX_TOPPINGS_PIZZA; j++) {
                if(pizzaList[i].getToppings()[j].getIdNumber() != 0) {
                    cout << pizzaList[i].getToppings()[j].getName() << " | ";
                }
            }
            cout << endl;
            cout << "\t  " << "Price:    | " << pizzaService.getPrice(pizzaList[i]) << "kr | Is ";
            if(pizzaList[i].getActiveState()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }

            cout << endl;
        }
    }
}
void AdminUI::addPizzas() {
    Pizza pizza;
    char userInput;
    string nameInput;
    double totalPrice = 0.0;
    int sizeSelection;
    int typeSelection;
    int sauceSelection;
    int toppingSelection[pizza.MAX_TOPPINGS_PIZZA];
    for(int i = 0; i < pizza.MAX_TOPPINGS_PIZZA; i++) {
        toppingSelection[i] = 0;
    }

        bool valid = false;
    do {
        system("CLS");
        displayPizzaMenu();
        cout << "Add a Pizza: " << endl;
        do{
            cout << "Enter pizza name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displaySizes();
        valid = false;
        do {
            cout << "Select size: ";
            cin >> sizeSelection;
            adminService.isInt(sizeSelection);
            try {
                adminService.validateSize(sizeSelection, valid);
            }
            catch(InvalidSizeException) {
                cout <<"Invalid size input" << endl;
            }

        } while(!valid);
        displayBases();
        valid = false;
        do {
            cout << "Select Base: ";
            cin >> typeSelection;
            adminService.isInt(typeSelection);
            try {
                adminService.validateType(typeSelection, valid);
            }
            catch(InvalidTypeException) {
                cout <<"Invalid type input." << endl;
            }

        } while(!valid);
        displaySauces();
        valid = false;
        do {
            cout << "Select sauce: ";
            cin >> sauceSelection;
            adminService.isInt(sauceSelection);
            try {
                adminService.validateSauce(sauceSelection, valid);
            }
            catch(InvalidSauceException) {
                cout << "Invalid sauce input." << endl;
            }
            valid = true;
        } while(!valid);
        displayToppings();
        valid = false;
        cout << endl << "Choose toppings: ";

        int counter = 0;
        int tempToppingSelection;
        cout << "Select toppings, press 0 to stop." << endl;

        while(counter < pizza.MAX_TOPPINGS_PIZZA) {
            toppingSelection[counter] = 0;
            cin >> tempToppingSelection;
            adminService.isInt(tempToppingSelection);
            if(tempToppingSelection == 0) {
                break;
            }
            try {
                adminService.validateToppingSelection(tempToppingSelection, valid);
            }
            catch(InvalidToppingException) {
                cout << "Invalid topping input." << endl;
            }
               toppingSelection[counter] = tempToppingSelection;
               counter++;
        }
        for(int i = 0; i < 10; i++) {
            cout << toppingSelection[i] << " ";
        }
        adminService.addPizza(nameInput, sizeSelection, typeSelection, sauceSelection, toppingSelection, totalPrice);
        dataBase.refreshPizza();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
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
        cout << "Price options" << endl;
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
            cout << ")\t" << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[i].getName();
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
    bool valid = false;
    do {
        system("CLS");
        displayPriceCategory();
        cout << "Add a price category:" << endl;

          do{
            cout << "Enter prize category name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        valid = false;
        do{
            cout << "\nEnter category price:    ";
            cin >> PriceInput;
            adminService.isDouble(PriceInput);
            try {
                adminService.validatePriceCategory(PriceInput,valid);
            }
            catch(InvalidPriceException) {
                cout <<"Invalid price input." << endl;
            }
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
        cout << "Topping options" << endl;
        cout << "1)\t" << "Add a topping" << endl;
        cout << "2)\t" << "Edit a topping" << endl;
        cout << "3)\t" << "Display a toppings" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            addToppings();
        } else if (c == '2') {
            editToppings();
        } else if (c == '3') {
            displayToppings();
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
            cout << ")\t" << setw(toppingList[0].MAX_STRING_LENGTH) << left << toppingList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[toppingList[i].getPriceCategory()-1].getName();
            cout << " | " << setw(4) << right << (priceList[toppingList[i].getPriceCategory()-1].getPrice() * dataBase.sizeMaster[0].getToppingMult()) + dataBase.sizeMaster[0].getToppingOffset() << "kr | ";
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
    bool valid = false;
    do {
        system("CLS");
        displayToppings();
        cout << "Add a topping: " << endl;
        do{
            cout << "Enter topping name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        valid = false;
        do{
            cout << "\nEnter category price:    ";
            cin >> priceInput;
            adminService.isInt(priceInput);
            try {
                adminService.validateTopping(priceInput,valid);
            }
            catch(InvalidToppingException) {
                cout <<"Invalid price input." << endl;
            }
        } while(!valid);
        adminService.addTopping(nameInput, priceInput);
        dataBase.refreshTopping();
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    system("CLS");
}
void AdminUI::editToppings() {
/*
    int userInput;
    char userInput2;
    string newNameInput;
    int newPriceInput;
    bool newStateInput;
    bool valid;
    Topping* toppingList = dataBase.toppingMaster;
    displayToppings();

    do {
        cout << "Select topping: ";
        cin >> userInput;
        //valid = adminService.validateSelection();
        valid = true;
    } while(!valid);
    do{
        cout << "Enter new topping name: ";
        cin >> ws;
        getline(cin, newNameInput);
        valid = adminService.validateName(newNameInput);
    } while(!valid);
    displayPriceCategory();
    do {
        cout << "Select a new price category: ";
        cin >> newPriceInput;
        valid = adminService.validatePriceCategory(newPriceInput);
    } while(!valid);
    while(true) {
        cout << "Is active? (y/n) ";
        cin >> userInput2;
        if(userInput2 == 'y' || userInput2 == 'Y') {
            newStateInput = true;
            break;
        } else if(userInput2 == 'n' || userInput2 == 'N') {
            newStateInput = false;
            break;
        }
    }
//    adminService.editTopping((toppingList[userInput - 1].getIdNumber()), newNameInput, newPriceInput, newStateInput);
    dataBase.refreshTopping();
    system("CLS");
*/
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
            cout << ")\t" << setw(extraList[0].MAX_STRING_LENGTH) << left << extraList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[extraList[i].getPriceCategory()-1].getName();
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
    bool valid = false;
    do {
        system("CLS");
        displayExtras();
        cout << "Add an extra: " << endl;
        do{
            cout << "Enter extra name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
        valid = false;
        do{
            cout << "\nEnter category price:    ";
            cin >> priceInput;
            adminService.isInt(priceInput);
            try {
                adminService.validateExtra(priceInput,valid);
            }
            catch(InvalidExtraException) {
                cout <<"Invalid price input." << endl;
            }
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
        cout << "Sizes in current list: " << endl;
        for (int i = 0; i < adminService.repo.getSizeLines(); i++) {
            cout << sizeList[i].getIdNumber();
            cout << ")\t" << setw(sizeList[0].MAX_STRING_LENGTH) << left << sizeList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sizeList[i].getPriceCategory()-1].getName();
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
    double toppingMult;
    double toppingOffset;
    bool valid = false;
    do {
        system("CLS");
        displaySizes();
        cout << "Add a pizza size: " << endl;
        do{
            cout << "Enter size name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        displayPriceCategory();
       valid = false;
        do{
            cout << "\nEnter category price:    ";
            cin >> priceInput;
            adminService.isInt(priceInput);
            try {
                adminService.validateSize(priceInput,valid);
            }
            catch(InvalidSizeException) {
                cout <<"Invalid price input." << endl;
            }
        } while(!valid);
        valid = false;
        do {
            cout << "Enter topping price Multiplier: ";
            cin >> toppingMult;
            adminService.isDouble(toppingMult);
            try {
                adminService.validateMult(toppingMult, valid);
            }
            catch(InvalidMultException) {
                cout <<"Invalid multiplier input." << endl;
            }

        } while(!valid);
        valid = false;
        do {
            cout << "Enter topping price offset: ";
            cin >> toppingOffset;
            adminService.isDouble(toppingOffset);
            try {
                adminService.validatePrice(toppingOffset, valid);
            }
            catch(InvalidOffsetException) {
                cout << "Invalid Offset input." << endl;
            }

        } while(!valid);
        adminService.addSize(nameInput, priceInput, toppingMult, toppingOffset);
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
            cout << ")\t" << setw(sauceList[0].MAX_STRING_LENGTH) << left << sauceList[i].getName();
            cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sauceList[i].getPriceCategory()-1].getName();
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
    bool valid = false;
    do {
        system("CLS");
        displaySauces();
        cout << "Add a sauce: " << endl;
        do {
            cout << "Enter sauce name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);

        displayPriceCategory();

       valid = false;
        do{
            cout << "\nEnter category price:    ";
            cin >> priceInput;
            adminService.isInt(priceInput);
            try {
                adminService.validateSauce(priceInput,valid);
            }
            catch(InvalidSauceException) {
                cout <<"Invalid price input." << endl;
            }
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
    if(typeList != 0) {
        cout << "Bases in current list: " << endl;
        for (int i = 0; i < adminService.repo.getTypeLines(); i++) {
            cout << typeList[i].getIdNumber();
            cout << ")\t" << setw(typeList[0].MAX_STRING_LENGTH) << left << typeList[i].getName();
            cout << " | " << setw(4) << right << typeList[i].getPriceOffset() << "kr | ";
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
    double priceInput;
    bool valid = false;
    do {
        system("CLS");
        displayBases();
        cout << "Add a pizza base: " << endl;
        do {
            cout << "Enter base name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        valid = false;
        do {
            cout <<"Enter a price offset: ";
            cin >> priceInput;
            adminService.isDouble(priceInput);
            try {
                adminService.validatePrice(priceInput, valid);
            }
            catch(InvalidOffsetException) {
                cout << "Invalid offset." << endl;
            }

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
        cout << "Locations in current list: " << endl;
        for (int i = 0; i < adminService.repo.getLocationLines(); i++) {
            cout << locList[i].getIdNumber();
            cout << ")\t" << setw(locList[0].MAX_STRING_LENGTH) << left << locList[i].getName();
            cout << " | " << setw(locList[0].MAX_ADDRESS_LENGTH) << left << locList[i].getAddress();
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
    bool valid = false;
    do {
        system("CLS");
        displayLocations();
        cout << "Add a location: " << endl;
        do {
            cout << "Enter location name: ";
            cin >> ws;
            getline(cin, nameInput);
            try {
                adminService.validateName(nameInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid name input." << endl;
            }
        } while(!valid);
        valid = false;
        do {
            cout << "Enter address: ";
            cin >> ws;
            getline(cin, addressInput);
            try {
                adminService.validateName(addressInput,valid);
            }
            catch(InvalidNameException) {
                cout <<"Invalid address input." << endl;
            }
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
