#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> dandelions(n);
    for (auto &ele : dandelions) cin >> ele;

    vector<ll> odd_dandelions;
    vector<ll> even_dandelions;

    for (auto &ele : dandelions) {
        if (ele&1) odd_dandelions.push_back(ele);
        else even_dandelions.push_back(ele);
    }

    sort(odd_dandelions.begin(), odd_dandelions.end());
    sort(even_dandelions.begin(), even_dandelions.end());

    ll total = accumulate(even_dandelions.begin(), even_dandelions.end(), 0LL);

    for (int i=0, j=odd_dandelions.size() - 1; i<=j; i++, j--) {
        total += odd_dandelions[j];
    }

    if (odd_dandelions.size() == 0) {
        cout << 0 << "\n"; return;
    }

    cout << total << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

