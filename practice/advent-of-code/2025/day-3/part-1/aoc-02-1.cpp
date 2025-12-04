#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void take_input(vector<vector<ll>>& banks) {
    // take input
    string bank_s;
    while (cin >> bank_s) {
        vector<ll> bank;
        for (auto &cell : bank_s) {
            ll cell_l = cell - '0';
            bank.push_back(cell_l);
        }
        banks.push_back(bank);
    }
}

ll get_largest_joltage(const vector<ll>& bank) {
    ll n = bank.size();
    vector<ll> pref(n);
    vector<ll> suff(n);
    // 818181911112111
    // 888888999999999
    // 999999922222111
    pref[0] = bank[0];
    suff[n-1] = bank[n-1];
    for (int i=1; i<n; i++) {
        pref[i] = max(pref[i-1], bank[i]);
    }

    for (int i=n-2; i>=0; i--) {
        suff[i] = max(suff[i+1], bank[i]);
    }

    // for (auto &ele : pref) cout << ele << " ";
    // cout << "\n";
    //
    // for (auto &ele : suff) cout << ele << " ";
    // cout << "\n";
    
    ll largest_joltage = 0;
    for (int i=0; i+1<n; i++) {
        ll joltage = pref[i] * 10 + suff[i+1];
        largest_joltage = max(largest_joltage, joltage);
    }
    return largest_joltage;
}

void solve() {
    vector<vector<ll>> banks;
    take_input(banks);

    // Check input
    // for (auto &bank : banks) {
    //     for (auto &ele : bank) cout << ele << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // Take any two cells from the bank and they should be the largest
    ll total_joltage = 0;
    for (auto &bank : banks) {
        ll largest_joltage = get_largest_joltage(bank);
        total_joltage += largest_joltage;
    }

    cout << total_joltage << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

