#include <iostream>
#include <vector>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

int main()
{
    // Pelaajien luonti
    vector<Pelaaja> pelaajat;
    // Nimien lisäys
    pelaajat.push_back(Pelaaja("Käyttäjä"));
    pelaajat.push_back(Pelaaja("Toka"));
    pelaajat.push_back(Pelaaja("Kolmas"));
    // Nimien testitulostus
     cout << "Nimet: " << endl;
     for(const auto& pelaaja : pelaajat) {
         cout << pelaaja.getNimi() << endl;
     }

    // Korttien luonti
    vector<string> kortit;
    vector<string> ratkaisu;
    luoKortit(kortit, ratkaisu);

    // Korttien jako
   // jaaKortit(pelaajat, kortit);
   // naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen
 //   naytaRatkaisu(ratkaisu);

    return 0;
}
