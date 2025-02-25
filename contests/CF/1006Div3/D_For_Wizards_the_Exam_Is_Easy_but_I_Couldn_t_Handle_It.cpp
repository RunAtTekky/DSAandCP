#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ' ' << x << '\n';

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<vector<int>> inverse(n);

    long long total_inverse = 0;

    for (int i=0; i<n; i++) {
        int inverse_count = 0;
        for (int j=i; j<n; j++) {
            if (vec[i] > vec[j]) {
                inverse[i].push_back(j);
                total_inverse++;
            }
        }
    }

    vector<vector<int>> greater_than(n+1, vector<int>(2001));

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=2000; j++) {
            if (vec[i-1] > j) {
                greater_than[i][j]++;
            }
            greater_than[i][j] += greater_than[i-1][j];
        }
    }

    int mini = total_inverse;

    int answer_l = 0;
    int answer_r = 0;

    for (int l=0; l<n; l++) {
        for (int r=l+1; r<n; r++) {

            int inverse_removed = upper_bound(inverse[l].begin(), inverse[l].end(), r) - inverse[l].begin();
            int greater_than_in_range = greater_than[r+1][vec[l]] - greater_than[l][vec[l]];

            // debug(l);
            // debug(r);
            // debug(inverse_removed);
            // debug(greater_than_in_range);

            int new_inverses = total_inverse - inverse_removed + greater_than_in_range;

            if (new_inverses < mini) {
                answer_l = l;
                answer_r = r;

                mini = new_inverses;
            }
            
        }
    }

    // cout << mini << "\n";
    cout << answer_l+1 << " " << answer_r+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
