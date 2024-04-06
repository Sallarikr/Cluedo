#ifndef PELAAJA_H
#define PELAAJA_H
#include <string>
#include <vector>

using namespace std;

class Pelaaja {
public:
    Pelaaja(const string& nimi) : nimi(nimi) {}
    void lisaaKortti(const string& kortti);
    const vector<string>& getPelaajallaOlevatKortit() const {
        return pelaajallaOlevatKortit;
    }
    const string& getNimi() const {
        return nimi;
    }
private:
    string nimi;
    vector<string> pelaajallaOlevatKortit;
};

void luoPelaajat(vector<Pelaaja>& pelaajat);
void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat);
void jaaKortit(vector<Pelaaja>& pelaajat, vector<string>& kortit);

#endif // PELAAJA_H
