#include<iostream>
#include<map>

using namespace std;

int collatz(int x, int y, int n) {
    map<int, int> m;
    m.insert(make_pair(n, 0));
    int i = 0;
    while (n<=1e8) {
        if (n % 2 == 0) { // Par
            n = (n/2)+x;
        }

        else { // Impar
            n = 3*n + y;
        }

        if (m.find(n)==m.end()) {
            m.insert(make_pair(n, i));
        }

        else {
            return i-m[n];
        }
    }

    return n;
}

int main() {
    int x, y, n;

    while (cin >> x >> y >> n) {
        cout << collatz(x, y, n) << endl;
    }
}