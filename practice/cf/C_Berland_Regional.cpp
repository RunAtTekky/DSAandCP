#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    map<ll, vector<ll>> uni_skill;
    vector<vector<ll>> uni_pref;

    vector<int> uni(n);
    for (auto &ele : uni) cin >> ele;
    
    vector<int> skill(n);
    for (auto &ele : skill) cin >> ele;
    
    for (int i=0; i<n; i++) uni_skill[uni[i]].push_back(skill[i]);

    for (auto &[uni, skill] : uni_skill) {
        sort(skill.rbegin(), skill.rend());

        vector<ll> pref = {0};
        for (auto &s : skill) {
            pref.push_back(pref.back() + s);
        }
        uni_pref.push_back(pref);
    }

    vector<ll> ans(n);

    for (int i=0; i<uni_pref.size(); i++) {
        ll m = uni_pref[i].size();

        for (int k=1; k<=m; k++) {
            ans[k-1] += uni_pref[i][(m-1)/k * k];
        }
    }

    for (auto &ele : ans) cout << ele << " ";
    cout << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
