#ifndef JUICE_H_INCLUDED
#define JUICE_H_INCLUDED

#include "Ingredient.h"

//Az Ingredient (hozzávalók) osztályából származtatott osztály, a gyümölcsleveket tárolja
class Juice : public Ingredient {
    double concentration;
public:
    /*
     * Konstruktor, ami inicializálja az objektumot a paramétereiben megadott értékekkel
     */
    Juice(String &name, double price, String &unit, double concentration) : Ingredient(name, price, unit),
                                                                            concentration(concentration) {}

    Juice() : Ingredient() {}

    /*
    * Beolvas egy bemenetről (fájlkezelésnél használom) egy gyümölcslé hozzávalót, és beállítja annak adattagait.
    * Visszatérési érték a bemenet stream, a függvény fejlécében meg kell adni a bemenetet, ahonnan olvasni szeretnénk.
   */
    std::istream &configure(std::istream &f);

    /*
    * Beolvas a billentyűzetről (konzolnál használom, a felhasználó adja meg az adatokat) egy gyümölcslé hozzávalót, és beállítja az adattagjait
   */
    void configure();

    //Gyümölcstartalmat lekérdező függvény
    double getconcentration() const { return concentration; }

    /*
    * Kiírja a megadott kimenetre az objektum adatait (a konzolra való kiírásnál használom)
    * Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
    */
    std::ostream &printonscreen(std::ostream &);

    /*
    *  Kiírja a megadott kimenetre az objektum adatait (fáljba való visszaírásnál írásnál használom)
    *  Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
    */
    std::ostream &print(std::ostream &os);

    /*
    * Le tudjuk kérdezni, hogy a hozzávaló alkoholos-e, ebben az esetben mindig hamis a visszatérési érték, hiszen gyümölcslevek osztálya.
    */
    bool isalcoholic() { return false; }

    /*
     * Destruktor
     */
    virtual ~Juice() {}
};

#endif // JUICE_H_INCLUDED
