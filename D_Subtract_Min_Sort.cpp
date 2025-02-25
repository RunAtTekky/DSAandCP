#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    for (int i=0; i+1<n; i++) {
        int mini = min(vec[i], vec[i+1]);

        vec[i] -= mini;
        vec[i+1] -= mini;
    }

    // for (auto &ele : vec) cout << ele << " ";
    // cout << "\n";
    
    if (is_sorted(vec.begin(), vec.end())) { YES; } 
    else { NO; }
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
