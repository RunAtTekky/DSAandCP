#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    multiset<ll> tickets;
    for (int i=0; i<n; i++) {
        ll ticket_price; cin >> ticket_price;
        tickets.insert(ticket_price);
    }

    for (int i=0; i<m; i++) {
        ll max_price; cin >> max_price;
        
        auto it = tickets.upper_bound(max_price);

        if (it == tickets.begin()) {
            cout << "-1" << "\n";
        } else {
            cout << *(--it) << "\n";
            tickets.erase(it);
        }
    }
    
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

