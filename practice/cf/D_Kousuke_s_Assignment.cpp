#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    int total = 0;

    for (int i=0,j=0; i<n; i=j+1) {
        map<int,bool> isPresent;
        isPresent[0] = true;

        int currentSum = 0;
        for (j=i; j<n; j++) {
            currentSum += arr[j];
            
            if (isPresent[currentSum]) {
                total++;
                break;
            }
            
            isPresent[currentSum] = true;
        }
    }

    cout << total << "\n";
}

int32_t main() {
    int t=1; cin >> t;
    while (t--) solve();
}
