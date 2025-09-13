#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    vector<pair<ll,ll>> audio(n);
    for (int i=0; i<n; i++) {
        cin >> audio[i].first;
        cin >> audio[i].second;
    }

    sort(audio.begin(), audio.end());

    ll currTime = 0;
    ll lastSide = 0;
    ll points = 0;
    for (int i=0; i<n; i++) {
        ll time_diff = audio[i].first - currTime;
        if (time_diff % 2 == 0) {
            if (audio[i].second == lastSide) {
                points += time_diff;
            } else {
                points += time_diff - 1;
            }
        } else {
            if (audio[i].second != lastSide) {
                points += time_diff;
            } else {
                points += time_diff - 1;
            }
        }

        lastSide = audio[i].second;
        currTime = audio[i].first;
        //
        // cout << points << "\n";
    }

    points += m - currTime;

    cout << points << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

