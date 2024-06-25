#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include "kortti.h"
#include "pelaaja.h"

using namespace std;

// Syytöksen tarkistaminen
bool tarkistaSyytos(const vector<string>& ratkaisu, const string& kysyttavaAse) {
return find(ratkaisu.begin(), ratkaisu.end(), kysyttavaAse) != ratkaisu.end();
}

// Korttien satunnaistaminen
string satunnaisKortti(const vector<string>& listaus) {
if (listaus.empty()) return "";
// Generoidaan satunnainen numero
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, listaus.size() - 1);
// Generoidaan satunnainen indeksi
int satunnaisIndeksi = dis(gen);
// Satunnainen kortti
return listaus[satunnaisIndeksi];
}

// Korttien tulostaminen
void tulostaKaikkiKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet,
                     const vector<string>& epaillyt1, const vector<string>& aseet1, const vector<string>& huoneet1,
                     const vector<string>& epaillyt2, const vector<string>& aseet2, const vector<string>& huoneet2, const Pelaaja& pelaaja, int& nro) {

cout << "Arvattavissa olevat kortit:" << endl;
cout << endl;

// Pelaajan kortit
if (nro == 0) {

// Tulostetaan epäillyt
cout << "Epäillyt:" << endl;
for (const auto& epailty : epaillyt) {
    if (!pelaaja.kadessa(epailty)) {
        cout << epailty << ", ";
    }
}
// Tulostuksen muotoilu
cout << endl;
cout << endl;

// Tulostetaan aseet
cout << "Aseet:" << endl;
for (const auto& ase : aseet) {
    if (!pelaaja.kadessa(ase)) {
        cout << ase << ", ";
    }
}
// Tulostuksen muotoilu
cout << endl;
cout << endl;

// Tulostetaan huoneet
cout << "Huoneet:" << endl;
for (const auto& huone : huoneet) {
    if (!pelaaja.kadessa(huone)) {
        cout << huone << ", ";
    }
}
// Tulostuksen muotoilu
cout << endl;
}

// Koodauksen tueksi vastustaja 1:n kortit
else if (nro == 1) {

 // Tulostetaan epäillyt
    cout << "Epäillyt:" << endl;
    for (const auto& epailty1 : epaillyt1) {
        if (!pelaaja.kadessa(epailty1)) {
            cout << epailty1 << ", ";
        }
    }
    cout << endl;

    // Tulostetaan aseet
    cout << "Aseet:" << endl;
    for (const auto& ase1 : aseet1) {
        if (!pelaaja.kadessa(ase1)) {
            cout << ase1 << ", ";
        }
    }
    cout << endl;

    // Tulostetaan huoneet
    cout << "Huoneet:" << endl;
    for (const auto& huone1 : huoneet1) {
        if (!pelaaja.kadessa(huone1)) {
            cout << huone1 << ", ";
        }
    }
}

// Koodauksen tueksi Vastustaja 2:n kortit
else if (nro == 2) {

    // Tulostetaan epäillyt
    cout << "Epäillyt:" << endl;
    for (const auto& epailty2 : epaillyt2) {
        if (!pelaaja.kadessa(epailty2)) {
            cout << epailty2 << ", ";
        }
    }
    cout << endl;

    // Tulostetaan aseet
    cout << "Aseet:" << endl;
    for (const auto& ase2 : aseet2) {
        if (!pelaaja.kadessa(ase2)) {
            cout << ase2 << ", ";
        }
    }
    cout << endl;

    // Tulostetaan huoneet
    cout << "Huoneet:" << endl;
    for (const auto& huone2 : huoneet2) {
        if (!pelaaja.kadessa(huone2)) {
            cout << huone2 << ", ";
        }
    }
}
}

// Kortin poistaminen pelaajan kysyttävistä korteista
void poistaArvattavista(vector<string>& epaillyt, vector<string>& aseet, vector<string>& huoneet, const string& card) {
epaillyt.erase(remove(epaillyt.begin(), epaillyt.end(), card), epaillyt.end());
aseet.erase(remove(aseet.begin(), aseet.end(), card), aseet.end());
huoneet.erase(remove(huoneet.begin(), huoneet.end(), card), huoneet.end());
}

