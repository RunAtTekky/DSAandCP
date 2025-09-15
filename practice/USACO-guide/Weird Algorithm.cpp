#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    cout << n << " ";
    while (n != 1) {
        if (n&1) n = n * 3 + 1;
        else n /= 2;
        cout << n << " ";
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

