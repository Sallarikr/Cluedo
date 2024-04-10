#ifndef KORTTI_H
#define KORTTI_H
#include <string>
#include <vector>

using namespace std;

void luoKortit(vector<string>& kortit, vector<string>& ratkaisu);
void naytaRatkaisu(const vector<string>& ratkaisu);
void tulostaKaikkiKortit(const vector<string>& epaillyt, const vector<string>& aseet, const vector<string>& huoneet);

#endif // KORTTI_H
