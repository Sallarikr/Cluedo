#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

// Syytöksen tarkistaminen
bool tarkistaSyytos(const vector<string>& ratkaisu, const string& kysyttavaAse) {
   return find(ratkaisu.begin(), ratkaisu.end(), kysyttavaAse) != ratkaisu.end();
}

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
 //   naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen
    // naytaRatkaisu(ratkaisu);

    // Kysytään pelaajalta haluaako tämä arvata vai syyttää
    int valinta;
    // Jos käyttäjä antaa muun vastauksen kuin 1 tai 2, ohjelma kysyy uudestaan
    do {
        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
        cout << "Haluatko arvata vai syyttää? (Arvaus = 1, syytös = 2)" << endl;
        cout << "Valintasi: ";
        cin >> valinta;
        if(cin.fail()) {
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Annathan vastauksesi vain numeroina!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        if(valinta != 1 && valinta != 2) {
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
        }
    } while(valinta != 1 && valinta != 2);

    // Jos halutaan arvata
       if(valinta == 1) {
        int vastustaja;
        do {
        // Valitaan vastustaja jolta kortteja kysytään
        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
        cout << "Kummalta vastustajalta haluat kysyä kortteja? (Vastustaja 1 = 1, Vastustaja 2 = 2)" << endl;
        cout << "valintasi: ";
        cin >> vastustaja;
        if(cin.fail()) {
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Annathan vastauksesi vain numeroina!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if(vastustaja != 1 && vastustaja != 2) {
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
        }
        } while(vastustaja != 1 && vastustaja != 2);
        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
        cin.ignore(); // Syötteen tyhjennys, jotta epäillyn koko nimi toimii epäillyn valitsemisessa

        // Kysyttävien korttien valitseminen
        string kysyttavaEpailty;
        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
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

    }
    // Jos halutaan syyttää
    else if (valinta == 2) {
        cout << "Anna syytöksesi: " << endl;
        cin.ignore(); // Syötteen tyhjennys, jotta epäillyn koko nimi toimii epäillyn valitsemisessa

        string kysyttavaEpailty;
        cout << "Syytökseni mukaan murhaaja on "; // Syöte jatkaa lausetta
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

        int lkm = 0;

        if(tarkistaSyytos(ratkaisu, kysyttavaEpailty)) {
            ++lkm;
        }

        if(tarkistaSyytos(ratkaisu, kysyttavaAse)) {
            ++lkm;
        }

        if(tarkistaSyytos(ratkaisu, kysyttavaHuone)) {
            ++lkm;
        }

        // Jos syytös on oikein
        if(lkm == 3) {
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Onneksi olkoon, voitit pelin!" << endl;
        }
        // Jos syytös on väärin
        else {
            int paatos;
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
            cout << "Voi harmi, syytöksesi oli väärin" << endl;

            // Kysytään halutaanko lopettaa vai jatkaa
            do {
                cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                cout << "Haluatko lopettaa pelin, vai katsoa, kumpi vastustajistasi vie voiton? (Lopetus = 1, katsominen = 2)" << endl;
                cout << "Valintasi: ";
                cin >> paatos;

                if(cin.fail()) {
                    cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                    cout << "Annathan vastauksesi vain numeroina!" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                if(paatos != 1 && paatos != 2) {
                    cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
                }
            } while(paatos != 1 && paatos != 2);

            // Jos lopetetaan
            if(paatos == 1) {
                cout << "Ensi kertaan!" << endl;
                exit(0);
            } else if(paatos == 2) {
                // TÄHÄN KATSOMINEN
            }
        }
    }
    return 0;
}
