#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ' ' << x << '\n';

vector<long long> get_reverse(vector<long long>& vec) {
    vector<long long> rev;
    for (long long i=vec.size()-1; i>=0; i--) rev.push_back(vec[i]);

    return rev;
}

vector<long long> get_diff(vector<long long>& vec) {
    vector<long long> diff;

    long long n = vec.size();
    for (long long i=0; i+1<n; i++) {
        long long ele = vec[i+1] - vec[i];
        diff.push_back(ele);
    }

    return diff;
}

map<vector<long long>, long long> dp;

long long h(vector<long long> vec) {
    if (vec.size() == 1) return vec[0];

    auto rev_vec = get_reverse(vec);
    if (dp.find(vec) != dp.end()) return dp[vec];
    if (dp.find(rev_vec) != dp.end()) return dp[rev_vec];

    // cout << "Initial\n";
    // for (auto &ele : vec) cout << ele << " ";
    // cout << "\n";

    // Two choices
    // Just difference
    auto difference_normal = get_diff(vec);

    long long normal = h(difference_normal);

    // Reverse and difference
    auto diff_vec = get_diff(rev_vec);
    long long rev = h(diff_vec);

    // cout << "Final\n";
    // for (auto &ele : vec) cout << ele << " ";
    // cout << "\n";

    long long best_ans = max(dp[vec], max(normal, rev));
    dp[vec] = best_ans;
    dp[rev_vec] = best_ans;

    return best_ans;
    // return max(normal, rev);
}

void solve() {
    long long n; cin >> n;

    vector<long long> vec(n);
    for (auto &ele : vec) cin >> ele;

    long long sum = accumulate(vec.begin(), vec.end(), 0LL);
    long long answer = h(vec);

    cout << max(sum, answer) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t=1; cin >> t;
    while (t--) solve();
}
