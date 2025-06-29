#include <bits/stdc++.h>



// Important header files  
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds; 
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set; 

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> input;
    
    ll ans = 0;
    ordered_set ends;

    for (int i=0; i<n; i++) {
        ll start, end;
        cin >> start >> end;

        input.push_back({start,end});
    }

    sort(input.begin(), input.end());

    for (int i=0; i<n; i++) {
        ll start = input[i].first;
        ll end = input[i].second;

        ans += ends.size() - ends.order_of_key(end);

        ends.insert(end);

    }


    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
