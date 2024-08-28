//
// Created by vassa on 4/19/2021.
//
#include <iostream>
#include <limits>
#include "Cocktail.h"
#include "CokctailContainer.h"

/*
 * a külonböző menüket és almenüket kiíró függvények
 */
#ifndef CPORTA
void menu() {
    std::cout << "\n1. List\n2. Add\n3. Remove\n4. Filter\n5. Search\n6. Close\nYour choice:";
}

void menu2() {
    std::cout << "\n1. Remove cocktail\n2. Remove ingredient\n3. Back\nYour choice:";
}

void menu3() {
    std::cout
            << "\n1. Filter: Alcoholic cocktails\n2. Filter: Non-alcoholic cocktails\n3. Filter by ingredient\n4. Back\nYour choice:";
}

void menu4() {
    std::cout << "\n1. Add new cocktail\n2. Add new ingredient to an existing cocktail\n3. Back\nYour choice:";
}
#endif

int main() {
    CocktailContainer a;
    String file2 = "forras.txt";
    String file3 = "Anna.txt";
    String c="Archie";
#ifdef CPORTA
    try{
        std::cout<<"Hibas a file formatuma, kivetelt dob";
        a.import(file3);
        }
        catch(std::exception &s)
    {
        std::cout<<s.what();
    }
#endif
    try {
        a.import(file2);
    }
    catch (std::exception &s) {
        std::cout << s.what();
    }
    a.addingredient(c);
    bool quit = false;
    while (!quit) {
#ifndef CPORTA
        menu();
#endif
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            choice = 0;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        int choice2 = 0;
        String cocktail, ingredient;
        bool in = true;
        switch (choice) {
            case 1:
                a.list(std::cout);
                break;
            case 2:
                while (in) {
#ifndef CPORTA
                    menu4();
#endif
                    if (!(std::cin >> choice2)) {
                        std::cin.clear();
                        choice2 = 0;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    switch (choice2) {
                        case 1:
                            try {
                                a.add();
                            }
                            catch (std::exception &s) {
                                std::cout << s.what();
                            }
                            in = false;
                            break;
                        case 2:
                            std::cout << "To which cocktail do you wanna add the ingredient?:";
                            std::cin >> cocktail;
                            a.addingredient(cocktail);
                            in = false;
                            break;
                        case 3:
                            in = false;
                            break;
                        default:
                            std::cout << "This option is invalid, please enter a number from 1 to 3!\n";
                            break;
                    }
                }
                break;
            case 3:
                while (in) {
#ifndef CPORTA
                    menu2();
#endif
                    if (!(std::cin >> choice2)) {
                        std::cin.clear();
                        choice2 = 0;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    switch (choice2) {
                        case 1:
                            std::cout << "Which cocktail would you like to remove?:";
                            std::cin >> cocktail;
                            a.remove(cocktail);
                            in = false;
                            break;
                        case 2:
                            std::cout << "From which cocktail would you like to remove the ingredient?:";
                            std::cin >> cocktail;
                            std::cout << "Which ingredient would you like to remove?:";
                            std::cin >> ingredient;
                            a.remove(cocktail, ingredient);
                            in = false;
                            break;
                        case 3:
                            in = false;
                            break;
                        default:
                            std::cout << "This option is invalid, please enter a number from 1 to 3!\n";
                            break;
                    }
                }
            case 4:
                while (in) {
#ifndef CPORTA
                    menu3();
#endif
                    if (!(std::cin >> choice2)) {
                        std::cin.clear();
                        choice2 = 0;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    switch (choice2) {
                        case 1:
                            a.filterbyalcohol(true);
                            in = false;
                            break;
                        case 2:
                            a.filterbyalcohol(false);
                            in = false;
                            break;
                        case 3:
                            std::cout << "Which ingredient do you wanna filter by?:";
                            std::cin >> ingredient;
                            a.filterbyingredient(ingredient);
                            in = false;
                            break;
                        case 4:
                            in = false;
                            break;
                        default:
                            std::cout << "This option is invalid, please enter a number from 1 to 4!\n";
                            break;
                    }
                }
                break;
            case 5:
                std::cout << "Give me a cocktail you want to find:";
                std::cin >> cocktail;
                a.searchbyname(cocktail);
                break;
            case 6:
                quit = true;
                break;
            default:
                std::cout << "This option is invalid, please enter a number from 1 to 6!\n";
                break;
        }


    }
    a.exp(file2);
    return 0;
}


