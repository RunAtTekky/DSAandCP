#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    string sequence; cin >> sequence;


    for (int k=1; k<=n; k++) {
        map<string,ll> freq;
        bool found = true;
        for (int i=0; i+k<=n; i++) {
            string s = sequence.substr(i, k);
            freq[s]++;

            if (freq[s] > 1) {found = false; break;}
        }

        if (found) {
            cout << k << "\n"; return;
        }

    }
}

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

