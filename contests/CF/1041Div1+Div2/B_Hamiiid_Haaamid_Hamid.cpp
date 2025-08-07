#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, x; cin >> n >> x;
    x--;

    string grid; cin >> grid;

    stack<int> lft;
    lft.push(0);
    stack<int> rgt;
    rgt.push(0);

    for (int i=0; i<x; i++) {
        if (grid[i] == '#') lft.push(i+1);
    }
    for (int i=n-1; i>x; i--) {
        if (grid[i] == '#') rgt.push(n-i);
    }

    x++;
    int days = 0;
    while (!lft.empty() && !rgt.empty()) {
        int l = lft.top(), r = rgt.top();
        int wall_l = x-1, wall_r = n-x;

        if (l <= r) {
            if (wall_l != l) {
                lft.push(wall_l);
            }
        } else {
            if (wall_r != r) {
                rgt.push(wall_r);
            }
        }

        l = lft.top(), r = rgt.top();

        if (l < r) {
            x = l;
            lft.pop();
        } else {
            x = n-r+1;
            rgt.pop();
        }

        // cout << x << "\n";

        days++;
    }

    cout << days << "\n";








}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
