#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<int> order(n);
    for (auto &ele : order) cin >> ele;
    
    vector<int> desired(n);
    for (auto &ele : desired) cin >> ele;
    
    map<int,int> position_in_A;
    map<int,bool> moved;

    for (int i=0; i<n; i++) {
        position_in_A[order[i]] = i;
    }

    ll ans = 0;
    int idxA = 0;

    for (int i=0; i<n; i++) {
        while (moved[idxA]) idxA++;

        if (order[idxA] == desired[i]) {
            idxA++;
        } else {
            int position = position_in_A[desired[i]];
            moved[position] = true;

            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    solve();
}

