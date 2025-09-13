#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n,m; cin >> n >> m;

    vector<ll> tickets(n);
    for (auto &ticket : tickets) cin >> ticket;
    
    vector<ll> customers(m);
    for (auto &customer : customers) cin >> customer;

    sort(tickets.begin(), tickets.end());

    map<ll,ll> ticketSold;
    map<ll,ll> lastSoldAtIdx;

    for (int i=0; i<n; i++) lastSoldAtIdx[i] = i+1;

    for (auto cust : customers) {
        ll idx = upper_bound(tickets.begin(), tickets.end(), cust) - tickets.begin();
        if (idx == 0) {
            cout << -1 << "\n"; continue;
        }
        idx--;

        ll ticketPrice = -1;
        int i=lastSoldAtIdx[idx]-1;

        for (; i>=0; i--) {
            if (lastSoldAtIdx[i] == i+1) {
                ticketPrice = tickets[i];
                lastSoldAtIdx[i] = i; break;
            }
        }

        for (int j=i+1; j<=lastSoldAtIdx[idx]; j++) {
            lastSoldAtIdx[j] = i;
        }
        
        cout << ( (ticketPrice == -1) ? -1 : ticketPrice ) << "\n";
    }

    cout << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

