#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<int> pref(n);
    for (auto &ele : pref) cin >> ele;
    
    vector<int> suf(n);
    for (auto &ele : suf) cin >> ele;
    
    bool found_same = false;
    ll smallest_idx = -1;
    for (int i=0; i<n; i++) {
        if (pref[i] == suf[i]) {
            smallest_idx = i;
            found_same = true; break;
        }
    }
    if (!found_same) {NO; return;}

    ll curr = pref.front();
    for (int i=1; i<n; i++) {
        if (gcd(curr, pref[i]) != pref[i]) {NO; return;}
        curr = pref[i];
    }

    curr = suf.back();
    for (int i=n-2; i>=0; i--) {
        if (gcd(curr, suf[i]) != suf[i]) {NO; return;}
        curr = suf[i];
    }

    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
