#ifndef GARNISH_H_INCLUDED
#define GARNISH_H_INCLUDED

#include "Ingredient.h"

//Díszítőelemeket tároló osztály, az Ingredient (hozzávalók) alaposztályból származik
class Garnish : public Ingredient {
    String type;
public:
    /*
     * Konstruktor, ami inicializálja az objektumot a paramétereiben megadott értékekkel
     */
    Garnish(String &name, double price, String &unit, String &type) : Ingredient(name, price, type), type(type) {}

    Garnish() : Ingredient() {}

    /*
    * Beolvas egy bemenetről (fájlkezelésnél használom) egy díszítőelem hozzávalót, és beállítja annak adattagait.
    * Visszatérési érték a bemenet stream, a függvény fejlécében meg kell adni a bemenetet, ahonnan olvasni szeretnénk.
   */
    std::istream &configure(std::istream &f);

    /*
    * Beolvas a billentyűzetről (konzolnál használom, a felhasználó adja meg az adatokat) egy díszítőelem hozzávalót, és beállítja az adattagjait
   */
    void configure();

    //A díszítőelem típusát lekérdező tagfüggvény
    String& gettype() { return type; }

    /*
    * Kiírja a megadott kimenetre az objektum adatait (a konzolra való kiírásnál használom)
    * Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
    */
    std::ostream &printonscreen(std::ostream &os);

    /*
     *  Kiírja a megadott kimenetre az objektum adatait (fáljba való visszaírásnál írásnál használom)
     *  Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
     */
    std::ostream &print(std::ostream &os);

    /*
    * Le tudjuk kérdezni, hogy a hozzávaló alkoholos-e, ebben az esetben mindig hamis a visszatérési érték, hiszen díszítőelem hozzávalók osztálya.
    */
    bool isalcoholic() { return false; }

    /*
     * Destruktor
     */
    virtual ~Garnish() {}
};

#endif // GARNISH_H_INCLUDED
