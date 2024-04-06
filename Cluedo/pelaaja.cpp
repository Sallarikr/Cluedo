#include <iostream>
#include "pelaaja.h"

using namespace std;

// Luodaan pelaajat
void luoPelaajat(vector<Pelaaja>& pelaajat) {
    pelaajat.emplace_back("Pelaaja 1");
    pelaajat.emplace_back("Pelaaja 2");
    pelaajat.emplace_back("Pelaaja 3");
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

// Näytetään pelaajalla olevat kortit
void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat) {
    for(size_t i = 0; i < pelaajat.size(); ++i) {
        cout << "Pelaajan " << i + 1 << " kortit:" << endl;
        for(const auto& kortti : pelaajat[i].getPelaajallaOlevatKortit()) {
            cout << kortti << endl;
        }
        cout << endl;
    }
}
