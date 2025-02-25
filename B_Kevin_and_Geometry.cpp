#include <bits/stdc++.h>
using namespace std;

#define NO cout << "-1\n"  

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    sort(vec.begin(), vec.end());

    bool occurs_twice = false;
    int occurs_at;

    for (int i=0; i+1<n; i++) {
        if (vec[i] == vec[i+1]) {
            occurs_at = i;
            occurs_twice = true; break;
        }
    }

    if (!occurs_twice) {NO; return;}

    int same_sides = vec[occurs_at];

    vec.erase(vec.begin() + occurs_at);
    vec.erase(vec.begin() + occurs_at);


    for (int i=0; i+1<vec.size(); i++) {
        double side_diff = (vec[i+1] - vec[i]) / 2.0;

        if (side_diff < same_sides) {
            cout << same_sides << " " << same_sides << " " << vec[i] << " " << vec[i+1] << "\n";
            return;
        }
    }

    NO;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
