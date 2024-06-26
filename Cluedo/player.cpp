#include <iostream>
#include <algorithm>
#include "player.h"

using namespace std;

Player::Player(const string& playerName) : name(playerName) {}

// Getting the player's names
string Player::getName() const {
    return name;
}

// Giving a card to players
void Player::addCard(const string& card) {
    playerCards.push_back(card);
}

// Distributing the deck between players
void dealCards(vector<Player>& players, vector<string>& cards) {
    size_t playerAmount = players.size();
    size_t playerCardsAmount = cards.size() / playerAmount;
    for(size_t i = 0; i < playerAmount; ++i) {
        for(size_t j = 0; j < playerCardsAmount; ++j) {
            players[i].addCard(cards.back());
            cards.pop_back();
        }
    }
}

// Showing all of the cards a player has
void showPlayerCards(const vector<Player>& players) {
    for(const auto& player : players) {
        cout << player.getName() + "'s cards:" << endl;
        for(const auto& card : player.getPlayerCards()) {
            cout << card << ", ";
        }
        cout << endl;
    }
}

// Asking a card from a player
bool Player::inHand(const string& card) const {
    return find(playerCards.begin(), playerCards.end(), card) != playerCards.end();
}

// Listing of the cards for suspection
// Player
vector<string> suspects = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
vector<string> weapons = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
vector<string> rooms = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};
// Opponent 1
vector<string> suspects1 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
vector<string> weapons1 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
vector<string> rooms1 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};
// Opponent 2
vector<string> suspects2 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
vector<string> weapons2 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
vector<string> rooms2 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

void Player::listSeenCards(const vector<string>& suspects, const vector<string>& weapons, const vector<string>& rooms,
                     const vector<string>& suspects1, const vector<string>& weapons1, const vector<string>& rooms1,
                     const vector<string>& suspects2, const vector<string>& weapons2, const vector<string>& rooms2, int& number) {
    cout << name + "'s seen cards: " << endl;
    cout << "Suspects: ";
    if(number == 0) {
        for(const auto& card : cardsSeenByPlayer) {
            if (find(suspects.begin(), suspects.end(), card) != suspects.end()) {
                cout << card << ", ";
            }
        }
    } else if (number == 1){
        for(const auto& card1 : cardsSeenByPlayer) {
            if (find(suspects1.begin(), suspects1.end(), card1) != suspects1.end()) {
                cout << card1 << ", ";
            }
        }
    } else if (number == 2) {
        for(const auto& card2 : cardsSeenByPlayer) {
            if (find(suspects2.begin(), suspects2.end(), card2) != suspects2.end()) {
                cout << card2 << ", ";
            }
        }
    }

    cout << endl;

    cout << "Weapons: ";
    if(number == 0) {
        for(const auto& card : cardsSeenByPlayer) {
            if (find(weapons.begin(), weapons.end(), card) != weapons.end()) {
                cout << card << ", ";
            }
        }
    } else if(number == 1) {
        for(const auto& card1 : cardsSeenByPlayer) {
            if (find(weapons1.begin(), weapons1.end(), card1) != weapons1.end()) {
                cout << card1 << ", ";
            }
        }
    } else if (number == 2) {
        for(const auto& card2 : cardsSeenByPlayer) {
            if (find(weapons2.begin(), weapons2.end(), card2) != weapons2.end()) {
                cout << card2 << ", ";
            }
        }
    }
    cout << endl;

    cout << "Rooms: ";
    if(number == 0){
        for(const auto& card : cardsSeenByPlayer) {
            if (find(rooms.begin(), rooms.end(), card) != rooms.end()) {
                cout << card << ", ";
            }
        }
    } else if (number == 1) {
        for(const auto& card1 : cardsSeenByPlayer) {
            if (find(rooms1.begin(), rooms1.end(), card1) != rooms1.end()) {
                cout << card1 << ", ";
            }
        }
    }
    else if (number == 2) {
        for(const auto& card2: cardsSeenByPlayer) {
            if (find(rooms2.begin(), rooms2.end(), card2) != rooms2.end()) {
                cout << card2 << ", ";
            }
        }
    }
    cout << endl;
}

void Player::sawCard(const string& card) {
    seenCards.push_back(card);
}

const set<string>& Player::getSuspectsSeenByPlayer() const {
    return suspectsSeenByPlayer;
}

const set<string>& Player::getWeaponsSeenByPlayer() const {
    return weaponsSeenByPlayer;
}

const set<string>& Player::getRoomsSeenByPlayer() const {
    return roomsSeenByPlayer;
}

void Player::addCardToSeen(const string& card) {
    cardsSeenByPlayer.insert(card);
}

const set<string>& Player::getCardsSeenByPlayer() const {
    return cardsSeenByPlayer;
}
