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
    naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen koodauksen tueksi
    // naytaRatkaisu(ratkaisu);

    // Pelaajien vuorottelu
    int vuorossaOlevaPelaaja = 0;

    string painallus;

    // Jatketaan kunnes peli loppuu
    bool peliLoppuu = false;


    // Kierrosten laskeminen, parillisuus määrittää keneltä vastustaja kysyy kortteja
    int v1Kierros = 1;
    int v2Kierros = 1;


    while(!peliLoppuu) {

        Pelaaja vuorossa = pelaajat[vuorossaOlevaPelaaja];
        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << vuorossa.getNimi() << "n vuoro. Paina enteriä jatkaaksesi";
        getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
        cin.clear();

        if(vuorossaOlevaPelaaja == 0) {
            cout << "pelaaja" << endl;
            // Kysytään pelaajalta haluaako tämä arvata vai syyttää
            int valinta;
            // Jos käyttäjä antaa muun vastauksen kuin 1 tai 2, ohjelma kysyy uudestaan
            do {
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

                cout << endl;
                cout << "*************************************************************" << endl;
                cout << endl;


                // Korttien kysyminen valitulta vastustajalta 
                // Epäillyn tarkistaminen
                if(pelaajat[vastustaja].kadessa(kysyttavaEpailty) && !pelaajat[0].onNahnytKortin(kysyttavaEpailty)) {
                    cout << "Vastustajalla on kysymäsi epäilty " + kysyttavaEpailty << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaEpailty);

                    // Aseen tarkistaminen
                }  else if(pelaajat[vastustaja].kadessa(kysyttavaAse) && !pelaajat[0].onNahnytKortin(kysyttavaAse)) {
                    cout << "Vastustajalla on kysymäsi ase " + kysyttavaAse << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaAse);

                }
                // Huoneen tarkistaminen
                else if(pelaajat[vastustaja].kadessa(kysyttavaHuone) && !pelaajat[0].onNahnytKortin(kysyttavaHuone)) {
                    cout << "Vastustajalla on kysymäsi huone " + kysyttavaHuone << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaHuone);
                }


                else {
                    cout << "Valitsemallasi pelaajalla ei ole kysymiäsi kortteja tai olet nähnyt kortit jo!";
                    cout << endl;
                }
                // Tulostetaan jokaisen pelaajan näkemät aseet
                for(const auto& pelaaja : pelaajat) {
                    cout << pelaaja.getNimi() + "n näkemät aseet: " << endl;
                    for(const auto& ase : pelaaja.getPelaajanNakematAseet()) {
                        cout << ase << endl;
                    }
                    cout << endl;
                }

            }
            // Jos halutaan syyttää
            else if (valinta == 2) {
                cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                cout << "Anna syytöksesi: " << endl;
                cin.ignore(); // Syötteen tyhjennys, jotta epäillyn koko nimi toimii epäillyn valitsemisessa

                naytaRatkaisu(ratkaisu);


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
                cout << endl;
                cout << "*************************************************************" << endl;

                // Jos syytös on väärin
                if(lkm != 3)                {
                    int paatos;
                    cout << endl; // Tulostuksen muotoilu miellyttävämmäksi

                    cout << "Voi harmi, syytöksesi oli väärin!" << endl;
                    cout << "Oikea ratkaisu on: " << endl;
                    naytaRatkaisu(ratkaisu);
                    cout << endl;

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
                        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                        cout << "Ensi kertaan!" << endl;
                        cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                        exit(0);
                    } else if(paatos == 2) {
                        // TÄHÄN KATSOMINEN
                    }
                }
                // Jos syytös on oikein
                else {
                    cout << endl; // Tulostuksen muotoilu miellyttävämmäksi
                    cout << "Onneksi olkoon, voitit pelin!" << endl;
                    cout << endl;
                    peliLoppuu = true;
                }

            }

            // Syötteen tyhjennys, jotta seuraavan pelaajan vuoro toimii
            cin.ignore();
            cin.clear();



        } else if (vuorossaOlevaPelaaja == 1) {

            cout << v1Kierros;

            if (v1Kierros % 2 == 0) {
                cout << "kysytään pelaajalta";
            } else {
                cout << "kysytään v2:lta";
            }



            cout << endl;


            listaaNahdytKortit(pelaajat);
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi


            ++v1Kierros;

            cout << endl;
            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();

        } else {


            cout << v2Kierros;

            if (v2Kierros % 2 == 0) {
                cout <<  " kysytään v1:ltä";

            } else {
                cout << "kysytään pelaajalta" ;

            }

            cout << endl;

            ++v2Kierros;

            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();

        }
        // LOGIIKKA

        vuorossaOlevaPelaaja = (vuorossaOlevaPelaaja + 1) % pelaajat.size();

    }





    return 0;

}
