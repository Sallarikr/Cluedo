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
    pelaajat.push_back(Pelaaja("Pelaaja"));
    pelaajat.push_back(Pelaaja("Vastustaja 1"));
    pelaajat.push_back(Pelaaja("Vastustaja 2"));

    // Korttien luonti
    vector<string> kortit;
    vector<string> ratkaisu;
    luoKortit(kortit, ratkaisu);

    // Korttien jako
    jaaKortit(pelaajat, kortit);
    naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen
    // naytaRatkaisu(ratkaisu);

    // Kysytään pelaajalta haluaako tämä epäillä vai syyttää
    int valinta;
    cout << "Haluatko esittää epäilyn vai syytöksen? (Epäily = 1, syytös = 2)" << endl;
    cout << "Valintasi: ";
    cin >> valinta;

    // Jos halutaan epäillä
    if(valinta == 1) {
        // Valitaan vastustaja jolta kortteja kysytään
        int vastustaja;
        cout << "Kummalta vastustajalta haluat kysyä kortteja? (Vastustaja 1 = 1, Vastustaja 2 = 2)" << endl;
        cout << "valintasi: ";
        cin >> vastustaja;

        // Kysyttävien korttien valitseminen
        string kysyttavaKortti;
        cout << "Mitä korttia haluat kysyä? ";
        cin >> kysyttavaKortti;

        // Korttien kysyminen valitulta vastustajalta
        if(pelaajat[vastustaja].kadessa(kysyttavaKortti)) {
            cout << "LÖYTYY";
        } else {
            cout << "EI LÖYDY";
        }

    } else if (valinta == 2) {
        cout << "Anna syytöksesi: " << endl;
        // Syytöstiedot ratkaisusta
    }

    return 0;
}
