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

// Kortin kysyminen pelaajalta kyselyä varten
bool Pelaaja::kadessa(const string& kortti) const {
    return find(pelaajallaOlevatKortit.begin(), pelaajallaOlevatKortit.end(), kortti) != pelaajallaOlevatKortit.end();
}

// Listaus korteista kyselyä varten
vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

vector<string> epaillyt1 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet1 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet1 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

vector<string> epaillyt2 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet2 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet2 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};




void Pelaaja::listaaNahdytKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet,
                                 const vector<string>& epaillyt1, const vector<string>& aseet1, const vector<string>& huoneet1,
                                 const vector<string>& epaillyt2, const vector<string>& aseet2, const vector<string>& huoneet2, int& nro) {
    cout << nimi + "n näkemät kortit: " << endl;
    cout << "Epäillyt: ";
    if(nro == 0) {
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(epaillyt.begin(), epaillyt.end(), kortti) != epaillyt.end()) {
            cout << kortti << ", ";
        }
    }
    } else if (nro == 1){
        for(const auto& kortti1 : pelaajanNakematKortit) {
            if (find(epaillyt1.begin(), epaillyt1.end(), kortti1) != epaillyt1.end()) {
                cout << kortti1 << ", ";
            }
        }
    } else if (nro == 2) {
        for(const auto& kortti2 : pelaajanNakematKortit) {
            if (find(epaillyt2.begin(), epaillyt2.end(), kortti2) != epaillyt2.end()) {
                cout << kortti2 << ", ";
            }
        }
    }

    cout << endl;

    cout << "Aseet: ";
    if(nro == 0) {
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(aseet.begin(), aseet.end(), kortti) != aseet.end()) {
            cout << kortti << ", ";
        }
    }
    } else if(nro == 1) {
        for(const auto& kortti1 : pelaajanNakematKortit) {
            if (find(aseet1.begin(), aseet1.end(), kortti1) != aseet1.end()) {
                cout << kortti1 << ", ";
            }
        }
    } else if (nro == 2) {
        for(const auto& kortti2 : pelaajanNakematKortit) {
            if (find(aseet2.begin(), aseet2.end(), kortti2) != aseet2.end()) {
                cout << kortti2 << ", ";
            }
        }
    }
    cout << endl;

    cout << "Huoneet: ";
    if(nro == 0){
    for(const auto& kortti : pelaajanNakematKortit) {
        if (find(huoneet.begin(), huoneet.end(), kortti) != huoneet.end()) {
            cout << kortti << ", ";
        }
    }
    } else if (nro == 1) {
        for(const auto& kortti1 : pelaajanNakematKortit) {
            if (find(huoneet1.begin(), huoneet1.end(), kortti1) != huoneet1.end()) {
                cout << kortti1 << ", ";
            }
        }
    }
    else if (nro == 2) {
    for(const auto& kortti2: pelaajanNakematKortit) {
        if (find(huoneet2.begin(), huoneet2.end(), kortti2) != huoneet2.end()) {
            cout << kortti2 << ", ";
        }
    }
    }
    cout << endl;
}

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
