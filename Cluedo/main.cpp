#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    // Jos käyttäjä antaa muun vastauksen kuin 1 tai 2, ohjelma kysyy uudestaan
    do {
        cout << "Haluatko esittää epäilyn vai syytöksen? (Epäily = 1, syytös = 2)" << endl;
        cout << "Valintasi: ";
        cin >> valinta;
        cin.ignore(); // Syötteen tyhjennys
        if(valinta != 1 && valinta != 2) {
            cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
        }
    } while(valinta != 1 && valinta != 2);

    // Jos halutaan epäillä
    if(valinta == 1) {
        // Valitaan vastustaja jolta kortteja kysytään
        int vastustaja;
        cout << "Kummalta vastustajalta haluat kysyä kortteja? (Vastustaja 1 = 1, Vastustaja 2 = 2)" << endl;
        cout << "valintasi: ";
        cin >> vastustaja;
        cin.ignore(); // Syötteen tyhjennys

        // Kysyttävien korttien valitseminen
        string kysyttavaKortti;
        cout << "Mitä korttia haluat kysyä? ";
        // Epäillyn koko nimen toimimiseksi käytetään getline ja sstream
        getline(cin, kysyttavaKortti);
        stringstream stream(kysyttavaKortti);
        string syote;

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
