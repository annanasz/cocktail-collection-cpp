#include "AlcoholicDrink.h"

std::ostream &AlcoholicDrink::print(std::ostream &os) {
    os << "\na";
    Ingredient::print(os);
    os << "\n" << alcoholVol;
    return os;
}

std::ostream &AlcoholicDrink::printonscreen(std::ostream &os) {
    Ingredient::printonscreen(os);
    os << " alcohol vol: " << alcoholVol << "%,";
    return os;
}

std::istream &AlcoholicDrink::configure(std::istream &f) {
    Ingredient::configure(f);
    double v;
    f >> v;
    alcoholVol = v;
    return f;
}

void AlcoholicDrink::configure() {
    Ingredient::configure();
    std::cout << "Give me the ALCOHOL VOL:";
    double a;
    std::cin >> a;
    alcoholVol = a;
}