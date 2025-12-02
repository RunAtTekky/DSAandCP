#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_movement(string rotation) {
    bool lft_move = false;
    if (rotation.front() == 'L') lft_move = true;
    ll value = (lft_move * -1 + !lft_move * 1) * stoi(rotation.substr(1));
    return value;
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
        start_point += movement;

        // if (start_point < 0) start_point = 100 - abs(start_point);
        // else if (start_point > 99) start_point = start_point - 100;

        start_point %= 100;

        ans += (start_point == 0);
        // cout << start_point << "\n";
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

