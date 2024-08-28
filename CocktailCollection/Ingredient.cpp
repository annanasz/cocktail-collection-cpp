#include "Ingredient.h"

std::ostream &Ingredient::print(std::ostream &os) {
    os << "\n" << name << "\n" << unit << "\n" << price;
    return os;
}

std::ostream &Ingredient::printonscreen(std::ostream &os) {
    os << name <<":";
    return os;
}

std::istream &Ingredient::configure(std::istream &f) {
    String n, u;
    double p;
    f >> n;
    f >> u;
    f >> p;
    name = n;
    unit = u;
    price = p;
    return f;
}

void Ingredient::configure() {
    String n, u;
    double p;
    std::cout << "Give me the NAME of the ingredient:";
    std::cin >> n;
    std::cout << "Give me the UNIT of the ingredient:";
    std::cin >> u;
    std::cout << "Give me the PRICE of the ingredient:";
    std::cin >> p;
    name = n;
    unit = u;
    price = p;
    return;
}