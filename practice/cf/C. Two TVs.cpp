#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> shows;
    for (int i=0; i<n; i++) {
        ll l,r; cin >> l >> r;
        shows.push_back({l,r});
    }

    sort(shows.begin(), shows.end());

    ll firstTV = -1;
    ll secondTV = -1;
    for (int i=0; i<n; i++) {
        ll l = shows[i][0], r = shows[i][1];

        if (firstTV < l) {
            firstTV = r;
        } else if (secondTV < l) {
            secondTV = r;
        } else {
            NO; return;
        }
    }
    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

