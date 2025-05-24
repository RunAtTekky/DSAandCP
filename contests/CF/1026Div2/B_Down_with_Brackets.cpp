#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    string s; cin >> s;

    int open = 0, close = 0, total = 0;

    for (auto &ch : s) {
        if (ch == '(') open++;
        if (ch == ')') close++;

        if (open == close) total++;

    }
    if (total == 1) {NO;}
    else {YES;}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
