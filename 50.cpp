#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> player1, player2;
    int card;
    for (int i = 0; i < 5; i++) {
        cin >> card;
        player1.push_back(card + 1);
    }

    for (int i = 0; i < 5; i++) {
        cin >> card;
        player2.push_back(card + 1);
    }

    int moves = 0;
    bool botva = false;

    while (!player1.empty() && !player2.empty() && moves < 1000000) {
        int card1 = player1.front();
        int card2 = player2.front();

        player1.erase(player1.begin());
        player2.erase(player2.begin());

        if ((card1 > card2 && card2 != 1) || (card2 == 1 && card1 != 10)) {
            player1.push_back(card1);
            player1.push_back(card2);
        }
        if ((card1 < card2 && card1 != 1) || (card1 == 1 && card2 != 10)) {
            player2.push_back(card1);
            player2.push_back(card2);
        }
        if (card1 == 1 && card2 == 10) {
            player1.push_back(card1);
            player1.push_back(card2);
        }
        if (card1 == 10 && card2 == 1) {
            player2.push_back(card1);
            player2.push_back(card2);
        }

        moves++;
    }

    if (moves == 1000000 && (!player1.empty() || !player2.empty())) {
        botva = true;
    }

    if (botva) {
        cout << "botva" << endl;
    }
    else if (player1.empty()) {
        cout << "second " << moves << endl;
    }
    else {
        cout << "first " << moves << endl;
    }

    return 0;
}