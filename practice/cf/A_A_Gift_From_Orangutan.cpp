#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &ele : arr) cin >> ele;

    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());

    int score = (n-1) * (maxElement - minElement);

    cout << score << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
