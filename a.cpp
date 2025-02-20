#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    

    // # Find if
    // auto it = find_if(vec.begin(), vec.end(), [&](int x) {
    //     return x&1;
    // });

    // cout << it - vec.begin() << "\n";

    // # Count if
    // auto count = count_if(vec.begin(), vec.end(), [&](int x) {
    //     return x&1;
    // });

    // cout << count << "\n";

    // # Unique
    // sort(vec.begin(), vec.end());

    // auto it = unique(vec.begin(), vec.end());

    // vec.resize(it-vec.begin());

    // for (auto &ele : vec) cout << ele << " ";
    // cout << "\n";
    
    

    

}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
