#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "kortti.h"

    using namespace std;

void luoKortit(vector<string>& kortit, vector<string>& ratkaisu) {
    // Epäiltyjen, aseiden ja huoneiden luominen korteiksi
    vector<string> epaillyt = {"Pastori Viherlevä", "Eversti Keltanokka", "Tohtori Pinkkilä", "Rouva Siniverinen", "Professori Purppuravalo", "Neiti Punakulta"};
    vector<string> aseet = {"Kynttilänjalka", "Tikari", "Putki", "Revolveri", "Köysi", "Jakoavain"};
    vector<string> huoneet = {"Tanssisali", "Biljardihuone", "Kasvihuone", "Ruokasali", "Kylpyhuone", "Keittiö", "Kirjasto", "Lepohuone", "Työhuone"};

    // Korttien sekoitus
    srand(time(nullptr));
    random_shuffle(epaillyt.begin(), epaillyt.end());
    random_shuffle(aseet.begin(), aseet.end());
    random_shuffle(huoneet.begin(), huoneet.end());

    // Otetaan sekoitetuista korteista erikseen yksi epäilty-, ase- ja huonekortti, ja sijoitetaan ne ratkaisuksi
    ratkaisu.push_back(epaillyt.back());
    epaillyt.pop_back();
    ratkaisu.push_back(aseet.back());
    aseet.pop_back();
    ratkaisu.push_back(huoneet.back());
    huoneet.pop_back();

    // Kootaan jäljelle jääneet kortit ja kootaan ne pakaksi
    for(const auto& epailty : epaillyt) {
        kortit.push_back(epailty);
    }
    for(const auto& ase : aseet) {
        kortit.push_back(ase);
    }
    for(const auto&huone : huoneet) {
        kortit.push_back(huone);
    }
    // Sekoitetaan korttipakka
    random_shuffle(kortit.begin(), kortit.end());
}



// Ratkaisun näyttäminen
void naytaRatkaisu(const vector<string>& ratkaisu) {
    for(const auto& kortti : ratkaisu) {
        cout << kortti << endl;
    }
}
