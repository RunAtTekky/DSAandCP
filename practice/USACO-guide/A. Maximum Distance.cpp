#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> xCoord(n);
    for (auto &ele : xCoord) cin >> ele;
    
    vector<ll> yCoord(n);
    for (auto &ele : yCoord) cin >> ele;

    ll maxEuclidDistance = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll euclidDistance = 
                (xCoord[i] - xCoord[j]) * (xCoord[i] - xCoord[j]) 
                +
                (yCoord[i] - yCoord[j]) * (yCoord[i] - yCoord[j]);
            maxEuclidDistance = max(maxEuclidDistance, euclidDistance);
        }
    }

    cout << maxEuclidDistance << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

