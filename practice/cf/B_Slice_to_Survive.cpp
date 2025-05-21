#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,m,a,b; cin >> n >> m >> a >> b;

    long long rounds = n+m;

    vector<pair<int,int>> possible_cuts({
        {a,m},
        {n-a+1,m},
        {n,b},
        {n,m-b+1}
    });

    for (auto &[rows,cols] : possible_cuts) {
        long long cuts = 0;

        while (rows > 1) {
            rows = (rows+1)/2;
            cuts++;
        }

        while (cols > 1) {
            cols = (cols+1)/2;
            cuts++;
        }

        rounds = min(rounds, cuts);
    }

    cout << rounds + 1 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
