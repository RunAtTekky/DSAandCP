#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void findMinimum(vector<ll> cows) {
    if (cows.back() - cows.front() == 2) {
        cout << 0 << "\n"; return;
    }

    if ( (cows[1] - cows[0] == 2) || (cows[2] - cows[1] == 2) ) {
        cout << 1 << "\n"; return;
    }

    cout << 2 << "\n";
}

void solve() {
    vector<ll> cows(3);
    cin >> cows[0] >> cows[1] >> cows[2];

    sort(cows.begin(), cows.end());

    // Minimum is at max 2
    // 0 if we already have consecutive
    // 1 if there can be 1 cow between any two cows
    // 2 in other case
    findMinimum(cows);

    // Maximum can be the max position of cows between two cows
    cout << max(cows[2] - cows[1], cows[1] - cows[0]) - 1 << "\n";
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

