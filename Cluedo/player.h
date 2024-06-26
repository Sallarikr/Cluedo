#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include <string>
#include <vector>

using namespace std;

class Player {
    public:
    Player(const string& playerName);
    void addCard(const string& card);

    // The player's cards
    const vector<string>& getPlayerCards() const {
        return playerCards;
    }

    string getName() const;
    bool inHand(const string& card) const;

    // If the card has been seen
    bool cardWasSeen(const string& card) const {
        return cardsSeenByPlayer.find(card) != cardsSeenByPlayer.end();
    }

    void sawCard(const string& card);

    // Adding the card to seen cards
    void addCardToSeen(const string& card);

    const set<string>& getCardsSeenByPlayer() const;
    const set<string>& getSuspectsSeenByPlayer() const;
    const set<string>& getWeaponsSeenByPlayer() const;
    const set<string>& getRoomsSeenByPlayer() const;

    // Listing the unseen cards
    const vector<string>& getUnseenCards() const {
        return unseenCards;
    }

    // Cards to be made unseen at the start
    // Players
    vector<string> suspects = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};
    // Opponent 1
    vector<string> suspects1 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons1 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms1 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};
    //Opponent 2
    vector<string> suspects2 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons2 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms2 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

    Player(const vector<string>& suspects, const vector<string>& weapons, const vector<string>& rooms) {
        // Add the cards to the unseen
        unseenCards.reserve(suspects.size() + weapons.size() + rooms.size());
        unseenCards.insert(unseenCards.end(), suspects.begin(), suspects.end());
        unseenCards.insert(unseenCards.end(), weapons.begin(), weapons.end());
        unseenCards.insert(unseenCards.end(), rooms.begin(), rooms.end());
    }

    void showPlayerCards() const;
    void listSeenCards(const vector<string>& suspects, const vector<string>& weapons, const vector<string>& rooms,
                       const vector<string>& suspects1, const vector<string>& weapons1, const vector<string>& rooms1,
                       const vector<string>& suspects2, const vector<string>& weapons2, const vector<string>& rooms2, int& number);

    private:
    string name;
    vector<string> playerCards;
    vector<string> seenCards;
    set<string> suspectsSeenByPlayer;
    set<string> weaponsSeenByPlayer;
    set<string> roomsSeenByPlayer;
    set<string> cardsSeenByPlayer;
    vector<string> unseenCards;
};

void showPlayerCards(const vector<Player>& players);
void dealCards(vector<Player>& players, vector<string>& cards);
void listSeenCards(const vector<Player>& players);


#endif // PLAYER_H
