#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> movies;
    vector<ll> startTime;

    for (int i=0; i<n; i++) {
        ll movieStart, movieEnd;
        cin >> movieStart >> movieEnd;

        movies.push_back({movieEnd, movieStart});
    }

    sort(movies.begin(), movies.end());

    pair<ll,ll> currMovie = {-1, -1};
    ll moviesWatched = 0;
    for (const auto &[end, start] : movies) {
        if (start < currMovie.second) continue;
        currMovie = {start, end};
        moviesWatched++;
    }

    cout << moviesWatched << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

