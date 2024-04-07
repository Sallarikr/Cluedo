﻿#include <iostream>
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

    // Kysytään pelaajalta haluaako tämä arvata vai syyttää
    int valinta;
    // Jos käyttäjä antaa muun vastauksen kuin 1 tai 2, ohjelma kysyy uudestaan
    do {
        cout << "Haluatko arvata vai syyttää? (Arvaus = 1, syytös = 2)" << endl;
        cout << "Valintasi: ";
        cin >> valinta;
        if(valinta != 1 && valinta != 2) {
            cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
        }
    } while(valinta != 1 && valinta != 2);

    // Jos halutaan arvata
    if(valinta == 1) {
        // Valitaan vastustaja jolta kortteja kysytään
        int vastustaja;
        cout << "Kummalta vastustajalta haluat kysyä kortteja? (Vastustaja 1 = 1, Vastustaja 2 = 2)" << endl;
        cout << "valintasi: ";
        cin >> vastustaja;
        cin.ignore(); // Syötteen tyhjennys, jotta epäillyn koko nimi toimii epäillyn valitsemisessa

        // Kysyttävien korttien valitseminen
        string kysyttavaEpailty;
        cout << "Arvaan, että murhaaja on "; // Syöte jatkaa lausetta
        // Epäillyn koko nimen toimimiseksi käytetään getline ja sstream
        getline(cin, kysyttavaEpailty);
        stringstream stream(kysyttavaEpailty);
        string syote;

        string kysyttavaAse;
        cout << "Murha-aseena oli "; // Syöte jatkaa lausetta
        cin >> kysyttavaAse;

        string kysyttavaHuone;
        cout << "Tapahtumapaikkana oli "; // Syöte päättää arvauksen
        cin >> kysyttavaHuone;

        // Korttien kysyminen valitulta vastustajalta
        if(pelaajat[vastustaja].kadessa(kysyttavaEpailty)) {
            cout << "EPÄILTY LÖYTYY" << endl;
        } else {
            cout << "EPÄILTYÄ EI LÖYDY" << endl;
        }

        if(pelaajat[vastustaja].kadessa(kysyttavaAse)) {
            cout << "ASE LÖYTYY" << endl;
        } else {
            cout << "ASETTA EI LÖYDY" << endl;
        }

        if(pelaajat[vastustaja].kadessa(kysyttavaHuone)) {
            cout << "HUONE LÖYTYY" << endl;
        } else {
            cout << "HUONETTA EI LÖYDY" << endl;
        }

    } else if (valinta == 2) {
        cout << "Anna syytöksesi: " << endl;
        // Syytöstiedot ratkaisusta
    }

    return 0;
}
