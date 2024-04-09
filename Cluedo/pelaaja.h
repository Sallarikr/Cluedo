#ifndef PELAAJA_H
#define PELAAJA_H
#include <iostream>
#include <set>
#include <string>
#include <vector>

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





private:
    string nimi;
    vector<string> pelaajallaOlevatKortit;
    vector<string> nahdytKortit;

    set<string> pelaajanNakematEpaillyt;
    set<string> pelaajanNakematAseet;
    set<string> pelaajanNakematHuoneet;
    set<string> pelaajanNakematKortit;


};

void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat);
void jaaKortit(vector<Pelaaja>& pelaajat, vector<string>& kortit);
void listaaNahdytKortit(const vector<Pelaaja>& pelaajat);

#endif // PELAAJA_H
