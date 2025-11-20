#include <bits/stdc++.h>
using namespace std;

#define AJISAI cout << "Ajisai\n"
#define MAI cout << "Mai\n"
#define TIE cout << "Tie\n"

typedef long long ll;
typedef pair<ll,ll> pll;


void solve() {
    ll n; cin >> n;

    vector<ll> vec_a(n);
    for (auto &ele : vec_a) cin >> ele;
    
    vector<ll> vec_b(n);
    for (auto &ele : vec_b) cin >> ele;

    set<pll> curr;
    curr.insert({0,0});

    bool ajisai_last = false;
    for (int i=0; i<n; i++) {
        ll a = vec_a[i], b = vec_b[i];
        if (a ^ b) {
            ajisai_last = (i&1) ? false : true;
            set<pll> new_curr;
            for (auto [ajisai,mai] : curr) {
                new_curr.insert({ajisai ^ a, mai ^ b});
                new_curr.insert({ajisai ^ b, mai ^ a});
            }
            curr = new_curr;
        } else {
            set<pll> new_curr;
            for (auto [ajisai,mai] : curr) {
                new_curr.insert({ajisai ^ a, mai ^ b});
            }
            curr = new_curr;
        }
    }

    for (auto [a, b] : curr) {
        if (a ^ b) {
            if (ajisai_last) {
                AJISAI;
            } else {
                MAI;
            }
            return;
        }
    }

    TIE;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

