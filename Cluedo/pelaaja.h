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

// Pelaajan kortit
const vector<string>& getPelaajallaOlevatKortit() const {
    return pelaajallaOlevatKortit;
}

string getNimi() const;
bool kadessa(const string& kortti) const;

// Onko kortti nähty
bool onNahnytKortin(const string& kortti) const {
    return pelaajanNakematKortit.find(kortti) != pelaajanNakematKortit.end();
}

void korttiNahty(const string& kortti);

// Kortin lisäys nähtyihin
void lisaaKorttiNahtyihin(const string& kortti);

const set<string>& getPelaajanNakematKortit() const;
const set<string>& getPelaajanNakematEpaillyt() const;
const set<string>& getPelaajanNakematAseet() const;
const set<string>& getPelaajanNakematHuoneet() const;

// Nähdyn kortin poisto
void poistaNahdytKortit(vector<string>& kortit) {
    for (const string& kortti : nakemattomatKortit) {
        kortit.erase(remove(kortit.begin(), kortit.end(), kortti), kortit.end());
    }
}

// Kortti näkemättömien listaan
void lisaaNakemattomiin(const string& kortti) {
    nakemattomatKortit.push_back(kortti);
}

// Näkemättömien korttien listaus
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

void poistaKortti(vector<string>& listaus, const string& kortti) {
    listaus.erase(remove(listaus.begin(), listaus.end(), kortti), listaus.end());
}

void katsoKortti(const string& kortti) {
    nakemattomatKortit.erase(remove(nakemattomatKortit.begin(), nakemattomatKortit.end(), kortti), nakemattomatKortit.end());
    nahdytKortit.push_back(kortti);
}

// Näkemättömäksi laitettavat kortit
// Pelaaja
vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};
// Vastustaja 1
vector<string> epaillyt1 = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
vector<string> aseet1 = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
vector<string> huoneet1 = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};
//Vastustaja 2
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

void naytaPelaajanKortit() const;
void listaaNahdytKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet,
                        const vector<string>& epaillyt1, const vector<string>& aseet1, const vector<string>& huoneet1,
                        const vector<string>& epaillyt2, const vector<string>& aseet2, const vector<string>& huoneet2, int& nro);

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
