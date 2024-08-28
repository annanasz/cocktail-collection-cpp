#ifndef COCKTAIL_H_INCLUDED
#define COCKTAIL_H_INCLUDED

#include "string5.h"
#include "Item.h"

//Egy recept hozzávalóit és azok mennyiségét (Item) eltároló osztály
class Cocktail {
    String name;
    size_t nItem;
    Item **items;
public:
    /*
     * Konstruktor, ami a paramétereiben megadott értékekkel inicializálja a objektumot, dinamikusan foglal helyet a hozzávalók tömbjének,
     * amely méretét meg lehet adni az n változóban.
     */
    Cocktail(String &name, size_t n) : name(name), nItem(0), items(new Item *[n]) {}

    Cocktail() {}

    /*
     *  Kiírja a megadott kimenetre az objektum adatait (fáljba való visszaírásnál írásnál használom)
     *  Visszatérési értéke a kimenet stream, a fejlécben meg kell adni a kimenetet, ahova írni szeretnénk
     */
    std::ostream &print(std::ostream &os);

    //Tagfüggvény, amely visszaadja a recept nevét, pl. "Cuba libre"
    String getname() { return name; }

    /*
     *  Kiírja a megadott kimenetre a receptek hozzávalóit sorban, és a hozzá tartozó mennyiségeket
     */
    std::ostream &list(std::ostream &);

    /*
     * A függvény kiszámolja a koktél árát, a megadott mennyiségek és a hozzávalók ára alapján
     * Visszatérési értéke a kiszámolt ár
     */
    double price();

    //Megadja, hogy alkoholos vagy alkoholmentes a koktél
    bool isAlcoholic();

    /*
     * Visszatérési értékében megadja, hogy a függvény fejlécében megadott nevű koktélrecept hányadik indexen szerepel a tömbben,
     * ha nincsen benne a visszatérési érték -1
     */
    int indx(String &a);

    /*
     * A függvény megkeresi és kitörli a megadott nevű hozzávalót, ha benne van az adatbázisban.
     */
    void remove(String &a);

    /*
     * Megnézi, hogy a fejlécben megadott nevű hozzávaló megtalálható-e a koktélban, ha igen igazzal tér vissza, ellenkező esetben hamissal
     * A hozzávalók alapján való szűréshez használom
     */
    bool filterbyingredient(String &);

    /*
     * Egy recepthez ennek a segítségével tudunk hozzávalót hozzáadni, de csak olyant, aminek már le van foglalva a hely dinamikusan
     * Leginkább a fájlból kiolvasásnál használom, mert ott egyben foglalom a memóriát, nem egyenként, mert az feleslegesen lassítaná a programot,
     * hiszen úgy is tudom előre, hogy mennyi hozzávalója lesz a koktélnak a fájlból, ezért a konstruktor foglal memóriát.
     * A fejlécben meg kell adni a hozzávalóra mutató pointert.
     */
    void add(Item *);

    /*
     * Egy recepthez ennek a segítségével tudunk hozzávalót hozzáadni, aminek nincs lefoglalva még helye a tömbben
     * Jellemzően akkor használódik ez a függvény, amikor a felhasználó ad hozzá új alapanyagot egy már meglévő recepthez
     */
    void addItem();

    /*
     * Destruktor - felszabadítja a dinamikusan foglalt memóriát
     */
    virtual ~Cocktail() {
        for (size_t i = 0; i < nItem; i++) { delete items[i]; }
        delete[] items;
    }
};

#endif // COCKTAIL_H_INCLUDED
