#include <bits/stdc++.h>
using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"  

void solve() {
    int x,y; cin >> x >> y;

    // if (x == 999 && y == 1) {YES; return;}
    // if (x - y == 26) {YES; return;}
    // if (x - y == 17) {YES; return;}
    // if (x - y == 8) {YES; return;}

    int diff = x-y;

    if (diff % 9 == 8) {YES; return;}

    if (x+1 == y) {YES; return;}

    NO;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
