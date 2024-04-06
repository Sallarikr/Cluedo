#include <vector>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

int main()
{
    // Pelaajien luonti
    vector<Pelaaja> pelaajat;
    luoPelaajat(pelaajat);

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
