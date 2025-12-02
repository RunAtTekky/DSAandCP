#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_movement(string rotation) {
    bool lft_move = false;
    if (rotation.front() == 'L') lft_move = true;
    ll value = (lft_move * -1 + !lft_move * 1) * stoi(rotation.substr(1));
    return value;
}

void do_movement(ll &start_point, ll &movement, ll &ans) {
    // Brute Force the movement (movement < 100)
    ll freq = abs(movement);
    ll dir = -1;
    if (movement > 0) dir = 1;
    ll curr = start_point;
    while (freq--) {
        curr += dir;
        ans += (curr == 0 || curr == 99);
        if (curr == -1) curr = 99;
        if (curr == 100) curr = 0;
    }

    start_point = curr;
}

void solve() {
    vector<string> rotations;
    string rotation;
    while (cin >> rotation) {
        rotations.push_back(rotation);
    }

    ll start_point = 50, ans = 0;
    for (const auto &rotation : rotations) {
        ll movement = get_movement(rotation);

        // Cycle basically, so it will pass through 0 `rotation / 100` times
        ans += abs(movement) / 100;
        movement %= 100;

        do_movement(start_point, movement, ans);

        // cout << start_point << " " << ans << "\n";
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

