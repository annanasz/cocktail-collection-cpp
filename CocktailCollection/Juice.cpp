#include <fstream>
#include "Juice.h"

std::ostream &Juice::print(std::ostream &os) {
    os << "\nj";
    Ingredient::print(os);
    os << "\n" << concentration;
    return os;
}

std::ostream &Juice::printonscreen(std::ostream &os) {
    Ingredient::printonscreen(os);
    os << " concentration: " << concentration << "%,";
    return os;
}

std::istream &Juice::configure(std::istream &f) {
    Ingredient::configure(f);
    double c;
    f >> c;
    concentration = c;
    return f;
}

void Juice::configure() {
    Ingredient::configure();
    std::cout << "Give me the CONCENTRATION of the ingredient:";
    double c;
    std::cin >> c;
    concentration = c;
}
