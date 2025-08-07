#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    if (count(vec.begin(), vec.end(), 0) > 0) {NO; return;}
    
    for (int i=0; i+2<n; i++) {
        // if (vec[i] != -1 && vec[i+1] != -1 && vec[i+2] != -1) {
        int maxi = max({vec[i], vec[i+1], vec[i+2]});

        if (vec[i] == -1) vec[i] = maxi;
        if (vec[i+1] == -1) vec[i+1] = maxi;
        if (vec[i+2] == -1) vec[i+2] = maxi;

        int mini = min({vec[i], vec[i+1], vec[i+2]});

        if (maxi != mini) {
            NO; return;
        }

        vec[i] = maxi;
        vec[i+1] = maxi;
        vec[i+2] = maxi;
        // }
    }

    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
