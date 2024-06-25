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

    void seeCard(const string& card) {
        nakemattomatKortit.erase(remove(nakemattomatKortit.begin(), nakemattomatKortit.end(), card), nakemattomatKortit.end());
        nahdytKortit.push_back(card);
    }

    // Vastustajien näkemättömäksi laitettavat kortit
    vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    vector<string> epaillyt1 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet1 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet1 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    vector<string> epaillyt2 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet2 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet2 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    Pelaaja(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet) {
        // Lisätään kortit näkemättömiksi
        nakemattomatKortit.reserve(epaillyt.size() + aseet.size() + huoneet.size());
        nakemattomatKortit.insert(nakemattomatKortit.end(), epaillyt.begin(), epaillyt.end());
        nakemattomatKortit.insert(nakemattomatKortit.end(), aseet.begin(), aseet.end());
        nakemattomatKortit.insert(nakemattomatKortit.end(), huoneet.begin(), huoneet.end());
    }

    // Tarkistetaan onko kortti vastustajalla itsellään
    bool kadessaOn(const string& kortti) const {
        return find(nakemattomatKortit.begin(), nakemattomatKortit.end(), kortti) != getNakemattomatKortit().end();
    }

    /* Vastustajien arvattavissa olevien korttien tulostus koodaamisen tueksi
    void tulostaKaikkiKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet, const Pelaaja& pelaaja) {
        cout << "Arvattavissa olevat kortit:" << endl;
        cout << endl;

        // Tulostetaan epäillyt
        cout << "Epäillyt:" << endl;
        for (const auto& epailty : epaillyt) {
            if (!pelaaja.kadessaOn(epailty)) {
                cout << epailty << ", ";
            }
        }
        cout << endl;
        cout << endl;

        // Tulostetaan aseet
        cout << "Aseet:" << endl;
        for (const auto& ase : aseet) {
            if (!pelaaja.kadessaOn(ase)) {
                cout << ase << ", ";
            }
        }
        cout << endl;
        cout << endl;

        // Tulostetaan huoneet
        cout << "Huoneet:" << endl;
        for (const auto& huone : huoneet) {
            if (!pelaaja.kadessaOn(huone)) {
                cout << huone << ", ";
            }
        }
        cout << endl;

         Näytetään vastustajan näkemät kortit ohjelmoinnin tueksi
        cout << "Nähtyjen korttien luettelo:" << endl;
        for (const auto& kortti : pelaaja.nakemattomatKortit) {
           cout << kortti << ", ";
       }
        cout << endl;
    }
*/
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
