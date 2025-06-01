#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
vector<int> a;
vector<int> b;

bool ok(int to_remove) {
    for (int i=0; i+to_remove<n; i++) {
        if (a[i] >= b[i+to_remove]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;

    a = {1};
    b = {};
    
    for (int i=0; i<n-1; i++) {
        ll ele; cin >> ele;
        a.push_back(ele);
    }
    
    for (int i=0; i<n; i++) {
        ll ele; cin >> ele;
        b.push_back(ele);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll start = 0, end = n;

    while (start <= end) {
        ll to_remove = (start + end) / 2;

        if (ok(to_remove)) {
            end = to_remove - 1;
        } else start = to_remove + 1;
    }

    cout << start << "\n";



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
