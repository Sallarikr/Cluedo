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
        cout << pelaaja.getNimi() + ":n kortit:" << endl;
        for(const auto& kortti : pelaaja.getPelaajallaOlevatKortit()) {
            cout << kortti << endl;
        }
        cout << endl;
    }
}

// Kortin kysyminen pelaajalta
bool Pelaaja::kadessa(const string& kortti) const {
    return find(pelaajallaOlevatKortit.begin(), pelaajallaOlevatKortit.end(), kortti) != pelaajallaOlevatKortit.end();
}



void listaaNahdytKortit(const vector<Pelaaja>& pelaajat) {
    for(const auto& pelaaja : pelaajat) {
        cout << pelaaja.getNimi() + "n näkemät kortit: " << endl;
        for(const auto& kortti : pelaaja.getPelaajanNakematKortit()) {
            cout << kortti << endl;
        }
        cout << endl;
    }

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

