#include <iostream>
#include <map>

using namespace std;

void win(map<string, int> &m, string name, int qt)
{
    map<string, int>::iterator it = m.find(name);

    if (it == m.end())
    {
        cout << name << " is not in the casino" << endl;
    }
    else
    {
        it->second += qt;
    }
}

void leave(map<string, int> &m, string name)
{
    map<string, int>::iterator it = m.find(name);

    if (it == m.end()) {
        cout << name << " is not in the casino" << endl;
    }

    else {
        cout << it->first << " has won " << it->second << endl;
        m.erase(it);
    }
}

void enter(map<string, int> &m, string name)
{
    map<string, int>::iterator it = m.find(name);

    if (it == m.end()) {
        m.insert({name, 0});
    }

    else {
        cout << name << " is already in the casino" << endl;
    }
}

void final_points(map<string, int>& m) {
    map<string, int>::iterator it = m.begin();

    cout << "----------" << endl;

    while (it != m.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}

int main()
{
    map<string, int> m;

    string name, action, number;

    while (cin >> name >> action) {
        if (action == "enters") {
            enter(m, name);
        }

        else if (action == "leaves") {
            leave(m, name);
        }

        else {
            int qt;
            cin >> qt;

            win(m, name, qt);
        }
    }

    final_points(m);
}