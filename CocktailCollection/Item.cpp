#include "Item.h"
#include "AlcoholicDrink.h"
#include "Garnish.h"
#include "Juice.h"

std::ostream &Item::print(std::ostream &os) {
    pIngredient->print(os);
    os << "\n" << quantity;
    return os;
}

std::ostream &Item::printonscreen(std::ostream &os) {
    pIngredient->printonscreen(os);
    os << " quantity:" << quantity << " " << pIngredient->getunit();
    return os;
}

std::istream &Item::configure(std::istream &f, Ingredient *ing) {
    double m;
    f >> m;
    quantity = m;
    pIngredient = ing;
    return f;
}

void Item::configure() {
    std::cout << "\nWhat kind of ingredient is this?\n"
                 "a - Alcoholic Drink\n"
                 "j - Juice\n"
                 "g - Garnish\n"
                 "Your answer:";
    char ch;
    std::cin >> ch;
    Ingredient *ing;
    switch (ch) {
        case 'a':
            ing = new AlcoholicDrink;
            break;
        case 'j':
            ing = new Juice;
            break;
        case 'g':
            ing = new Garnish;
            break;
        default:
            throw std::runtime_error("You chose an invalid option, adding the ingredient failed");
    }
    ing->configure();
    pIngredient = ing;
    std::cout << "How many do you need from this ingredient?:";
    double a;
    std::cin >> a;
    quantity = a;
}

bool Item::filterbyingredient(String &a) {
    if (pIngredient->getname() == a)
        return true;
    return false;
}