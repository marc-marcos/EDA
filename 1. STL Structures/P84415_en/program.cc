#include<iostream>
#include<map>

using namespace std;

void store(string w, map<string, int>& m) {
    if (m.find(w) != m.end()) {
        (m.find(w))->second++;
    }

    else {
        m.insert(make_pair(w, 1));
    }
}

void maximum(map<string, int>& m) {
    if (m.end() == m.begin()) {
        cout << "indefinite maximum" << endl;
    }

    else {
        map<string, int>::iterator it = m.end(); 
        it--;
        cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
    }

}

void minimum(map<string, int>& m) {
    if (m.end() == m.begin()) {
        cout << "indefinite minimum" << endl;
    }

    else {
        map<string, int>::iterator it = m.begin(); 
        cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
    }
}

void remove(map<string, int>& m, string w) {
    map<string, int>::iterator it = m.find(w);

    if (it->second == 1) {
        m.erase(it);
    }

    else {
        it->second--;
    }
}



int main() {
    string option;
    map<string, int> w;

    while (cin >> option) {
        if (option == "minimum?") {
            minimum(w);
        }

        else if (option == "maximum?") {
            maximum(w);
        }

        else if (option == "delete") {
            string p;
            cin >> p;
            remove(w, p);
        }

        else if (option == "store") {
            string p;
            cin >> p;
            store(p, w);
        }
    }
}