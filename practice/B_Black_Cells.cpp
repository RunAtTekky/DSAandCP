#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll k;

void maxDiff(vector<ll> arr) {
    sort(arr.begin(), arr.end());

    // for (auto e : arr) cout << e << " ";
    // cout << "\n";

    int n = arr.size();
    for (int i=0; i+1<n; i++) {
        if (arr[i+1] == arr[i]) return;
    }

    ll curr = 0;
    for (int i=0; i+1<n; i+=2) {
        ll diff = arr[i+1] - arr[i];
        curr = max(curr, diff);
        // cout << curr << " <- curr \n";
    }

    k = min(k, curr);
}

void solve() {
    ll n; cin >> n;

    vector<ll> arr(n);
    for (auto &e: arr) cin >> e;

    sort(arr.begin(), arr.end());

    k = 1e18;

    if (n%2 == 0) {
        maxDiff(arr); 
        cout << k << "\n";
        return;
    }

    for (int i=0; i<n; i++) {
        for (auto x : {-1, 1}) {
            arr.push_back(arr[i] + x);
            maxDiff(arr);
            arr.pop_back();
        }
    }

    cout << k << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
