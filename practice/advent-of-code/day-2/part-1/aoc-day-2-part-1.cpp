#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

/*
     269351-363914,180-254,79-106,771-1061,4780775-4976839,7568-10237,33329-46781,127083410-127183480,19624-26384,9393862801-9393974421,2144-3002,922397-1093053,39-55,2173488366-2173540399,879765-909760,85099621-85259580,2-16,796214-878478,163241-234234,93853262-94049189,416472-519164,77197-98043,17-27,88534636-88694588,57-76,193139610-193243344,53458904-53583295,4674629752-4674660925,4423378-4482184,570401-735018,280-392,4545446473-4545461510,462-664,5092-7032,26156828-26366132,10296-12941,61640-74898,7171671518-7171766360,3433355031-3433496616
*/

// terminate called after throwing an instance of 'std::out_of_range'

vector<ll> get_range(string split) {
    vector<ll> range(2);
    ll n = split.size();
    for (int i=0; i<n; i++) {
        if (split[i] == '-') {
            string lft = split.substr(0, i);
            string rgt = split.substr(i+1);

            range[0] = stoll(lft);
            range[1] = stoll(rgt);
            break;
        }
    }

    return range;
}

vector<vector<ll>> get_ranges(string input) {
    vector<vector<ll>> ranges;

    ll n = input.size(), lst = 0;
    for (int i=0; i<n; i++) {
        if (input[i] == ',') {
            ll sz = i-lst+1;
            string split = input.substr(lst,sz);
            vector<ll> range = get_range(split);
            ranges.push_back(range);
            lst = i+1;
        }
    }

    string last_split = input.substr(lst);
    ranges.push_back(get_range(last_split));

    return ranges;
}

bool is_invalid(ll num) {
    /*
      We need to find if the num is repeated
      "Since the young Elf was just doing silly patterns, you can find the invalid
      IDs by looking for any ID which is made only of some sequence of digits
      repeated twice. So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice)
      would all be invalid IDs."
    */

    string num_s = to_string(num);
    ll n = num_s.size();
    if (n & 1) return false;

    ll mid = n / 2;
    auto lft = num_s.substr(0, mid);
    auto rgt = num_s.substr(mid);

    return lft == rgt;
}

ll get_sum_of_invalid(ll lft, ll rgt) {
    ll sum = 0;
    for (ll i=lft; i<=rgt; i++) {
        if (is_invalid(i)) sum += i;
    }
    return sum;
}

void solve() {
    string input; cin >> input;

    // { (l,r), (l,r), (l,r)} => ranges
    vector<vector<ll>> ranges = get_ranges(input);

    for (auto &range : ranges) cout << range[0] << " " << range[1] << "\n";
    cout << "\n";

    ll total_invalid_sum = 0;
    for (const auto &range : ranges) {
        ll lft = range[0], rgt = range[1];

        ll sum_of_invalid = get_sum_of_invalid(lft,rgt);
        total_invalid_sum += sum_of_invalid;
    }

    cout << total_invalid_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

