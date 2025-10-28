#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get_subseg_length(vector<ll>& vec) {
    ll n = vec.size();
    vector<ll> res(n+1);

    for (ll i=0, j=0; i<n; i=j) {
        if (vec[i] == 0) {j=i+1; continue;}
        j=i;

        while (j<n && vec[j] == 1) j++;

        ll consecutive_ones = j-i;
        for (ll len=1; len <= consecutive_ones; len++) {
            res[len] += consecutive_ones - len + 1;
        }
    }

    return res;
}

void solve() {
    ll n,m,k; cin >> n >> m >> k;

    vector<ll> arr_a(n);
    for (auto &ele : arr_a) cin >> ele;
    
    vector<ll> arr_b(m);
    for (auto &ele : arr_b) cin >> ele;

    auto subsegment_of_length_l_in_a = get_subseg_length(arr_a);
    auto subsegment_of_length_l_in_b = get_subseg_length(arr_b);

    // for (auto &ele : subsegment_of_length_l_in_a) cout << ele << " ";
    // cout << "\n";
    //
    // for (auto &ele : subsegment_of_length_l_in_b) cout << ele << " ";
    // cout << "\n";
    //
    // k = p * q
    ll ans = 0;
    for (ll p=1; p<=n; p++) {
        if (k % p == 0 && k/p <= m) {
            ans += subsegment_of_length_l_in_a[p] * subsegment_of_length_l_in_b[k/p];
        }
    }

    cout << ans << "\n";
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

