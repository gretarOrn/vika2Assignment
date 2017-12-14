#include "MainUI.h"

MainUI::MainUI() {
    //ctor
}

void MainUI::startUI() {
    char c;
    while (c != 'q') {
        system("CLS");
        cout << " ____                    "   << endl;
        cout << "/    \\		          "   << "\t" << "            88                                 " << endl;
        cout << "  u  u|      _______     "   << "\t" << "                                               " << endl;
        cout << "    \\ |  .-#%&#&%#%&`-. "   << "\t" << "8b,dPPYba,  88 888888888 888888888 ,adPPYYba,  " << endl;
        cout << "   = /  ((%&#&#&%&#&&%&))"   << "\t" << "88P'    \"8a 88      a8P\"      a8P\" \"\"     `Y8  " << endl;
        cout << "    |    `-._#%&##&%_.-' "   << "\t" << "88       d8 88   ,d8P'     ,d8P'   ,adPPPPP88  " << endl;
        cout << " /\\/\\`--.   `-."".-'     " << "\t\t" << "88b,   ,a8\" 88 ,d8\"      ,d8\"      88,    ,88  " << endl;
        cout << " |  |    \\   /`./        "  << "\t" << "88`YbbdP\"'  88 888888888 888888888 `\"8bbdP\"Y8  " << endl;
        cout << " |\\/|  \\  `-'  /         " << "\t" << "88                                             " << endl;
        cout << " || |   \\     /          "  << "\t" << "88                                             " << endl;
        cout  << endl;
        cout << "Please select a branch:" << endl;
        cout << "1)\t" << "Administration" << endl;
        cout << "2)\t" << "Sales" << endl;
        cout << "3)\t" << "Baking" << endl;
        cout << "4)\t" << "Delivery" << endl;
        cout << "5)\t" << "Exit/Quit" << endl;

        cin >> c;
        if(c == '1') {
            AdminUI adminUI;
            adminUI.startUp();
        } else if(c == '2') {
            SalesUI salesUI;
            salesUI.startUp();
        } else if(c == '3') {
            BakerUI bakerUI;
            bakerUI.startUp();
        } else if(c == '4') {
            DeliveryUI deliveryUI;
            deliveryUI.startUp();

        }
    }
    cout << endl << "Shutting down." << endl;
}
