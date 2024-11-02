#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

string s;
int n;

map<int, bool> isCorrect;

void solve(int index, char value) {
    s[index] = value;

    int starting_position = max(0, index-3);
    int ending_position = min(n-1, index+3);

    bool found = false;
    for (int i=starting_position; i<=index; i++) {
        if (s.substr(i,4) == "1100") {
            isCorrect[i] = true;
            found = true;
        }
        else isCorrect.erase(i);
    }

    if (found) {
        YES; return;
    }

    for (auto [position, val] : isCorrect) {
        if (!val) continue;
        if (s.substr(position,4) == "1100") {
            YES; return;
        }
    }

    NO;
}

void solve() {
    cin >> s;

    n = s.size();

    for (int i=0; i+4<=n; i++) {
        if (s.substr(i,4) == "1100") isCorrect[i] = true;
    }

    int q; cin >> q;

    while (q--) {
        int index;
        char value;
        cin >> index;
        cin >> value;

        solve(index-1, value);
    }
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
