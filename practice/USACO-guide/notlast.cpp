#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    map<string, ll> milk;
    milk["Bessie"] = 0;
    milk["Elsie"] = 0;
    milk["Daisy"] = 0;
    milk["Gertie"] = 0;
    milk["Annabelle"] = 0;
    milk["Maggie"] = 0;
    milk["Henrietta"] = 0;

    for (int i=0; i<n; i++) {
        string cow; cin >> cow;
        ll milkProd; cin >> milkProd;

        milk[cow] += milkProd;
    }


    map<ll, vector<string>> milkByCow;
    for (auto &[cow, milkProd] : milk) {
        milkByCow[milkProd].push_back(cow);
    }

    bool firstDone = false;
    for (auto &[milkProd, cows] : milkByCow) {
        if (!firstDone) {
            firstDone = true;
            continue;
        }

        if (cows.size() > 1) {
            cout << "Tie" << "\n";
        } else {
            cout << cows[0] << "\n";
        }
        return;
    }

    cout << "Tie" << "\n";
}


int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

