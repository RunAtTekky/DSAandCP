/*
Tourist's code
My code was similar but this is more optimised and readable
*/

#include <bits/stdc++.h>
using namespace std;

set<int> positions;
string s; 
int n;

void update(int index) {
    if (index < 0 || index + 4 > n) return;

    if (s.substr(index,4) == "1100") positions.insert(index);
    else positions.erase(index);
}

void solve() {
    cin >> s;
    n = s.size();

    positions.clear();

    for (int i=0; i+4<=n; i++) {
        update(i);
    }

    int q; cin >> q;

    while (q--) {
        int index; cin >> index;
        char value; cin >> value;

        index--;
        s[index] = value;

        for (int i=index-3; i<=index; i++) {
            update(i);
        }

        cout << ((positions.empty()) ? "NO" : "YES") << "\n";
    }
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
