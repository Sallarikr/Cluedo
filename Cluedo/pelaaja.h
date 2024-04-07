#ifndef PELAAJA_H
#define PELAAJA_H
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

private:
    string nimi;
    vector<string> pelaajallaOlevatKortit;
};

void naytaPelaajanKortit(const vector<Pelaaja>& pelaajat);
void jaaKortit(vector<Pelaaja>& pelaajat, vector<string>& kortit);

#endif // PELAAJA_H
