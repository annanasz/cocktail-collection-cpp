#ifndef ALCOHOLICDRINK_H_INCLUDED
#define ALCOHOLICDRINK_H_INCLUDED

#include "Ingredient.h"

//Alkoholos hozzávalókat tároló osztály, ami az Ingredient osztály leszármazottja
class AlcoholicDrink : public Ingredient {
    double alcoholVol;
public:
    //Konstruktor, ami a paramétereiben megadott értékekkel inicializálja a objektumot
    AlcoholicDrink(String &name, double price, String &unit, double alc) : Ingredient(name, price, unit),
                                                                           alcoholVol(alc) {}

    AlcoholicDrink() : Ingredient() {}

    /*
     * Beolvas egy bemenetről (fájlkezelésnél használom) egy alkoholos hozzávalót, és beállítja annak adattagait.
     * Visszatérési érték a bemenet stream, a függvény fejlécében meg kell adni a bemenetet, ahonnan olvasni szeretnénk.
    */
    std::istream &configure(std::istream &f);

    /*
     * Beolvas a billentyűzetről (konzolnál használom, a felhasználó adja meg az adatokat) egy alkoholos hozzávalót, és beállítja az adattagjait
     */
    void configure();

    //Le lehet kérdezni az objektum alkoholtartalmát a függvénnyel.
    double getalcoholVol() const { return alcoholVol; }

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
     * Le tudjuk kérdezni, hogy a hozzávaló alkoholos-e, ebben az esetben mindig igaz a visszatérési érték, hiszen alkoholos hozzávalók osztálya.
     */
    bool isalcoholic() { return true; }

    /*
     * Destruktor
     */
    virtual ~AlcoholicDrink() {}
};

#endif // ALCOHOLICDRINK_H_INCLUDED
