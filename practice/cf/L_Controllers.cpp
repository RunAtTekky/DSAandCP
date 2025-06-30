#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll n; cin >> n;
    string game; cin >> game;
    
    ll controllers; cin >> controllers;

    ll positive = count(game.begin(), game.end(), '+');
    ll negative = count(game.begin(), game.end(), '-');

    for (int i=0; i<controllers; i++) {
        ll x,y; cin >> x >> y;

        if (positive - negative == 0) {
            YES; continue;
        }

        if (x == y) {
            NO; continue;
        }

        double k = (y * (positive - negative)) / (1.0 * (y - x));

        if (k != (int)(k)) {
            NO; continue;
        }

        if (k >= -1*negative && k <= positive) {
            YES;
        } else {
            NO;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
