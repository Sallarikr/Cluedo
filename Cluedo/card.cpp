#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "card.h"

using namespace std;

void createCards(vector<string>& cards, vector<string>& conclusion) {
    // Creating cards for suspects, weapons and rooms
    vector<string> suspects = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

    // Shuffling the cards
    srand(time(nullptr));
    random_shuffle(suspects.begin(), suspects.end());
    random_shuffle(weapons.begin(), weapons.end());
    random_shuffle(rooms.begin(), rooms.end());

    // Extracting one card from suspects, weapons and rooms and placing them to the conclusion
    conclusion.push_back(suspects.back());
    suspects.pop_back();
    conclusion.push_back(weapons.back());
    weapons.pop_back();
    conclusion.push_back(rooms.back());
    rooms.pop_back();

    // Gathering the remaining cards to a deck
    for(const auto& suspect : suspects) {
        cards.push_back(suspect);
    }
    for(const auto& weapon : weapons) {
        cards.push_back(weapon);
    }
    for(const auto&room : rooms) {
        cards.push_back(room);
    }
    // Shuffling the deck
    random_shuffle(cards.begin(), cards.end());
}

// Showing the conclusion
void showConclusion(const vector<string>& conclusion) {
    for(const auto& card : conclusion) {
    cout << card << endl;
    }
}
