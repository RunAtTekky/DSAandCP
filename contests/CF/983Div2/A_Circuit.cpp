#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> switches(2*n);

    for (auto &e : switches) cin >> e;

    int cnt = count(switches.begin(), switches.end(), 1);

    int mini = 0;
    if (cnt&1) mini = 1;

    int maxi = 0;
    if (cnt <= n) maxi = cnt;

    else maxi = n - (cnt - n);


    cout << mini << " " << maxi << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
