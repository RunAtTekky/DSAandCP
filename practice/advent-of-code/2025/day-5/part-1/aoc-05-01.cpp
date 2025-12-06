#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get_range(string input) {
    ll dash_idx = find(input.begin(), input.end(), '-') - input.begin();

    string lft_side = input.substr(0, dash_idx);
    string rgt_side = input.substr(dash_idx+1);

    ll before_dash = stoll(lft_side);
    ll after_dash = stoll(rgt_side);

    return {before_dash,after_dash};
}

void take_input(vector<vector<ll>>& ranges, vector<ll>& ingredients) {
    string input;
    bool range_over = false;
    while (cin >> input) {
        // WARNING: Very important to use stop as the separator between both inputs
        // coz cin just skips and checks the next input wherever possible
        // it doesn't consider emptyline as an input
        // It took me nearly 10 minutes to figure this shit out lol
        if (input == "STOP") {
            range_over = true; continue;
        }
        if (!range_over) {
            vector<ll> range = get_range(input);
            ranges.push_back(range);
        } else {
            ll ing_input = stoll(input);
            ingredients.push_back(ing_input);
        }

    }
}

bool find_ingredient(ll ingredient, vector<vector<ll>>& ranges) {
    for (const auto& range : ranges) {
        ll lft = range[0], rgt = range[1];
        if (ingredient >= lft && ingredient <= rgt) return true;
    }
    return false;
}

bool check_freshness(ll ingredient, vector<vector<ll>>& ranges) {
    // TODO: Linear Search
    return find_ingredient(ingredient, ranges);
}

ll find_fresh(vector<vector<ll>>& ranges, vector<ll>& ingredients) {
    // TODO: Find number of fresh ingredients

    // for (auto &range : ranges) cout << range[0] << " " << range[1] << "\n";
    // cout << "\n";

    ll fresh = 0;
    for (const auto &ingredient : ingredients) {
        bool isFresh = check_freshness(ingredient, ranges);
        fresh += isFresh;
    }
    return fresh;
}

vector<vector<ll>> condense_ranges(vector<vector<ll>>& ranges) {
    // TODO: Condense ranges
    vector<vector<ll>> new_ranges;

    ll n = ranges.size();
    for (int i=0, j=0; i<n; i=j) {
        j = i+1;
        ll lft = ranges[i][0], rgt = ranges[i][1];
        while (j<n) {
            ll curr_lft = ranges[j][0], curr_rgt = ranges[j][1];
            if (rgt < curr_lft) break;

            rgt = max(rgt, curr_rgt);
            j++;
        }
        new_ranges.push_back({lft,rgt});
    }

    return new_ranges;
}

void solve() {
    vector<vector<ll>> ranges;
    vector<ll> ingredients;

    take_input(ranges, ingredients);
    sort(ranges.begin(), ranges.end());

    ranges = condense_ranges(ranges);

    ll fresh = find_fresh(ranges, ingredients);
    cout << fresh << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

