#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include "card.h"
#include "player.h"

using namespace std;

// Checking the accusation
bool checkAccusation(const vector<string>& conclusion, const string& accusationCard) {
    return find(conclusion.begin(), conclusion.end(), accusationCard) != conclusion.end();
}

// Randomizing the cards for suspections
string randomCard(const vector<string>& listing) {
    if (listing.empty()) return "";
    // Generate a random number for the card list
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, listing.size() - 1);
    // Generate a random index
    int randomIndex = dis(gen);
    // Get a random card
    return listing[randomIndex];
}

// Printing the cards
void printEveryCard(const vector<string>& suspects, const vector<string>& weapons, const vector<string>& rooms,
             const vector<string>& suspects1, const vector<string>& weapons1, const vector<string>& rooms1,
             const vector<string>& suspects2, const vector<string>& weapons2, const vector<string>& rooms2, const Player& player, int& number) {
    cout << "Cards you haven't seen yet:" << endl;
    cout << endl;

    // The player's cards
    if (number == 0) {

        // Printing the suspects
        cout << "Suspects:" << endl;
        for (const auto& suspect : suspects) {
            if (!player.inHand(suspect)) {
                cout << suspect << ", ";
            }
        }

        // Printing design
        cout << endl;
        cout << endl;

        // Printing the weapons
        cout << "Weapons:" << endl;
        for (const auto& weapon : weapons) {
            if (!player.inHand(weapon)) {
                cout << weapon << ", ";
            }
        }

        // Printing design
        cout << endl;
        cout << endl;

        // Printing the rooms
        cout << "Rooms:" << endl;
        for (const auto& room : rooms) {
            if (!player.inHand(room)) {
                cout << room << ", ";
            }
        }
        // Printing design
        cout << endl;
    }

    // For coding: cards of Opponent 1
    else if (number == 1) {

        // Printing the suspects
        cout << "Suspects:" << endl;
        for (const auto& suspect1 : suspects1) {
            if (!player.inHand(suspect1)) {
                   cout << suspect1 << ", ";
            }
        }
        cout << endl;

        // Printing the weapons
        cout << "Weapons:" << endl;
        for (const auto& weapon1 : weapons1) {
            if (!player.inHand(weapon1)) {
                cout << weapon1 << ", ";
            }
        }
        cout << endl;

        // Printing the rooms
        cout << "Rooms:" << endl;
        for (const auto& room1 : rooms1) {
            if (!player.inHand(room1)) {
                cout << room1 << ", ";
            }
        }
    }

    // For coding: cards of Opponent 2
    else if (number == 2) {

        // Printing the suspects
        cout << "Suspects:" << endl;
        for (const auto& suspect2 : suspects2) {
            if (!player.inHand(suspect2)) {
                cout << suspect2 << ", ";
            }
        }
        cout << endl;

        // Printing the weapons
        cout << "Weapons:" << endl;
        for (const auto& weapon2 : weapons2) {
            if (!player.inHand(weapon2)) {
                cout << weapon2 << ", ";
            }
        }
        cout << endl;

        // Printing the rooms
        cout << "Rooms:" << endl;
        for (const auto& room2 : rooms2) {
            if (!player.inHand(room2)) {
                cout << room2 << ", ";
            }
        }
    }
}

// Remove the cards from the player's To be asked-cards
void removeFromToBeAsked(vector<string>& suspects, vector<string>& weapons, vector<string>& rooms, const string& card) {
    suspects.erase(remove(suspects.begin(), suspects.end(), card), suspects.end());
    weapons.erase(remove(weapons.begin(), weapons.end(), card), weapons.end());
    rooms.erase(remove(rooms.begin(), rooms.end(), card), rooms.end());
}

