#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    for (int i=0; i<n; i++) {
        int distance_to_start = i;
        int distance_to_end = n-1-i;

        int dist = max(distance_to_start, distance_to_end);

        if (dist*2 >= vec[i]) {
            NO; return;
        }
    }

    YES;
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
