#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

using namespace std;

void createCards(vector<string>& cards, vector<string>& conclusion);
void showConclusion(const vector<string>& conclusion);
void printEveryCard(const vector<string>& suspects, const vector<string>& weapons, const vector<string>& rooms);

#endif // CARD_H
