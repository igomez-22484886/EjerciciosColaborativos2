//
// Created by Pablete on 07/10/2025.
//

#include <iostream>
#include "../include/Exercise1_StudentManagement.h"
#include "../include/Exercise2_BackpackGame.h"
#include "../include/Exercise3_AdvancedCalculator.h"
#include "../include/Exercise4_UserSystem.h"
#include <vector>

using namespace std;

void Exercise4_UserSystem::run() {
    // Genero un menú de las opciones que tiene el código, el nombre viene de Actividad Colaborativa 2
    cout << "===  System AC2 ===" << endl;

    int option;
    bool exit = false;
    while (!exit) {
        cout << "\n1. Manage Students"
                << "\n2. Digital Backpack and Game"
                << "\n3. Advanced Calculator"
                << "\n4. User System"
                << "\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            // Creo los objetos e y llamo a los demás códigos.
            case 1: {
                Exercise1_StudentManagement e1;
                e1.run();
                break;
            }
            case 2: {
                Exercise2_BackpackGame e2;
                e2.run();
                break;
            }
            case 3: {
                Exercise3_AdvancedCalculator e3;
                e3.run();
                break;
            }
            case 4: {
                cout << "\n[User System module is under development]\n";
                break;
            }
            case 5:
                exit = true;
                break;
            default:
                cout << "Invalid option!\n";
        }
    }

    cout << "Thank you for using the AC2 System." << endl;
}
