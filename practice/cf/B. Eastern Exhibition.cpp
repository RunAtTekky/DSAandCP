#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> houseX;
    vector<ll> houseY;
    for (int i=0; i<n; i++) {
        ll x, y; cin >> x >> y;
        houseX.push_back(x);
        houseY.push_back(y);
    }

    sort(houseX.begin(), houseX.end());
    sort(houseY.begin(), houseY.end());

    ll sum_x = 0, sum_y = 0;
    for (auto &x : houseX) sum_x += x;
    for (auto &y : houseY) sum_y += y;

    double mid_x = sum_x / (n * 1.0);
    double mid_y = sum_y / (n * 1.0);

    // cout << mid_x << " " << mid_y << "\n";

    ll possible_x = 1, possible_y = 1;
    for (int i=0; i+1<n; i++) {
        ll to_the_left = i+1;
        ll to_the_right = n - (i+1);
        if (to_the_left != to_the_right) continue;

        ll lft = houseX[i], rgt = houseX[i+1];
        possible_x = max(possible_x, rgt - lft + 1);
        // if (lft <= mid_x && mid_x <= rgt) {
        //     possible_x = rgt - lft + 1;
        //     break;
        // }
    }

    for (int i=0; i+1<n; i++) {
        ll to_the_left = i+1;
        ll to_the_right = n - (i+1);
        if (to_the_left != to_the_right) continue;

        // cout << "HI" << " " << i << "\n";

        ll lft = houseY[i], rgt = houseY[i+1];
        possible_y = max(possible_y, rgt - lft + 1);
        // cout << lft << " " << rgt << "\n";
        // cout << rgt - lft + 1 << "\n";
        // if (lft <= mid_y && mid_y <= rgt) {
        //     possible_y = rgt - lft + 1;
        //     break;
        // }
    }

    // cout << possible_x << " " << possible_y << "\n";

    cout << possible_x * possible_y << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

