#include <bits/stdc++.h>
using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"  

const int INF = 1e13;

long long max_subarray_sum(vector<long long>& vec, int start, int end) {
    int n = vec.size();
    if (start >= n || start < 0 || end < 0 || end >= n) return 0;

    long long curr = 0, best = 0;

    for (int i=start; i<=end; i++) {
        curr = max(curr + vec[i], vec[i]);
        best = max(best, curr);
    }

    return best;
}

bool check_impossible(vector<long long> vec, string s, int n, int k) {
    for (int i=0; i<n; i++) {
        if (s[i] == '0') vec[i] = -1 * INF;
    }

    long long max_sub_sum = max_subarray_sum(vec, 0, n-1);
    return max_sub_sum > k;
}

void solve() {
    long long n,k; cin >> n >> k;

    string s; cin >> s;

    vector<long long> vec(n);
    for (auto &ele : vec) cin >> ele;

    int pos = -1;
    for (int i=0; i<n; i++) {
        if (s[i] == '0') {
            pos = i;
            vec[i] = -1 * INF;
        }
    }

    // If it is impossible -> max_sub_sum > k || max sub sum != k and no position left
    long long max_sum = max_subarray_sum(vec, 0, n-1);
    if (max_sum > k || (max_sum != k && pos == -1)) {NO; return;}

    if (pos != -1) {
        long long lft = 0, curr = 0;
        for (int i=pos+1; i<n; i++) {
            curr += vec[i];
            lft = max(lft, curr);
        }

        long long rgt = 0;
        curr = 0;
        for (int i=pos-1; i>=0; i--) {
            curr += vec[i];
            rgt = max(rgt, curr);
        }

        vec[pos] = k - lft - rgt;
    }  

    YES;
    for (auto &ele : vec) cout << ele << " ";
    cout << "\n";
    
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
