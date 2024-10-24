#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &ele : arr) cin >> ele;

    int beauty = 0;

    for (int i=0, j=0; i<n; i=j+1) {
        map<int,bool> isPresent;
        isPresent[0] = true;

        int currentSum = 0;
        for (j=i; j<n; j++) {
            currentSum += arr[j];
            if (isPresent[currentSum]) {
                beauty++;
                break;
            }
            else {
                isPresent[currentSum] = true;
            }
        }
    }

    cout << beauty << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
