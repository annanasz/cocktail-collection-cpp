#include "CokctailContainer.h"
#include <fstream>
#include <limits>

void CocktailContainer::filecheck(String &a) {
    std::ifstream f(a.c_str());
    size_t num;
    size_t run = 0;
    if (!(f >> num))
        throw std::invalid_argument("The file format is invalid");
    while (!f.eof()) {
        String name;
        if (!(f >> name))
            throw std::invalid_argument("The file format is invalid");
        char ch;
        size_t n;
        size_t r = 0;
        if (!(f >> n))
            throw std::invalid_argument("The file format is invalid");
        if (!(f >> ch))
            throw std::invalid_argument("The file format is invalid");
        while (ch != '/' && !f.eof()) {
            if (ch != 'a' && ch != 'j' && ch != 'g')
                throw std::invalid_argument("The file format is invalid");
            String n, u, t;
            double p, d, q;
            if (!(f >> n))
                throw std::invalid_argument("The file format is invalid");
            if (!(f >> u))
                throw std::invalid_argument("The file format is invalid");
            if (!(f >> p))
                throw std::invalid_argument("The file format is invalid");
            if (ch!='g' && !(f >> d))
                throw std::invalid_argument("The file format is invalid");
            if(ch=='g' && !(f>>t))
                throw std::invalid_argument("The file format is invalid");
            if (!(f >> q))
                throw std::invalid_argument("The file format is invalid");
            f >> ch;
            r++;
        }
        if (n != r)
            throw std::invalid_argument("The file format is invalid");
        run++;
    }
    if (run != num)
        throw std::invalid_argument("The file format is invalid");
    f.close();
}

void CocktailContainer::add(Cocktail *c) {
    cocktails[nCocktail++] = c;
}

void CocktailContainer::addingredient(String &a) {
    int ind = indx(a);
    if (ind == -1)
        return;
    else
        cocktails[ind]->addItem();
}

void CocktailContainer::import(String &a) {
    filecheck(a);
    std::ifstream f(a.c_str());
    if (!f.is_open()) {
        throw std::invalid_argument("The import failed, the file cannot be opened");
    }
    size_t num;
    f >> num;
    cocktails = new Cocktail *[num];
    while (!f.eof()) {
        String name;
        f >> name;
        char ch;
        size_t n;
        f >> n;
        f >> ch;
        Cocktail *c = new Cocktail(name, n);
        add(c);
        while (ch != '/' && !f.eof()) {
            Ingredient *imported = NULL;
            switch (ch) {
                case 'a':
                    imported = new AlcoholicDrink;
                    break;
                case 'j':
                    imported = new Juice;
                    break;
                case 'g':
                    imported = new Garnish;
                    break;
                case 'i':
                    imported = new Ingredient;
                    break;
                default:
                    break;
            }
            imported->configure(f);
            Item *impItem = new Item;
            impItem->configure(f, imported);
            cocktails[nCocktail - 1]->add(impItem);
            f >> ch;
        }
    }
    f.close();
}

void CocktailContainer::add() {
    String name;
    size_t db;
    std::cout << "What is the name of the new cocktail?:";
    std::cin >> name;
    std::cout << "How many ingredients do you have?:";
    std::cin >> db;
    if (db == 0)
        throw std::runtime_error("You cannot add this cocktail with 0 ingredients");
    Cocktail *c = new Cocktail(name, db);
    size_t i;
    for (i = 1; i <= db; i++) {
        Item *it = new Item;
        std::cout << "\n" << i << ". Ingredient:\n";
        try {
            it->configure();
            c->add(it);
        }
        catch (std::exception &s) {
            std::cout << s.what();
            i--;
            delete it;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    Cocktail **temp = new Cocktail *[nCocktail + 1];
    for (size_t j = 0; j < nCocktail; j++) {
        temp[j] = cocktails[j];
    }
    temp[nCocktail++] = c;
    delete[] cocktails;
    cocktails = temp;
}

void CocktailContainer::exp(String &file) {
    std::ofstream f(file.c_str());
    f << nCocktail;
    for (size_t i = 0; i < nCocktail; i++) {
        cocktails[i]->print(f);
        if (i != nCocktail - 1)f << "\n/";
    }
}

std::ostream &CocktailContainer::list(std::ostream &os) {
    for (size_t i = 0; i < nCocktail; i++) {
        cocktails[i]->list(os);
        os << " ";
    }
    return os;
}

void CocktailContainer::filterbyalcohol(bool a) {
    for (size_t i = 0; i < nCocktail; i++) {
        if (cocktails[i]->isAlcoholic() == a)
            cocktails[i]->list(std::cout);
    }
}

void CocktailContainer::filterbyingredient(String &ing) {
    for (size_t i = 0; i < nCocktail; i++) {
        if (cocktails[i]->filterbyingredient(ing)) {
            cocktails[i]->list(std::cout);
        }
    }
}

int CocktailContainer::indx(String &a) {
    for (int i = 0; i < (int) nCocktail; i++) {
        if (a == cocktails[i]->getname())
            return  i;
    }
    return -1;
}

void CocktailContainer::remove(String &a) {
    int ind = indx(a);
    if (ind != -1) {
        Cocktail **temp = new Cocktail *[nCocktail - 1];
        size_t i = 0, j = 0;
        while (i != nCocktail) {
            if ((int) i != ind) {
                temp[j] = cocktails[i];
                j++;
            }
            i++;
        }
        delete cocktails[ind];
        delete[] cocktails;
        cocktails = temp;
        nCocktail--;
        std::cout << "\nCocktail removed successfully!\n";
    } else {
        std::cout << "\nThis cocktail is not in the database\n";
    }
}

void CocktailContainer::searchbyname(String &a) {
    int ind = indx(a);
    if (ind == -1) {
        std::cout << "There's no cocktail named " << a;
        return;
    } else cocktails[ind]->list(std::cout);
}

void CocktailContainer::remove(String &c, String &i) {
    int ind = indx(c);
    if (ind == -1)
        return;
    cocktails[ind]->remove(i);
}