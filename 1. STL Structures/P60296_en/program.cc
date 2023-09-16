#include <iostream>
#include <map>

using namespace std;

void print_ranking(const map<string, pair<bool, int>> &m)
{
    auto it = m.begin();
    cout << "RANKING" << endl;

    while (it != m.end()) {
        cout << it->first << " " << it->second.second << endl;

        ++it;
    }
}

void get_elo(map<string, pair<bool, int>> &m, const string &player) {
    auto it = m.find(player);

    cout << it->first << " " << it->second.second << endl;
}

void login(map<string, pair<bool, int>> &m, const string &player) {
    auto it = m.find(player);

    if (it == m.end()) {
        m.insert({player, {true, 1200}});
    }

    else {
        if (not it->second.first) {
            it->second.first = true;
        }
    }
}

void logout(map<string, pair<bool, int>>  &m, const string &player) {
    auto it = m.find(player);

    if (it->second.first) {
        it->second.first = false;
    }
}

void elo_change(map<string, pair<bool, int>> &m, const string &playerW, const string &playerL) {
    auto it1 = m.find(playerW);
    auto it2 = m.find(playerL);

    if (it1 == m.end() or it2 == m.end()) {
        cout << "player(s) not connected" << endl;
    }

    else {
        if (not it1->second.first or not it2->second.first) {
            cout << "player(s) not connected" << endl;
        }

        else {
            it1->second.second += 10;
            if (it2->second.second >= 1210) it2->second.second -= 10;
        }
    }
}

int main() {
    map<string, pair<bool, int>> player_elo;

    string command;

    while (cin >> command) {
        if (command == "LOGIN") {
            string player;
            cin >> player;
            login(player_elo, player);
        }

        else if (command == "LOGOUT") {
            string player;
            cin >> player;
            logout(player_elo, player);
        }

        else if (command == "GET_ELO") {
            string player;
            cin >> player;
            get_elo(player_elo, player);
        }

        else {
            string playerW, playerL;
            cin >> playerW >> playerL;
            elo_change(player_elo, playerW, playerL);
        }
    }

    print_ranking(player_elo);
}