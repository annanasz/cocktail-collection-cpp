#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "Ingredient.h"

//Ebben az osztályban tárolunk el egy hozzávalót (Ingredient) és annak mennyiségét a receptben
class Item {
    Ingredient *pIngredient;
    double quantity;
public:
    /*
     * Konstruktor, ami a paramétereiben megadott értékekkel inicializálja a objektumot
     * ingredient - hozzávalóra mutató pointer
     * quantity - a hozzávaló mennyisége
     */
    Item(Ingredient *ingredient, double quantity) : pIngredient(ingredient), quantity(quantity) {}

    Item() { pIngredient = NULL; }

    /*
     * Beolvas egy bemenetről (fájlkezelésnél használom) egy hozzávalót, és beállítja annak adattagait.
     * Visszatérési érték a bemenet stream, a függvény fejlécében meg kell adni a bemenetet, ahonnan olvasni szeretnénk.
     * ing - a hozzávalóra mutató pointer, ami belekerül az Item-be
     */
    std::istream &configure(std::istream &f, Ingredient *ing);

    /*
    * Beolvas a billentyűzetről (konzolnál használom, a felhasználó adja meg az adatokat) egy hozzávalót, és beállítja az adattagjait
   */
    void configure();

    //Lekérdezhetjük a mennyiség privát adattagot a függvény segítségével
    double getquantity() const { return quantity; }

    //Lekérdezhetjük a tárolt hozzávaló nevét
    String &getname() {
        return pIngredient->getname();
    }

    //Az árat lekérdező tagfüggvény
    double getprice() const { return (pIngredient->getprice()) * quantity; }

    //Megmondja, hogy a tárolt ingredient objektum alkoholos-e
    bool isalcoholic() { return pIngredient->isalcoholic(); }

    /*
     * Megmondja a tagfüggvény, hogy a paraméterül kapott név egyezik-e a tárolt hozzávaló nevével
     */
    bool filterbyingredient(String &);

    /*
     *  Kiírja a megadott kimenetre az objektum adatait (fáljba való visszaírásnál írásnál használom)
     *  Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
     */
    std::ostream &print(std::ostream &);

    /*
    * Kiírja a megadott kimenetre az objektum adatait (a konzolra való kiírásnál használom)
    * Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
    */
    std::ostream &printonscreen(std::ostream &);

    //Destruktor
    ~Item() { if (pIngredient != NULL)delete pIngredient; }
};

#endif // ITEM_H_INCLUDED
