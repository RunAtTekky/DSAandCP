#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    ll a = 0, b = 0;
    ll pos = 0, neg = 0;

    for (auto &ele : vec) {
        if (ele > 0) a++;
        else {
            swap(a,b);
            b++;
        }
        pos += a;
        neg += b;
    }

    cout << neg << " " << pos << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}
