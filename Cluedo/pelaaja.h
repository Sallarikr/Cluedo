#ifndef PELAAJA_H
#define PELAAJA_H
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Pelaaja {
public:
    Pelaaja(const string& pelaajanNimi);
    void lisaaKortti(const string& kortti);

    const vector<string>& getPelaajallaOlevatKortit() const {
        return pelaajallaOlevatKortit;
    }

    string getNimi() const;
    bool kadessa(const string& kortti) const;


    bool onNahnytKortin(const string& kortti) const {
        return pelaajanNakematKortit.find(kortti) != pelaajanNakematKortit.end();
    }

    void korttiNahty(const string& kortti);

    void lisaaKorttiNahtyihin(const string& kortti);

    const set<string>& getPelaajanNakematKortit() const;
    const set<string>& getPelaajanNakematEpaillyt() const;
    const set<string>& getPelaajanNakematAseet() const;
    const set<string>& getPelaajanNakematHuoneet() const;

    void listaaNahdytEpaillyt(const vector<Pelaaja>& pelaajat, const string& pelaajanNimi) {
        for(const auto& pelaaja : pelaajat) {
            if(pelaaja.getNimi() == pelaajanNimi) {
                cout << pelaaja.getNimi() + "n näkemät epäillyt: " << endl;
                for(const auto& epailty : pelaaja.getPelaajanNakematEpaillyt()) {
                    cout << epailty << endl;
                }
                return;
            }
        }
    }

    void listaaNahdytAseet(const vector<Pelaaja>& pelaajat, const string& pelaajanNimi) {
        for(const auto& pelaaja : pelaajat) {
            if(pelaaja.getNimi() == pelaajanNimi) {
                cout << pelaaja.getNimi() + "n näkemät aseet: " << endl;
                for(const auto& ase : pelaaja.getPelaajanNakematAseet()) {
                    cout << ase << endl;
                }
                return;
            }
        }
    }

    void listaaNahdytHuoneet(const vector<Pelaaja>& pelaajat, const string& pelaajanNimi) {
        for(const auto& pelaaja : pelaajat) {
            if(pelaaja.getNimi() == pelaajanNimi) {
                cout << pelaaja.getNimi() + "n näkemät huoneet: " << endl;
                for(const auto& huone : pelaaja.getPelaajanNakematHuoneet()) {
                    cout << huone << endl;
                }
                return;
            }
        }
    }

    void poistaNahdytKortit(vector<string>& kortit) {
        for (const string& kortti : nakemattomatKortit) {
            kortit.erase(remove(kortit.begin(), kortit.end(), kortti), kortit.end());
        }
    }

    void lisaaNakemattomiin(const string& kortti) {
        nakemattomatKortit.push_back(kortti);
    }

    const vector<string>& getNakemattomatKortit() const {
        return nakemattomatKortit;
    }


    // Poistaa kortin pelaajan näkemättömien korteista, jos se siellä on
    void poistaNakematon(const string& kortti) {
        auto it = find(nakemattomatKortit.begin(), nakemattomatKortit.end(), kortti);
        if (it != nakemattomatKortit.end()) {
            nakemattomatKortit.erase(it);
        } else {
        }
    }

    void removeItem(vector<string>& listaus, const string& item) {
        listaus.erase(remove(listaus.begin(), listaus.end(), item), listaus.end());
    }

    void muokkaaListaaV1(vector<string>& listaEpaillytV1, vector<string>& listaAseetV1, vector<string>& listaHuoneetV1, const vector<string>& nakemattomatKortit) {
        for (const auto& kortti : nakemattomatKortit) {
            removeItem(listaEpaillytV1, kortti);
            removeItem(listaAseetV1, kortti);
            removeItem(listaHuoneetV1, kortti);
        }
    }

    void muokkaaListaaV2(vector<string>& listaEpaillytV2, vector<string>& listaAseetV2, vector<string>& listaHuoneetV2, const vector<string>& nakemattomatKortit) {
        for (const auto& kortti : nakemattomatKortit) {
            removeItem(listaEpaillytV2, kortti);
            removeItem(listaAseetV2, kortti);
            removeItem(listaHuoneetV2, kortti);
        }
    }


    void naytaPelaajanKortit() const;
    void listaaNahdytKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet);


private:
    string nimi;
    vector<string> pelaajallaOlevatKortit;
    vector<string> nahdytKortit;

    set<string> pelaajanNakematEpaillyt;
    set<string> pelaajanNakematAseet;
    set<string> pelaajanNakematHuoneet;
    set<string> pelaajanNakematKortit;
    vector<string> nakemattomatKortit;
};

void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat);
void jaaKortit(vector<Pelaaja>& pelaajat, vector<string>& kortit);
void listaaNahdytKortit(const vector<Pelaaja>& pelaajat);

#endif // PELAAJA_H
