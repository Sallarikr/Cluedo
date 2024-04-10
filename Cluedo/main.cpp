#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
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
void removeItem(vector<string>& mainus, const string& item) {
    mainus.erase(remove(mainus.begin(), mainus.end(), item), mainus.end());
}

string satunnaisKortti(const vector<string>& mainus) {
    if (mainus.empty()) return "";
    // Generoidaan satunnainen numero
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, mainus.size() - 1);
    // Generoidaan satunnainen indeksi
    int satunnaisIndeksi = dis(gen);
    // Satunnainen kortti
    return mainus[satunnaisIndeksi];
}

// Vastustajan 1 kirjauskortin sisältö
void vastus1Kirjaus(vector<string>& epaillyt, vector<string>& aseet, vector<string>& huoneet,
                    const string& poistettava1Epailty, const string& poistettava1Ase, const string& poistettava1Huone) {
    // Poistetaan kortin tiedot vektorista
    removeItem(epaillyt, poistettava1Epailty);
    removeItem(aseet, poistettava1Ase);
    removeItem(huoneet, poistettava1Huone);
}


// Vastustajan 2 kirjauskortin sisältö
void vastus2Kirjaus(vector<string>& epaillyt, vector<string>& aseet,vector<string>& huoneet,
                    const string& poistettava2Epailty, const string& poistettava2Ase, const string& poistettava2Huone) {
    // Poistetaan kortin tiedot vektorista
    removeItem(epaillyt, poistettava2Epailty);
    removeItem(aseet, poistettava2Ase);
    removeItem(huoneet, poistettava2Huone);
}

void muokkaaListaaV1(vector<string>& mainEpaillytV1, vector<string>& mainAseetV1, vector<string>& mainHuoneetV1, const vector<string>& nakemattomatKortit) {
    // Kortin poisto
    for (const auto& kortti : nakemattomatKortit) {
        removeItem(mainEpaillytV1, kortti);
        removeItem(mainAseetV1, kortti);
        removeItem(mainHuoneetV1, kortti);
    }
}

void muokkaaListaaV2(vector<string>& mainEpaillytV2, vector<string>& mainAseetV2, vector<string>& mainHuoneetV2, const vector<string>& nakemattomatKortit) {
    // Kortin poisto
    for (const auto& kortti : nakemattomatKortit) {
        removeItem(mainEpaillytV2, kortti);
        removeItem(mainAseetV2, kortti);
        removeItem(mainHuoneetV2, kortti);
    }
}


void tulostaKaikkiKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet) {
    cout << "Kaikki kortit pelissä:" << endl;
    cout << endl;

    // Tulostetaan epäillyt
    cout << "Epäillyt:" << endl;
    for (const auto& epailty : epaillyt) {
        cout << epailty << ", ";
    }
    cout << endl;
    cout << endl;

    // Tulostetaan aseet
    cout << "Aseet:" << endl;
    for (const auto& ase : aseet) {
        cout << ase << ", ";
    }
    cout << endl;
    cout << endl;

    // Tulostetaan huoneet
    cout << "Huoneet:" << endl;
    for (const auto& huone : huoneet) {
        cout << huone << ", ";
    }
    cout << endl;
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
    // naytaPelaajanKortit(pelaajat);

    // Ratkaisun näyttäminen koodauksen tueksi
    // naytaRatkaisu(ratkaisu);

    // Pelaajien vuorottelu
    int vuorossaOlevaPelaaja = 0;

    string painallus;

    // Jatketaan kunnes peli loppuu
    bool peliLoppuu = false;;

    int v1Kysyttava = 0;
    int v2Kysyttava = 0;

    vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet= {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};


    // Tuodaan tiedot myös tänne vastustajien kysymysten esittämistä varten
    vector<string> epaillytV1 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseetV1 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneetV1 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    vector<string> epaillytV2 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseetV2 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneetV2 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    // Kierrosten laskeminen, parillisuus määrittää keneltä vastustaja kysyy kortteja
    int v1Kierros = 1;
    int v2Kierros = 1;

    while(!peliLoppuu) {
        // Vastustajien nähtyjen korttien poisto
        for (size_t i = 0; i < pelaajat.size(); ++i) {
            pelaajat[i].poistaNahdytKortit(kortit);
        }

        Pelaaja vuorossa = pelaajat[vuorossaOlevaPelaaja];
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << vuorossa.getNimi() << "n vuoro. Paina enteriä jatkaaksesi";
        getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
        cin.clear();

        if(vuorossaOlevaPelaaja == 0) {
            cout << endl;

            tulostaKaikkiKortit(epaillyt, aseet, huoneet);

            cout << endl;
            cout << "*************************************************************" << endl;
            cout << endl;

            naytaPelaajanKortit(vector<Pelaaja>{pelaajat[0]});

            cout << endl;

            pelaajat[0].listaaNahdytKortit(epaillytV1, aseetV1, huoneetV1);

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
                    cout << "valintasi: ";
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

                cout << endl;
                cout << "*************************************************************" << endl;
                cout << endl;

                // Korttien kysyminen valitulta vastustajalta
                // Epäillyn tarkistaminen
                if(pelaajat[vastustaja].kadessa(kysyttavaEpailty) && !pelaajat[0].onNahnytKortin(kysyttavaEpailty)) {
                    cout << "Vastustajalla on kysymäsi epäilty " + kysyttavaEpailty << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaEpailty);
                    pelaajat[0].poistaNakematon(kysyttavaEpailty);

                    // Aseen tarkistaminen
                }  else if(pelaajat[vastustaja].kadessa(kysyttavaAse) && !pelaajat[0].onNahnytKortin(kysyttavaAse)) {
                    cout << "Vastustajalla on kysymäsi ase " + kysyttavaAse << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaAse);
                    pelaajat[0].poistaNakematon(kysyttavaAse);


                }
                // Huoneen tarkistaminen
                else if(pelaajat[vastustaja].kadessa(kysyttavaHuone) && !pelaajat[0].onNahnytKortin(kysyttavaHuone)) {
                    cout << "Vastustajalla on kysymäsi huone " + kysyttavaHuone << endl;
                    pelaajat[0].lisaaKorttiNahtyihin(kysyttavaHuone);
                    pelaajat[0].poistaNakematon(kysyttavaHuone);
                } else {
                    cout << "Valitsemallasi pelaajalla ei ole kysymiäsi kortteja tai olet nähnyt kortit jo!";
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
        } else if (vuorossaOlevaPelaaja == 1) {

            // Vastustajan 1 näkemien korttien kirjauslomake
            vector<string> epaillytV1K = epaillytV1;
            vector<string> aseetV1K = aseetV1;
            vector<string> huoneetV1K = huoneetV1;

            pelaajat[1].muokkaaListaaV1(epaillytV1K, aseetV1K, huoneetV1K, vuorossa.getNakemattomatKortit());

            vastus1Kirjaus(epaillytV1K, aseetV1K, huoneetV1K, poistettava1Epailty, poistettava1Ase, poistettava1Huone);
            cout << endl;

            string v1RandomEpailty = satunnaisKortti(epaillytV1K);
            string v1RandomAse = satunnaisKortti(aseetV1K);
            string v1RandomHuone = satunnaisKortti(huoneetV1K);

            if (v1Kierros % 2 == 0) {
                // Kysytään Pelaajalta
                v1Kysyttava = 0;
            }
            else {
                // Kysytään Vastustaja 2:lta
                v1Kysyttava = 2;
            }

            // Jos kysyttävä kortti on vastustajalla, se poistetaan vastustajan korttimainuksesta
            if(pelaajat[v1Kysyttava].kadessa(v1RandomEpailty) || pelaajat[v1Kysyttava].kadessa(v1RandomAse) || pelaajat[v1Kysyttava].kadessa(v1RandomHuone)) {

                if(pelaajat[v1Kysyttava].kadessa(v1RandomEpailty)) {
                    poistettava1Epailty = v1RandomEpailty;
                    vuorossa.lisaaNakemattomiin(v1RandomEpailty);
                } else {
                }
                if(pelaajat[v1Kysyttava].kadessa(v1RandomAse)) {
                    poistettava1Ase = v1RandomAse;
                    vuorossa.lisaaNakemattomiin(v1RandomAse);
                } else {
                }

                if(pelaajat[v1Kysyttava].kadessa(v1RandomHuone)) {
                    poistettava1Huone = v1RandomHuone;
                    vuorossa.lisaaNakemattomiin(v1RandomHuone);
                } else {
                }
                cout << "Vastustaja näki jonkin kysymistään korteista:" << endl;
                cout << endl;

            } else {
                cout << "Vastustaja ei nähnyt kysymiään kortteja:" << endl;
            }
            muokkaaListaaV1(epaillytV1K, aseetV1K, huoneetV1K, vuorossa.getNakemattomatKortit());

            // Tulostetaan pelaajan nähtäväksi, mitä kortteja on kysytty
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä epäilty: " << v1RandomEpailty << endl;
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä ase: " << v1RandomAse << endl;
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä huone: " << v1RandomHuone << endl;

            ++v1Kierros;

            cout << endl;
            cout << endl;
            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();

        } else {

            // Vastustajan 2 näkemien korttien kirjauslomake
            vector<string> epaillytV2K = epaillytV1;
            vector<string> aseetV2K = aseetV1;
            vector<string> huoneetV2K = huoneetV1;

            //      updatemainLists(epaillytV2, aseetV2, huoneetV2, vuorossa.getNakemattomatKortit());
            pelaajat[2].muokkaaListaaV2(epaillytV2K, aseetV2K, huoneetV2K, vuorossa.getNakemattomatKortit());


            vastus2Kirjaus(epaillytV2K, aseetV2K, huoneetV2K, poistettava2Epailty, poistettava2Ase, poistettava2Huone);
            cout << endl;

            string v2RandomEpailty = satunnaisKortti(epaillytV2K);
            string v2RandomAse = satunnaisKortti(aseetV2K);
            string v2RandomHuone = satunnaisKortti(huoneetV2K);

            if (v2Kierros % 2 == 1) {
                // Kysytään Vastustaja 2:lta
                v2Kysyttava = 0;
            }
            else {
                // Kysytään Pelaajalta
                v2Kysyttava = 0;
            }

            // Jos kysyttävä kortti on vastustajalla, se poistetaan vastustajan korttimainuksesta

            // Jos kysyttävä kortti on vastustajalla, se poistetaan vastustajan korttimainuksesta
            if(pelaajat[v2Kysyttava].kadessa(v2RandomEpailty) || pelaajat[v1Kysyttava].kadessa(v2RandomAse) || pelaajat[v1Kysyttava].kadessa(v2RandomHuone)) {

                if(pelaajat[v2Kysyttava].kadessa(v2RandomEpailty)) {
                    poistettava1Epailty = v2RandomEpailty;
                    vuorossa.lisaaNakemattomiin(v2RandomEpailty);
                } else {
                }
                if(pelaajat[v2Kysyttava].kadessa(v2RandomAse)) {
                    poistettava1Ase = v2RandomAse;
                    vuorossa.lisaaNakemattomiin(v2RandomAse);
                } else {
                }

                if(pelaajat[v2Kysyttava].kadessa(v2RandomHuone)) {
                    poistettava1Huone = v2RandomHuone;
                    vuorossa.lisaaNakemattomiin(v2RandomHuone);
                } else {
                }
                cout << "Vastustaja näki jonkin kysymistään korteista:" << endl;
            } else {
                cout << "Vastustaja ei nähnyt kysymiään kortteja:" << endl;
            }
            muokkaaListaaV2(epaillytV2K, aseetV2K, huoneetV2K, vuorossa.getNakemattomatKortit());

            // Tulostetaan pelaajan nähtäväksi, mitä kortteja on kysytty
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä epäilty: " << v2RandomEpailty << endl;
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä ase: " << v2RandomAse << endl;
            cout << "Vastustaja " << vuorossaOlevaPelaaja << ":n kysymä huone: " << v2RandomHuone << endl;

            ++v2Kierros;

            cout << "Paina enteriä jatkaaksesi";
            getline(cin, painallus); // Käytetään getlinea, jotta ei tarvitse painaa enteriä kahdesti
            cin.clear();
        }
        vuorossaOlevaPelaaja = (vuorossaOlevaPelaaja + 1) % pelaajat.size();
    }
    return 0;
}
