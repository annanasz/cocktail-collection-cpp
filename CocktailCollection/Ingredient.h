#ifndef COCKTAILRECIPE_INGREDIENT_H
#define COCKTAILRECIPE_INGREDIENT_H

#include "string5.h"

//Az Ingredient (hozzávalók) alaposztálya
class Ingredient {
    String name;
    double price;
    String unit;
public:
    //Konstruktor, ami a paramétereiben megadott értékekkel inicializálja a objektumot
    Ingredient(String &n, double p, String &unit) : name(n), price(p), unit(unit) {}

    Ingredient() {}

    /*
   * Beolvas egy bemenetről (fájlkezelésnél használom) egy hozzávalót, és beállítja annak adattagjait.
   * Visszatérési érték a bemenet stream, a függvény fejlécében meg kell adni a bemenetet, ahonnan olvasni szeretnénk.
  */
    virtual std::istream&configure(std::istream &f);

    /*
    * Beolvas a billentyűzetről (konzolnál használom, a felhasználó adja meg az adatokat) egy hozzávalót, és beállítja az adattagjait
   */
    virtual void configure();

    //A hozzávaló nevét lekérdező getter tagfüggvény
    String &getname() { return name; }

    /*
     * Kiírja a megadott kimenetre az objektum adatait (a konzolra való kiírásnál használom)
     * Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
     */
    virtual std::ostream &printonscreen(std::ostream &os);

    /*
     *  Kiírja a megadott kimenetre az objektum adatait (fáljba való visszaírásnál írásnál használom)
     *  Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
     */
    virtual std::ostream &print(std::ostream &os);

    //A hozzávaló árát lekérdező tagfüggvény
    double getprice() const { return price; }

    //Megmondja, hogy a hozzávaló tartalmaz-e alkoholt, vagy nem
    virtual bool isalcoholic() { return false; }

    //A hozzávaló egységét lekérdező tagfüggvény
    String &getunit() { return unit; }

    //Destruktor
    virtual ~Ingredient() {}
};

#endif //COCKTAILRECIPE_INGREDIENT_H
