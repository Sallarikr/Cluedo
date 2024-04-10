#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

string poistettava1Epailty;
string poistettava1Ase;
string poistettava1Huone;
string poistettava2Epailty;
string poistettava2Ase;
string poistettava2Huone;

// Syytöksen tarkistaminen
bool tarkistaSyytos(const vector<string>& ratkaisu, const string& kysyttavaAse) {
    return find(ratkaisu.begin(), ratkaisu.end(), kysyttavaAse) != ratkaisu.end();
}


// Poistetaan kortti vektorista
void removeItem(vector<string>& listaus, const string& item) {
    listaus.erase(remove(listaus.begin(), listaus.end(), item), listaus.end());
}

// Vastustajan 1 kirjauskortin sisältö
void vastus1Kirjaus(vector<string>& epaillyt,
                    vector<string>& aseet,
                    vector<string>& huoneet,
                    const string& poistettava1Epailty,
                    const string& poistettava1Ase,
                    const string& poistettava1Huone) {
    // Poistetaan kortin tiedot vektorista
    removeItem(epaillyt, poistettava1Epailty);
    removeItem(aseet, poistettava1Ase);
    removeItem(huoneet, poistettava1Huone);
}


// Vastustajan 2 kirjauskortin sisältö
void vastus2Kirjaus(vector<string>& epaillyt,
                    vector<string>& aseet,
                    vector<string>& huoneet,
                    const string& poistettava2Epailty,
                    const string& poistettava2Ase,
                    const string& poistettava2Huone) {
    // Poistetaan kortin tiedot vektorista
    removeItem(epaillyt, poistettava2Epailty);
    removeItem(aseet, poistettava2Ase);
    removeItem(huoneet, poistettava2Huone);
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

    poistettava1Epailty = "Neiti Punakulta";
    poistettava2Epailty = "Tohtori Pinkkilä";

    // Tuodaan tiedot myös tänne vastustajien kysymysten esittämistä varten
    vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

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
                    cout << endl; // Tulostuksen muotoilu miellyttävämmäksi

                    cout << "Voi harmi, syytöksesi oli väärin!" << endl;
                    cout << endl;
                    cout << "Oikea ratkaisu on: " << endl;
                    naytaRatkaisu(ratkaisu);
                    cout << endl;
                    peliLoppuu = true;
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

            // Vastustajan 1 näkemien korttien kirjauslomake
            vector<string> epaillytV1 = epaillyt;
            vector<string> aseetV1 = aseet;
            vector<string> huoneetV1 = huoneet;

            vastus1Kirjaus(epaillytV1, aseetV1, huoneetV1, poistettava1Epailty, poistettava1Ase, poistettava1Huone);

            // Korttien tulostus koodauksen tueksi
            cout << "Vastustaja 1:n näkemät epäillyt:" << endl;
            for (const auto& item : epaillytV1) {
                cout << item << " ";
            }
            cout << endl;;

            cout << "Vastustaja 1:n näkemät aseet:" << endl;
            for (const auto& item : aseetV1) {
                cout << item << " ";
            }
            cout << endl;;

            cout << "Vastustaja 1:n näkemät huoneet:" << endl;
            for (const auto& item : huoneetV1) {
                cout << item << " ";
            }
            cout << endl;;

            cout << endl;


            //     listaaNahdytKortit(pelaajat);
            cout << endl; // Tulostuksen muotoilu miellyttävämmäksi



            cout << endl;
            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();

        } else {

            // Vastustajan 2 näkemien korttien kirjauslomake
            vector<string> epaillytV2 = epaillyt;
            vector<string> aseetV2 = aseet;
            vector<string> huoneetV2 = huoneet;

            vastus2Kirjaus(epaillytV2, aseetV2, huoneetV2, poistettava2Epailty, poistettava2Ase, poistettava2Huone);

            // Korttien tulostus koodauksen tueksi
            cout << "Vastustaja 2:n näkemät epäillyt:" << endl;
            for (const auto& item : epaillytV2) {
                cout << item << " ";
            }
            cout << endl;;

            cout << "Vastustaja 2:n näkemät aseet:" << endl;
            for (const auto& item : aseetV2) {
                cout << item << " ";
            }
            cout << endl;;

            cout << "Vastustaja 2:n näkemät huoneet:" << endl;
            for (const auto& item : huoneetV2) {
                cout << item << " ";
            }
            cout << endl;;


            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();

        }

        vuorossaOlevaPelaaja = (vuorossaOlevaPelaaja + 1) % pelaajat.size();

    }





    return 0;

}
