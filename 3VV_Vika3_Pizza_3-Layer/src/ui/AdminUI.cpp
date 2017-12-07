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
        system("CLS");
        cout << "Please select an admin option:" << endl;
        cout << "1)\t" << "Size options" << endl;
        cout << "2)\t" << "Sauce options" << endl;
        cout << "3)\t" << "Topping options" << endl;
        cout << "4)\t" << "Pizza menu options" << endl;
        cout << "5)\t" << "Extra options" << endl;
        cout << "6)\t" << "Price category options" << endl;
        cout << "7)\t" << "Location options" << endl;
        cout << "q)\t" << "Go back" << endl;

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
            addPriceCategory();
        }
        if (c == '7') {

        }
    }
    system("CLS");
}

void AdminUI::addSauces() {
    char c;
    while(c != 'q') {
        DataBase dataBase;
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a sauce" << endl;
        cout << "2)\t" << "Edit a sauce" << endl;
        cout << "3)\t" << "\"remove a sauce\"" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            string nameinput;
            int prizeinput;
            bool valid;
            PizzaSauce* listi = dataBase.sauceMaster;
            cout <<"Sauces in current list: " << endl;
            for (int i = 0; i < adminService.sauceListSize(); i++) {
                cout << listi[i].getIdNumber();
                cout << ")\t" << listi[i].getName();
                cout << "\t|" << listi[i].getPriceCategory();
                cout <<endl;
            }
            //do{
                cout <<"\nEnter name of new sauce: ";
                cin >> nameinput;
                //valid = adminService.validateName(nameinput);
            //}while(!valid);
            do{
                cout <<"\nEnter prize catagory for new sauce: ";
                cin >>prizeinput;
                valid = adminService.validatePrizeCategory(prizeinput);
            }while(!valid);
                /// prenta út lista af sósum nú þegar í lista. (sem að hann nær í úr admin service, sem að nær sjálfur í listann úr database);
                /// cin'a nafn á sósu
                /// validate'a nafn í service
                /// cin'a integer og validate'a
                /// adda ef allt er valid þá senda sósuna í listann hérna
            adminService.addSauces(nameinput, prizeinput);
        }
        if (c == '2') {

        }
        if (c == '3') {

        }
    }
    //system("CLS");
}

void AdminUI::addToppings() {
    char c;
    while(c != 'q') {
        DataBase dataBase;
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a topping" << endl;
        cout << "2)\t" << "Edit a topping" << endl;
        cout << "3)\t" << "\"remove a topping\"" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            string nameinput;
            int prizeinput;
            bool valid;
            Topping* listi = dataBase.toppingMaster;
            cout <<"Sacues in current list: " << endl;
            for (int i = 0; i < adminService.toppingListSize(); i++) {
                cout << listi[i].getIdNumber();
                cout << ")\t" << listi[i].getName();
                cout << "\t|" << listi[i].getPriceCategory();
                cout <<endl;
            }
            do{
            cout <<"\nEnter name of new topping: ";
            cin >>nameinput;
            valid = adminService.validateName(nameinput);
            }while(!valid);
            do{
                cout <<"\nEnter prize catagory for new topping: ";
                cin >>prizeinput;
                valid = adminService.validatePrizeCategory(prizeinput);
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

void AdminUI::addPriceCategory() {
    char c;
    while(c != 'q') {
        DataBase dataBase;
        system("CLS");
        cout << "Sauce options" << endl;
        cout << "1)\t" << "Add a price category" << endl;
        cout << "2)\t" << "Edit a price category" << endl;
        cout << "3)\t" << "\"remove a price category\"" << endl;
        cout << "q)\t" << "Go back" << endl;
        cin >> c;
        if (c == '1') {
            string nameinput;
            int prizeinput;
            //bool valid;
            PriceList* priceList = dataBase.priceMaster;

            cout << "Price category in current list: " << endl;
            for (int i = 0; i < adminService.priceListSize(); i++) {
                cout << priceList[i].getIdNumber();
                cout << ")\t" << priceList[i].getName();
                cout << "\t|" << priceList[i].getPrice();
                cout <<endl;
            }


            //do{
                cout <<"\nEnter name of new price category: ";
                cin >>nameinput;
                //valid = adminService.validateName(nameinput);
            //}while(!valid);

            //do{
                cout <<"\nEnter prize catagory for new sauce: ";
                cin >> prizeinput;
            //    valid = adminService.validatePrizeCategory(prizeinput);
            //}while(!valid);
                /// prenta út lista af sósum nú þegar í lista. (sem að hann nær í úr admin service, sem að nær sjálfur í listann úr database);
                /// cin'a nafn á sósu
                /// validate'a nafn í service
                /// cin'a integer og validate'a
                /// adda ef allt er valid þá senda sósuna í listann hérna
            adminService.addPriceCategory(nameinput, prizeinput);
        }
        if (c == '2') {

        }
        if (c == '3') {

        }
    }
    system("CLS");
}