// Remove the cards from Opponent 1's To be asked-cards
void removeFromToBeAsked1(vector<string>& suspects1, vector<string>& weapons1, vector<string>& rooms1, const string& card1) {
    suspects1.erase(remove(suspects1.begin(), suspects1.end(), card1), suspects1.end());
    weapons1.erase(remove(weapons1.begin(), weapons1.end(), card1), weapons1.end());
    rooms1.erase(remove(rooms1.begin(), rooms1.end(), card1), rooms1.end());
}

// Remove the cards from Opponent 2's To be asked-cards
void removeFromToBeAsked2(vector<string>& suspects2, vector<string>& weapons2, vector<string>& rooms2, const string& card2) {
    suspects2.erase(remove(suspects2.begin(), suspects2.end(), card2), suspects2.end());
    weapons2.erase(remove(weapons2.begin(), weapons2.end(), card2), weapons2.end());
    rooms2.erase(remove(rooms2.begin(), rooms2.end(), card2), rooms2.end());
}


int main()
{
    // Creation of players
    vector<Player> players;
    // Adding names
    players.push_back(Player("You"));
    players.push_back(Player("Opponent 1"));
    players.push_back(Player("Opponent 2"));

    // Creating the cards
    vector<string> cards;
    vector<string> conclusion;
    createCards(cards, conclusion);

    // Dealing the cards
    dealCards(players, cards);
    // For coding: printing every player's hand
    // showPlayerCards(players);

    // Alternating between players
    int hasATurn = 0;

    // For moving on in the game
    string pressingEnter;

    // The game continues until a victory or a loss
    bool gameOver = false;;

    // Creating cards to be asked for the player
    vector<string> suspects = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

    // Creating cards to be asked for Opponent 1
    vector<string> suspects1 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons1 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms1 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

    // Creating cards to be asked for Opponent 2
    vector<string> suspects2 = {"Reverend Green", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Professor Plum", "Miss Scarlett"};
    vector<string> weapons2 = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench"};
    vector<string> rooms2 = {"Ballroom", "Billiard room", "Conservatory", "Dining room", "Hall", "Kitchen", "Library", "Lounge", "Study"};

    // Creating a base for player to be asked for the opponents
    int opponent1Asks = 0;
    int opponent2Asks = 0;

    // Counting turns for oppponents to change the player they ask cards from
    int opponent1Turn = 1;
    int opponent2Turn = 1;


    // The game goes on until a victory or a loss
    while(!gameOver) {
        Player playing = players[hasATurn];
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << + "Up next in turn: "  + playing.getName() << ". Press enter to continue";
        getline(cin, pressingEnter); // Using getline to avoid having to press enter twice
        cin.clear();

        if(hasATurn == 0) {
            int number = 0;
            cout << endl;

            // Printing the cards to be asked
            printEveryCard(suspects, weapons, rooms, suspects1, weapons1, rooms1, suspects2, weapons2, rooms2, players[0], number);

            // Printing design
            cout << endl;
            cout << "*************************************************************" << endl;
            cout << endl;

            // Asking the player if they want to suspect or accuse
            int choice;
            // If input is not 1 or 2 the question repeats
            do {
                cout << "Do you want to suspect or make an accusation? (Suspection = 1, Accusation = 2)" << endl;
                cout << "Your choice: ";
                cin >> choice;
                if(cin.fail()) {
                    cout << endl;
                    cout << "Please give an answer of 1 or 2!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if(choice != 1 && choice != 2) {
                    cout << endl;
                    cout << "Please give an answer of 1 or 2!" << endl;
                }
            } while(choice != 1 && choice != 2);

            // If suspecting
            if(choice == 1) {
                int opponent;
                do {
                    // Deciding an opponent to ask cards from
                    cout << endl;
                    cout << "Who do you want to ask cards from? (Opponent 1 = 1, Opponent 2 = 2)" << endl;
                    cout << "Your choice: ";
                    cin >> opponent;
                    if(cin.fail()) {
                        cout << "Please give an answer of 1 or 2!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if(opponent != 1 && opponent != 2) {
                        cout << endl;
                        cout << "Please give an answer of 1 or 2!" << endl;
                    }
                } while(opponent != 1 && opponent != 2);
                cout << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the input so that the suspect's whole name works in the code

                // Choosing the cards to be asked
                string suspectToBeAsked;
                cout << "I suspect that the murderer is "; // Input concludes the sentence
                // For the whole name to work, using getline and sstream
                getline(cin, suspectToBeAsked);

                string weaponToBeAsked;
                cout << "I suspect that the weapon was a "; // // Input concludes the sentence
                getline(cin, weaponToBeAsked);

                string roomToBeAsked;
                cout << "I suspect that the room was "; // // Input concludes the suspection
                getline(cin, roomToBeAsked);
                // Printing design
                cout << endl;
                cout << "*************************************************************" << endl;
                cout << endl;

                // Asking the cards from the chosen opponent. If the card it seen, it is removed from the To be asked-cards
                // Checking the suspect card
                if(players[opponent].inHand(suspectToBeAsked) && !players[0].cardWasSeen(suspectToBeAsked)) {
                    cout << "The opponent had the card " + suspectToBeAsked << endl;
                    players[0].addCardToSeen(suspectToBeAsked);
                    removeFromToBeAsked(suspects, weapons, rooms, suspectToBeAsked);
                    // Checking the weapon card
                } else if(players[opponent].inHand(weaponToBeAsked) && !players[0].cardWasSeen(weaponToBeAsked)) {
                    cout << "The opponent had the card " + weaponToBeAsked << endl;
                    players[0].addCardToSeen(weaponToBeAsked);
                    removeFromToBeAsked(suspects, weapons, rooms, weaponToBeAsked);
                }
                // Checking the room card
                else if(players[opponent].inHand(roomToBeAsked) && !players[0].cardWasSeen(roomToBeAsked)) {
                    cout << "The opponent had the card " + roomToBeAsked << endl;
                    players[0].addCardToSeen(roomToBeAsked);
                    removeFromToBeAsked(suspects, weapons, rooms, roomToBeAsked);
                } else {
                    // If no cards were seen
                    cout << "The opponent had none of the cards you asked!";
                    cout << endl;
                }
                cout << endl;
                cout << + "Press enter to continue";
                getline(cin, pressingEnter); // Using getline to avoid having to press enter twice
                cin.clear();
            }

            // If making an accusation
            else if (choice == 2) {
                cout << endl;
                cout << "Give your accusation: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the input for the suspects whole name to work in the code

                // For coding: showing the conclusion
                // showConclusion(conclusion);

                string suspectToBeAsked;
                cout << "I accuse that the murderer is "; // Input concludes the sentence
                // For the whole name to work, using getline and sstream
                getline(cin, suspectToBeAsked);
                stringstream stream(suspectToBeAsked);
                string input;

                string weaponToBeAsked;
                cout << "The weapon was a "; // Input concludes the sentence
                cin >> weaponToBeAsked;

                string roomToBeAsked;
                cout << "The room was "; // Input concludes the accusation
                cin >> roomToBeAsked;

                // Foundation for the checking
                int amount = 0;

                // Correct accusations to amounts
                if(checkAccusation(conclusion, suspectToBeAsked)) {
                    ++amount;
                }

                if(checkAccusation(conclusion, weaponToBeAsked)) {
                    ++amount;
                }

                if(checkAccusation(conclusion, roomToBeAsked)) {
                    ++amount;
                }

                // Printing design
                cout << endl;
                cout << "*************************************************************" << endl;

                // If the accusation was wrong
                if(amount != 3) {
                    cout << endl;
                    cout << "Oh dear, your accusation was incorrect!" << endl;
                    cout << endl;
                    cout << "The correct conclusion is: " << endl;
                    showConclusion(conclusion);
                    cout << endl;
                    gameOver = true;
                }
                // If the accusation was correct
                else {
                    cout << endl;
                    cout << "Congratulations, you won!" << endl;
                    cout << endl;
                    gameOver = true;
                }
            }

            // Claring the input so that the next player's turn works correctly
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();

            // For coding: printing every player's cards
            //   showPlayerCards(players);

        }  else if (hasATurn == 1) {
            // For coding: printing the To be asked-cards for Opponent 1
            // int number = 1;
            // printEveryCard(suspects, weapons, rooms, suspects1, weapons1, rooms1, suspects2, weapons2, rooms2, players[1], number);

            string opponent1RandomSuspect = randomCard(suspects1);
            string opponent1RandomWeapon = randomCard(weapons1);
            string opponent1RandomRoom = randomCard(rooms1);

            // Remove the opponents own cards from To be asked-cards
            for (const auto& suspect1 : suspects1) {
                if (players[1].inHand(suspect1)) {
                    removeFromToBeAsked1(suspects1, weapons1, rooms1, suspect1);
                }
            }
            for (const auto& weapon1 : weapons1) {
                if (players[1].inHand(weapon1)) {
                    removeFromToBeAsked1(suspects1, weapons1, rooms1, weapon1);
                }
            }
            for (const auto& room1 : rooms1) {
                if (players[1].inHand(room1)) {
                    removeFromToBeAsked1(suspects1, weapons1, rooms1, room1);
                }
            }

            // Alternating the opponent to be asked
            if (opponent1Turn % 2 == 0) {
                // Asking from the player
                opponent1Asks = 0;
            }
            else {
                // Asking from Opponent 2
                opponent1Asks = 2;
            }

            // Printing the asked player's name
            string askedByOpponent1;
            if(opponent1Asks == 0) {
                askedByOpponent1 = "you";
            } else if(opponent1Asks == 2) {
                askedByOpponent1 = "Opponent 2";
            }

            // Printing design
            cout << endl;

            // If the opponent has the accusation, the game ends
            if ((suspects1.size() == 1 && rooms1.size() == 1 && weapons1.size() == 1)) {
                cout << "Opponent 1 won the game with their accusation. The Murderer was  " + suspects1[0] + ", the weapon was " + weapons1[0] + " and the room was " + rooms1[0] << endl;
                break;
            }

            // Removing a seen card from the To be asked-cards
            if(players[opponent1Asks].inHand(opponent1RandomSuspect)) {
                players[1].addCardToSeen(opponent1RandomSuspect);
                cout << "Opponent 1 saw one of the cards they asked from " + askedByOpponent1 << endl;
                removeFromToBeAsked1(suspects1, weapons1, rooms1, opponent1RandomSuspect);
            } else if(players[opponent1Asks].inHand(opponent1RandomWeapon)) {
                players[1].addCardToSeen(opponent1RandomWeapon);
                cout << "Opponent 1 saw one of the cards they asked from " + askedByOpponent1 << endl;
                removeFromToBeAsked1(suspects1, weapons1, rooms1, opponent1RandomWeapon);
            } else if(players[opponent1Asks].inHand(opponent1RandomRoom)) {
                players[1].addCardToSeen(opponent1RandomRoom);
                cout << "Opponent 1 saw one of the cards they asked from " + askedByOpponent1 << endl;
                removeFromToBeAsked1(suspects1, weapons1, rooms1, opponent1RandomRoom);
            } else {
                cout << "Opponent 1 didn't see any of the cards they asked from " + askedByOpponent1 << endl;
            }

            // Printing design
            cout << endl;

            // Printing the cards that the opponent asked
            cout << "Opponent " << hasATurn << " suspected " << opponent1RandomSuspect << endl;
            cout << "Opponent " << hasATurn << " suspected " << opponent1RandomWeapon << endl;
            cout << "Opponent " << hasATurn << " suspected " << opponent1RandomRoom << endl;

            ++opponent1Turn;

            // Printing design
            cout << endl;
            cout << "Press enter to continue";
            getline(cin, pressingEnter); // Using getline to avoid having to press enter twice
            cin.clear();
        } else if (hasATurn==2){
            // For coding: printing the To be asked-cards for Opponent 2
            // int number = 2;
            // printEveryCard(suspects, weapons, rooms, suspects1, weapons1, rooms1, suspects2, weapons2, rooms2, players[2], number);

            string opponent2RandomSuspect = randomCard(suspects2);
            string opponent2RandomWeapon = randomCard(weapons2);
            string opponent2RandomRoom = randomCard(rooms2);

            // Remove the opponents own cards from To be asked-cards
            for (const auto& suspect2 : suspects2) {
                if (players[2].inHand(suspect2)) {
                    removeFromToBeAsked2(suspects2, weapons2, rooms2, suspect2);
                }
            }
            for (const auto& weapon2 : weapons2) {
                if (players[2].inHand(weapon2)) {
                    removeFromToBeAsked2(suspects2, weapons2, rooms2, weapon2);
                }
            }
            for (const auto& room2 : rooms2) {
                if (players[2].inHand(room2)) {
                    removeFromToBeAsked2(suspects2, weapons2, rooms2, room2);
                }
            }

            // Alternating the opponent to be asked
            if (opponent2Turn % 2 == 0) {
                // Asking from Opponent 1
                opponent2Asks = 1;
            }
            else {
                // Asking from the player
                opponent2Asks = 0;
            }

            // Printing the asked player's name
            string askedByOpponent2;
            if(opponent2Asks == 0) {
                askedByOpponent2 = "you";
            } else if(opponent2Asks == 1) {
                askedByOpponent2 = "Opponent 1";
            }

            // Printing design
            cout << endl;

            // If the opponent has the accusation, the game ends
            if ((suspects2.size() == 1 && rooms2.size() == 1 && weapons2.size() == 1)) {
                cout << "Opponent 2 won the game with their accusation. The Murderer was  " + suspects2[0] + ", the weapon was " + weapons2[0] + " and the room was " + rooms2[0] << endl;
                break;
            }

            // Removing a seen card from the To be asked-cards
               if(players[opponent2Asks].inHand(opponent2RandomSuspect)) {
                players[2].addCardToSeen(opponent2RandomSuspect);
                cout << "Opponent 2 saw one of the cards they asked from " + askedByOpponent2 << endl;
            } else if(players[opponent2Asks].inHand(opponent2RandomWeapon)) {
                players[2].addCardToSeen(opponent2RandomWeapon);
                cout << "Opponent 2 saw one of the cards they asked from " + askedByOpponent2 << endl;
                removeFromToBeAsked2(suspects2, weapons2, rooms2, opponent2RandomWeapon);
            } else if(players[opponent2Asks].inHand(opponent2RandomRoom)) {
                players[2].addCardToSeen(opponent2RandomRoom);
                cout << "Opponent 2 saw one of the cards they asked from " + askedByOpponent2 << endl;
                removeFromToBeAsked2(suspects2, weapons2, rooms2, opponent2RandomRoom);
            } else {
                cout << "Opponent 2 didn't see any of the cards they asked from " + askedByOpponent2 << endl;
            }

            // Printing design
            cout << endl;

            // Printing the cards that the opponent asked
            cout << "Opponent " << hasATurn << " suspected " << opponent2RandomSuspect << endl;
            cout << "Opponent " << hasATurn << " suspected " << opponent2RandomWeapon << endl;
            cout << "Opponent " << hasATurn << " suspected " << opponent2RandomRoom << endl;

            ++opponent2Turn;

            // Printing design
            cout << endl;
            cout << "Press enter to continue";
            getline(cin, pressingEnter); // Using getline to avoid having to press enter twice
            cin.clear();
        }
        hasATurn = (hasATurn + 1) % players.size();
    }
    return 0;
}
