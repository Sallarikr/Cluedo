#include <iostream>
#include <algorithm>
#include "pelaaja.h"

using namespace std;

Pelaaja::Pelaaja(const string& pelaajanNimi) : nimi(pelaajanNimi) {}

// Nimen hakeminen
string Pelaaja::getNimi() const {
    return nimi;
}

// Annetaan pelaajalle kortti
void Pelaaja::lisaaKortti(const string& kortti) {
    pelaajallaOlevatKortit.push_back(kortti);
}

// Jaetaan kortit pelaajille
void jaaKortit(vector<Pelaaja>& pelaajat, vector<string>& kortit) {
    size_t pelaajienLkm = pelaajat.size();
    size_t pelaajanKorttienLkm = kortit.size() / pelaajienLkm;
    for(size_t i = 0; i < pelaajienLkm; ++i) {
        for(size_t j = 0; j < pelaajanKorttienLkm; ++j) {
            pelaajat[i].lisaaKortti(kortit.back());
            kortit.pop_back();
        }
    }
}

// Näytetään kaikki pelaajalla olevat kortit
void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat) {
    for(const auto& pelaaja : pelaajat) {
        cout << pelaaja.getNimi() + "n kortit:" << endl;
        for(const auto& kortti : pelaaja.getPelaajallaOlevatKortit()) {
            cout << kortti << ", ";
        }
        cout << endl;
    }
}

// Kortin kysyminen pelaajalta
bool Pelaaja::kadessa(const string& kortti) const {
    return find(pelaajallaOlevatKortit.begin(), pelaajallaOlevatKortit.end(), kortti) != pelaajallaOlevatKortit.end();
}

vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

void Pelaaja::listaaNahdytKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet) {
    cout << nimi + "n näkemät kortit: " << endl;

    cout << "Epäillyt: ";
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(epaillyt.begin(), epaillyt.end(), kortti) != epaillyt.end()) {
            cout << kortti << ", ";
        }
    }
    cout << endl;

    cout << "Aseet: ";
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(aseet.begin(), aseet.end(), kortti) != aseet.end()) {
            cout << kortti << ", ";
        }
    }
    cout << endl;

    cout << "Huoneet: ";
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(huoneet.begin(), huoneet.end(), kortti) != huoneet.end()) {
            cout << kortti << ", ";
        }
    }
    cout << endl;
}
// Annetaan pelaajalle kortti
void Pelaaja::korttiNahty(const string& kortti) {
    nahdytKortit.push_back(kortti);
}

const set<string>& Pelaaja::getPelaajanNakematEpaillyt() const {
    return pelaajanNakematEpaillyt;
}


const set<string>& Pelaaja::getPelaajanNakematAseet() const {
    return pelaajanNakematAseet;
}

const set<string>& Pelaaja::getPelaajanNakematHuoneet() const {
    return pelaajanNakematHuoneet;
}


void Pelaaja::lisaaKorttiNahtyihin(const string& kortti) {
    pelaajanNakematKortit.insert(kortti);
}

const set<string>& Pelaaja::getPelaajanNakematKortit() const {
    return pelaajanNakematKortit;
}

