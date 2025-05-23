#include <bits/stdc++.h>
using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"  

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    // If all same then obv NO
    if (*min_element(vec.begin(), vec.end()) == *max_element(vec.begin(), vec.end())) {
        NO; return;
    }

    int maxi = *max_element(vec.begin(), vec.end());
    bool done = false;

    YES;
    for (int i=0; i<n; i++) {
        if (!done && vec[i] == maxi) {
            cout << "1 ";
            done = true;
        } else {
            cout << "2 ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