// Kortin poistaminen vastustaja 1:n kysyttävistä korteista
void poistaArvattavista1(vector<string>& epaillyt1, vector<string>& aseet1, vector<string>& huoneet1, const string& card1) {
    epaillyt1.erase(remove(epaillyt1.begin(), epaillyt1.end(), card1), epaillyt1.end());
    aseet1.erase(remove(aseet1.begin(), aseet1.end(), card1), aseet1.end());
    huoneet1.erase(remove(huoneet1.begin(), huoneet1.end(), card1), huoneet1.end());
}

// Kortin poistaminen vastustaja 2:n kysyttävistä korteista
void poistaArvattavista2(vector<string>& epaillyt2, vector<string>& aseet2, vector<string>& huoneet2, const string& card2) {
    epaillyt2.erase(remove(epaillyt2.begin(), epaillyt2.end(), card2), epaillyt2.end());
    aseet2.erase(remove(aseet2.begin(), aseet2.end(), card2), aseet2.end());
    huoneet2.erase(remove(huoneet2.begin(), huoneet2.end(), card2), huoneet2.end());
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
// Koodauksen tueksi pelaajien korttien tulostus
// naytaPelaajanKortit(pelaajat);

// Pelaajien vuorottelu
int vuorossaOlevaPelaaja = 0;

string painallus;

// Jatketaan kunnes peli loppuu
bool peliLoppuu = false;;

// Arvattavien korttien alustus pelaajalle
vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

// Arvattavien korttien alustus vastustaja 1:lle
vector<string> epaillyt1 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet1 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet1 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

// Arvattavien korttien alustus vastustaja 2:lle
vector<string> epaillyt2 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet2 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet2 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

// Vastustajien kysyttävien pelaajien alustus
int v1Kysyttava = 0;
int v2Kysyttava = 0;

// Kierrosten laskeminen, parillisuus määrittää keneltä vastustaja kysyy kortteja
int v1Kierros = 1;
int v2Kierros = 1;


// Peli jatkuu kunnes pelaaja esittää syytöksen
while(!peliLoppuu) {
    Pelaaja vuorossa = pelaajat[vuorossaOlevaPelaaja];
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << vuorossa.getNimi() << "n vuoro. Paina enteriä jatkaaksesi";
    getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
    cin.clear();

    if(vuorossaOlevaPelaaja == 0) {
       int nro = 0;
        cout << endl;

        // Pelaajan arvattavissa olevien korttien tulostus
        tulostaKaikkiKortit(epaillyt, aseet, huoneet, epaillyt1, aseet1, huoneet1, epaillyt2, aseet2, huoneet2, pelaajat[0], nro);

        // Tulostuksen muotoilu
        cout << endl;
        cout << "*************************************************************" << endl;
        cout << endl;

        // Kysytään pelaajalta haluaako tämä arvata vai syyttää
        int valinta;
        // Jos käyttäjä antaa muun vastauksen kuin 1 tai 2, ohjelma kysyy uudestaan
        do {
            cout << "Haluatko arvata vai syyttää? (Arvaus = 1, syytös = 2)" << endl;
            cout << "Valintasi: ";
            cin >> valinta;
            if(cin.fail()) {
                cout << endl;
                cout << "Annathan vastauksesi vain numeroina!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            if(valinta != 1 && valinta != 2) {
                cout << endl;
                cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
            }
        } while(valinta != 1 && valinta != 2);

        // Jos halutaan arvata
        if(valinta == 1) {
            int vastustaja;
            do {
                // Valitaan vastustaja jolta kortteja kysytään
                cout << endl;
                cout << "Kummalta vastustajalta haluat kysyä kortteja? (Vastustaja 1 = 1, Vastustaja 2 = 2)" << endl;
                cout << "Valintasi: ";
                cin >> vastustaja;
                if(cin.fail()) {
                    cout << "Annathan vastauksesi vain numeroina!" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                if(vastustaja != 1 && vastustaja != 2) {
                    cout << endl;
                    cout << "Virheellinen syöte, anna joko numero 1 tai 2!" << endl;
                }
            } while(vastustaja != 1 && vastustaja != 2);
            cout << endl;
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

            // Tulostuksen muotoilu
            cout << endl;
            cout << "*************************************************************" << endl;
            cout << endl;

            // Korttien kysyminen valitulta vastustajalta, jos kortti nähdään, se poistetaan kysyttävien luettelosta
            // Epäillyn tarkistaminen
            if(pelaajat[vastustaja].kadessa(kysyttavaEpailty) && !pelaajat[0].onNahnytKortin(kysyttavaEpailty)) {
                cout << "Vastustajalla on kysymäsi epäilty " + kysyttavaEpailty << endl;
                pelaajat[0].lisaaKorttiNahtyihin(kysyttavaEpailty);
                poistaArvattavista(epaillyt, aseet, huoneet, kysyttavaEpailty);
                // Aseen tarkistaminen
            } else if(pelaajat[vastustaja].kadessa(kysyttavaAse) && !pelaajat[0].onNahnytKortin(kysyttavaAse)) {
                cout << "Vastustajalla on kysymäsi ase " + kysyttavaAse << endl;
                pelaajat[0].lisaaKorttiNahtyihin(kysyttavaAse);
                poistaArvattavista(epaillyt, aseet, huoneet, kysyttavaAse);
            }
            // Huoneen tarkistaminen
            else if(pelaajat[vastustaja].kadessa(kysyttavaHuone) && !pelaajat[0].onNahnytKortin(kysyttavaHuone)) {
                cout << "Vastustajalla on kysymäsi huone " + kysyttavaHuone << endl;
                pelaajat[0].lisaaKorttiNahtyihin(kysyttavaHuone);
                poistaArvattavista(epaillyt, aseet, huoneet, kysyttavaHuone);
            } else {
                // Jos kortteja ei löydy
                cout << "Valitsemallasi pelaajalla ei ole kysymiäsi kortteja!";
                cout << endl;
            }
        }

        // Jos halutaan syyttää
        else if (valinta == 2) {
            cout << endl;
            cout << "Anna syytöksesi: " << endl;
            cin.ignore(); // Syötteen tyhjennys, jotta epäillyn koko nimi toimii epäillyn valitsemisessa

            // Ratkaisun näyttäminen koodauksen tueksi
            // naytaRatkaisu(ratkaisu);

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

            // Oikeat vastaukset luvuksi
            if(tarkistaSyytos(ratkaisu, kysyttavaEpailty)) {
                ++lkm;
            }

            if(tarkistaSyytos(ratkaisu, kysyttavaAse)) {
                ++lkm;
            }

            if(tarkistaSyytos(ratkaisu, kysyttavaHuone)) {
                ++lkm;
            }

            // Tulostuksen muotoilu
            cout << endl;
            cout << "*************************************************************" << endl;

            // Jos syytös on väärin
            if(lkm != 3)                {
                cout << endl;
                cout << "Voi harmi, syytöksesi oli väärin!" << endl;
                cout << endl;
                cout << "Oikea ratkaisu on: " << endl;
                naytaRatkaisu(ratkaisu);
                cout << endl;
                peliLoppuu = true;
            }
            // Jos syytös on oikein
            else {
                cout << endl;
                cout << "Onneksi olkoon, voitit pelin!" << endl;
                cout << endl;
                peliLoppuu = true;
            }
        }

        // Syötteen tyhjennys, jotta seuraavan pelaajan vuoro toimii
        cin.ignore();
        cin.clear();

      // Koodauksen tueksi kaikkien pelaajien korttien tulostus
      //   naytaPelaajanKortit(pelaajat);

    }  else if (vuorossaOlevaPelaaja == 1) {
        // Koodauksen tueksi vastustajan kysyttävien korttien tulostus
        // int nro = 1;
        // tulostaKaikkiKortit(epaillyt, aseet, huoneet, epaillyt1, aseet1, huoneet1, epaillyt2, aseet2, huoneet2, pelaajat[1], nro);

        string v1RandomEpailty = satunnaisKortti(epaillyt1);
        string v1RandomAse = satunnaisKortti(aseet1);
        string v1RandomHuone = satunnaisKortti(huoneet1);

        // Poistetaan kysyttävistä vastustajan omat kortit
        for (const auto& epailty1 : epaillyt1) {
            if (pelaajat[1].kadessa(epailty1)) {
                poistaArvattavista1(epaillyt1, aseet1, huoneet1, epailty1);
            }
        }
        for (const auto& ase1 : aseet1) {
            if (pelaajat[1].kadessa(ase1)) {
                poistaArvattavista1(epaillyt1, aseet1, huoneet1, ase1);
            }
        }
        for (const auto& huone1 : huoneet1) {
            if (pelaajat[1].kadessa(huone1)) {
                poistaArvattavista1(epaillyt1, aseet1, huoneet1, huone1);
            }
        }

        // Kysyttävän vastustajan vuorottelu
        if (v1Kierros % 2 == 0) {
            // Kysytään Pelaajalta
            v1Kysyttava = 0;
        }
        else {
            // Kysytään Vastustaja 2:lta
            v1Kysyttava = 2;
        }

        // Tulostusta varten kysytyn pelaajan nimi
        string k1Nimi;
        if(v1Kysyttava == 0) {
            k1Nimi = "Pelaajalta";
        } else if(v1Kysyttava == 2) {
            k1Nimi = "Vastustaja 2:lta";
        }

        // Tulostuksen muotoilu
        cout << endl;

        // Jos vastustaja on löytänyt ratkaisun, peli päättyy
        if ((epaillyt1.size() == 1 && huoneet1.size() == 1 && aseet1.size() == 1)) {
            cout << "Vastustaja 1 voitti pelin syytöksellään. Murhaaja oli " + epaillyt1[0] + ", aseena oli " + aseet1[0] + " ja murhapaikkana oli " + huoneet1[0] << endl;
            break;
        }

        // Jos kysyttävä kortti on kysyttävällä vastustajalla, se poistetaan vastustajan kysyttävien korttien listauksesta
        if(pelaajat[v1Kysyttava].kadessa(v1RandomEpailty)) {
            pelaajat[1].lisaaKorttiNahtyihin(v1RandomEpailty);
            cout << "Vastustaja 1 näki jonkin " + k1Nimi + " kysymistään korteista:" << endl;
            poistaArvattavista1(epaillyt1, aseet1, huoneet1, v1RandomEpailty);
        } else if(pelaajat[v1Kysyttava].kadessa(v1RandomAse)) {
            pelaajat[1].lisaaKorttiNahtyihin(v1RandomAse);
            cout << "Vastustaja 1 näki jonkin " + k1Nimi + " kysymistään korteista:" << endl;
            poistaArvattavista1(epaillyt1, aseet1, huoneet1, v1RandomAse);
        } else if(pelaajat[v1Kysyttava].kadessa(v1RandomHuone)) {
            pelaajat[1].lisaaKorttiNahtyihin(v1RandomHuone);
            cout << "Vastustaja 1 näki jonkin " + k1Nimi + " kysymistään korteista:" << endl;
            poistaArvattavista1(epaillyt1, aseet1, huoneet1, v1RandomHuone);
        } else {
            cout << "Vastustaja 1 ei nähnyt mitään " + k1Nimi + " kysymiään kortteja:" << endl;
        }

        // Tulostuksen muotoilu
        cout << endl;

        // Tulostetaan pelaajan nähtäväksi, mitä kortteja on kysytty
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä epäilty: " << v1RandomEpailty << endl;
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä ase: " << v1RandomAse << endl;
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä huone: " << v1RandomHuone << endl;

        ++v1Kierros;

        // Tulostuksen muotoilu
        cout << endl;
        cout << "Paina enteriä jatkaaksesi";
        getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
        cin.clear();
    } else if (vuorossaOlevaPelaaja==2){
        // Koodauksen tueksi vastustajan kysyttävien korttien tulostus
        // int nro = 2;
        // tulostaKaikkiKortit(epaillyt, aseet, huoneet, epaillyt1, aseet1, huoneet1, epaillyt2, aseet2, huoneet2, pelaajat[2], nro);

        string v2RandomEpailty = satunnaisKortti(epaillyt2);
        string v2RandomAse = satunnaisKortti(aseet2);
        string v2RandomHuone = satunnaisKortti(huoneet2);

        // Poistetaan kysyttävistä vastustajan omat kortit
        for (const auto& epailty2 : epaillyt2) {
            if (pelaajat[2].kadessa(epailty2)) {
                poistaArvattavista2(epaillyt2, aseet2, huoneet2, epailty2);
            }
        }
        for (const auto& ase2 : aseet2) {
            if (pelaajat[2].kadessa(ase2)) {
                poistaArvattavista2(epaillyt2, aseet2, huoneet2, ase2);
            }
        }
        for (const auto& huone2 : huoneet2) {
            if (pelaajat[2].kadessa(huone2)) {
                poistaArvattavista2(epaillyt2, aseet2, huoneet2, huone2);
            }
        }

        // Kysyttävän vastustajan vuorottelu
        if (v2Kierros % 2 == 0) {
            // Kysytään Vastustaja 1:lta
            v2Kysyttava = 1;
        }
        else {
            // Kysytään Pelaajalta
            v2Kysyttava = 0;
        }

        // Tulostusta varten kysytyn pelaajan nimi
        string k2Nimi;
        if(v2Kysyttava == 0) {
            k2Nimi = "Pelaajalta";
        } else if(v2Kysyttava == 1) {
            k2Nimi = "Vastustaja 1:lta";
        }

        // Tulostuksen muotoilu
        cout << endl;

        // Jos vastustaja on löytänyt ratkaisun, peli päättyy
        if ((epaillyt2.size() == 1 && huoneet2.size() == 1 && aseet2.size() == 1)) {
            cout << "Vastustaja 2 voitti pelin syytöksellään. Murhaaja oli " + epaillyt2[0] + ", aseena oli " + aseet2[0] + " ja murhapaikkana oli " + huoneet2[0] << endl;
            break;
        }

        // Jos kysyttävä kortti on kysyttävällä vastustajalla, se poistetaan vastustajan kysyttävien korttien listauksesta
           if(pelaajat[v2Kysyttava].kadessa(v2RandomEpailty)) {
            pelaajat[2].lisaaKorttiNahtyihin(v2RandomEpailty);
            cout << "Vastustaja 2 näki jonkin " + k2Nimi + " kysymistään korteista:" << endl;
        } else if(pelaajat[v2Kysyttava].kadessa(v2RandomAse)) {
            pelaajat[2].lisaaKorttiNahtyihin(v2RandomAse);
            cout << "Vastustaja 2 näki jonkin " + k2Nimi + " kysymistään korteista:" << endl;
            poistaArvattavista2(epaillyt2, aseet2, huoneet2, v2RandomAse);
        } else if(pelaajat[v2Kysyttava].kadessa(v2RandomHuone)) {
            pelaajat[2].lisaaKorttiNahtyihin(v2RandomHuone);
            cout << "Vastustaja 2 näki jonkin " + k2Nimi + " kysymistään korteista:" << endl;
            poistaArvattavista2(epaillyt2, aseet2, huoneet2, v2RandomHuone);
        } else {
            cout << "Vastustaja 2 ei nähnyt mitään " + k2Nimi + " kysymiään kortteja:" << endl;
        }

        // Tulostuksen muotoilu
        cout << endl;

        // Tulostetaan pelaajan nähtäväksi, mitä kortteja on kysytty
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä epäilty: " << v2RandomEpailty << endl;
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä ase: " << v2RandomAse << endl;
        cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä huone: " << v2RandomHuone << endl;

        ++v2Kierros;

        // Tulostuksen muotoilu
        cout << endl;
        cout << "Paina enteriä jatkaaksesi";
        getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
        cin.clear();
    }
    vuorossaOlevaPelaaja = (vuorossaOlevaPelaaja + 1) % pelaajat.size();
}
return 0;
}
