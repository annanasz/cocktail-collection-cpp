#include "Cocktail.h"

void Cocktail::add(Item *i) {
    items[nItem++] = i;
}

double Cocktail::price() {
    double p = 0;
    for (size_t i = 0; i < nItem; i++) {
        p += items[i]->getprice();
    }
    return p;
}

std::ostream &Cocktail::list(std::ostream &os) {
    os << "\n" << name << ": " << price() << " ft\n";
    for (size_t i = 0; i < nItem; i++) {
        items[i]->printonscreen(os);
        os << "\n";
    }
    return os;
}

std::ostream &Cocktail::print(std::ostream &os) {
    os << "\n" << name << "\n" << nItem;
    for (size_t i = 0; i < nItem; i++) {
        items[i]->print(os);
    }
    return os;
}

bool Cocktail::isAlcoholic() {
    for (size_t i = 0; i < nItem; i++) {
        if (items[i]->isalcoholic())
            return true;
    }
    return false;
}

bool Cocktail::filterbyingredient(String &ing) {
    for (size_t i = 0; i < nItem; i++) {
        if (items[i]->filterbyingredient(ing))
            return true;
    }
    return false;
}

int Cocktail::indx(String &a) {
    for (int i = 0; i < (int) nItem; i++) {
        if (items[i]->filterbyingredient(a))
            return i;
    }
    return -1;
}

void Cocktail::remove(String &a) {
    int ind = indx(a);
    if (ind == -1) {
        std::cout << "There's no ingredient named \"" << a << "\" in this cocktail";
        return;
    } else {
        Item **temp = new Item *[nItem - 1];
        int i = 0, j = 0;
        while (i != (int) nItem) {
            if (i != ind) {
                temp[j] = items[i];
                j++;
            }
            i++;
        }
        delete items[ind];
        delete[] items;
        items = temp;
        nItem--;
    }
}

void Cocktail::addItem() {
    Item *n = new Item;
    n->configure();
    Item **temp = new Item *[nItem + 1];
    for (size_t i = 0; i < nItem; i++) {
        temp[i] = items[i];
    }
    temp[nItem++] = n;
    delete[] items;
    items = temp;
}
