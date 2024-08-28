#ifndef COKCTAILCONTAINER_H_INCLUDED
#define COKCTAILCONTAINER_H_INCLUDED

#include "string5.h"
#include "Cocktail.h"
#include "Ingredient.h"
#include "Juice.h"
#include "AlcoholicDrink.h"
#include "Garnish.h"
#include "memtrace.h"

//Az adatbázist, a recepteket tároló osztály
class CocktailContainer{
size_t nCocktail;
Cocktail **cocktails;
public:
    /*
     * Konstruktor
     */
    CocktailContainer():nCocktail(0), cocktails(NULL)
    {}
    /*
     * Függvény, amely mielőtt importálnánk a file-t, leellenőrzi a fájl formátumát, ha nem helyes akkor nem importál a program.
     */
    static void filecheck(String& a);
    /*
     * A megadott kimenetre kiírja az adatbázisban található koktélok neveit, adatait
     */
    std::ostream& list(std::ostream&);
    /*
    * Egy receptet ennek a segítségével tudunk hozzáadni az adatbázishoz, de csak olyant, aminek már le van foglalva a hely dinamikusan
    * Leginkább a fájlból kiolvasásnál használom, mert ott egyben foglalom a memóriát, nem egyenként, mert az feleslegesen lassítaná a programot,
    * hiszen úgy is tudom előre, hogy hány darab recept lesz a fájlból, ezért az importálásnál foglalok memóriát.
    * A fejlécben meg kell adni a receptre mutató pointert, amit hozzáadunk.
    */
    void add(Cocktail*);
    /*
     * Egy receptet ennek a segítségével tudunk hozzáadni az adatbázishoz, aminek nincs lefoglalva még helye a tömbben, így azt meg kell nyújtani
     * Jellemzően akkor használódik ez a függvény, amikor a felhasználó ad hozzá új receptet a billentyűzetről az adatbázishoz
     */
    void add();
    /*
     * A fejlécben megadott nevű recepthez tudnunk hozzávalót hozzáadni egy már meglévő recepthez,
     * az adatokat a felhasználó adja meg a billentyűzeten keresztül
     */
    void addingredient(String& a);
    /*
     * Eltávolítja az adatbázisból a fejlécben megadott névvel rendelkező receptet, törli a memóriából is
     */
    void remove(String&);
    /*
    * Eltávolítja az adatbázisból a fejlécben megadott névvel rendelkező receptből (első paraméter) a megadott nevű hozzávalót (második paraméter)
    */
    void remove(String&, String&);
    /*
     * A fejlécben megadott nevű fájlból kiolvassa az adatbázist, importál minden receptet, előkészíti az adatbázist a használatra
     */
    void import(String&);
    /*
     * A program bezárásával exportálja a megváltozott adatbázist,a fejlécben megadott névvel rendelkező fájlba, így a módosítások megmaradnak
     * bezárás után is.
     */
    void exp(String&);
    /*
     * A függvény paraméterében megadott nevű receptet megkeresi az adatbázisban és visszatér a tömbbeli indexével.
     * Ha nincs benne, a -1-es visszatérési értékkel jelzi azt
     */
    int indx(String& a);
    /*
     * A függvény paraméterében megadott nevű receptet megkeresi az adatbázisban és kiírja annak a hozzávalóit.
     * Ha nincs benne a megadott recept, akkor ezt a proogram jelzi a felhasználónak.
     */
    void searchbyname(String&);
    /*
     * Megkeresi a receptek között, és kiírja azokat a recepteket, amikben található a fejlécben megadott nevű hozzávaló
     * Hozzávaló szerinti szűrésnél használom
     */
    void filterbyingredient(String&);
    /*
     * Végigmegy a receptek tömbjén, és kiírja az alkoholos/az alkoholmentes recepteket, attól függően, hogy a függvény paraméterében
     * milyen logikai érték szerepel.
     * True - az alkoholos koktélokat írja ki
     * False - az alkoholmentes koktélokat írja ki
     */
    void filterbyalcohol(bool);
    /*
     * Destruktor - felszabadítja a dinamikusan foglalt területet
     */
    ~CocktailContainer()
    {
        for(size_t i=0;i<nCocktail;i++)
        {
            delete cocktails[i];
        }
        delete[] cocktails;
    }
};

#endif // COKCTAILCONTAINER_H_INCLUDED
