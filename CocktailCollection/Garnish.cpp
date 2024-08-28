#include "Garnish.h"

std::ostream &Garnish::print(std::ostream &os) {
    os << "\ng";
    Ingredient::print(os);
    os << "\n" << type;
    return os;
}

std::ostream &Garnish::printonscreen(std::ostream &os) {
    Ingredient::printonscreen(os);
    os << " type:" << type << ",";
    return os;
}

std::istream &Garnish::configure(std::istream &f) {
    Ingredient::configure(f);
    String t;
    f >> t;
    type = t;
    return f;
}

void Garnish::configure() {
    Ingredient::configure();
    String t;
    std::cout << "Give me the TYPE of the ingredient:";
    std::cin >> t;
    type = t;
}