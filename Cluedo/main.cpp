#include <vector>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

int main()
{
    // Pelaajien luonti
    vector<Pelaaja> pelaajat;
    // Nimien lisäys
    pelaajat.push_back(Pelaaja("Pelaaja 1"));
    pelaajat.push_back(Pelaaja("Pelaaja 2"));
    pelaajat.push_back(Pelaaja("Pelaaja 3"));

    // Korttien luonti
    vector<string> kortit;
    vector<string> ratkaisu;
    luoKortit(kortit, ratkaisu);

    // Korttien jako
    jaaKortit(pelaajat, kortit);
    naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen
    naytaRatkaisu(ratkaisu);

    return 0;
}
