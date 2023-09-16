#include<iostream>
#include<set>

using namespace std;

string th_element(set<string>& s, int th) {
    set<string>::iterator it = s.begin();
    for (int i = 0; i < th; ++i) it++;
    return *(it);
}

int main() {
    set<string> s;
    string s0;
    int counter = 0;

    bool par = true;
    cin >> s0;
    while (s0 != "END") {
        s.insert(s0);
        ++counter;

        cout << th_element(s, (counter+1)/2) << endl;

        cin >> s0;
    }

}