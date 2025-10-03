#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void solve() {
//     ll a, b, c, d;
//     cin >> a >> b >> c >> d;
//
//     if (a > b) swap(a,b);
//     if (c > d) swap(c,d);
//
//     vector<bool> painted(101);
//     for (int i=a; i<b; i++) painted[i] = true;
//     for (int i=c; i<d; i++) painted[i] = true;
//
//     cout << accumulate(painted.begin(), painted.end(), 0) << "\n";
// }

void solve2() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll sum = b - a + d - c;
    ll intersection = max(min(b,d) - max(a,c), 0LL);

    cout << sum - intersection << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    // solve();
    solve2();
}

