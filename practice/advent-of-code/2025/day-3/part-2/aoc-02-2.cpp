#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll BATTERIES_REQ = 12;

void take_input(vector<vector<ll>>& banks) {
    // take input
    string bank_s;
    while (cin >> bank_s) {
        vector<ll> bank;
        for (auto &cell : bank_s) {
            ll cell_l = cell - '0';
            bank.push_back(cell_l);
        }
        banks.push_back(bank);
    }
}

ll calculate_ans(vector<ll> ans) {
    ll result = 0;
    ll mult = 1;
    for (int i=ans.size() - 1; i>=0; i--) {
        result += mult * ans[i];
        mult *= 10;
    }
    return result;
}

void get_best(ll& curr_idx, vector<ll>& bank, map<ll, vector<ll>>& idxs, vector<ll>& ans) {
    ll n = bank.size();
    for (int want=9; want>=0; want--) {
        for (const auto &idx : idxs[want]) {
            // Can we take that
            if (idx <= curr_idx) continue;
            ll elements_ahead = n - idx;
            bool can_take_element = ans.size() + elements_ahead >= BATTERIES_REQ;
            if (can_take_element) {
                ans.push_back(want);
                curr_idx = idx;
                return;
            }
        }
    }
}

ll get_largest_joltage(vector<ll>& bank) {
    /*
        TODO: Get largest joltage with exactly 12 cells from the bank

        Well probably we can try (take/no-take)
        818181911112111 - 15 length (we can use take/no-take)
        2633322623185223292633232342336241353472323432337144252444247533312232433423423228632337331231223633
        this is 99 length which means we can't use (take/no-take)

        We need something greedy
        26333226231852232 9263323234233624135347232343233714425244424753331223243342342322 863233 7331231223 63 3
        Should I take 2 or not
        ANS: NO. Why? Coz 6 is ahead and there are still 11 more left.
        We can take the 6 and 11 more ahead of it.
        So, if we have a number greater than our current number ahead and beyond that we have the rest of required numbers.
        It is always better to take that next number.

        So we miss out on 2 and take the 6.
        But then we have a 6 ahead and then an 8 ahead and then a 9 ahead
        Now this 9 is where we start from
        Then we get that 8 for front
        9 8 7 633 -> These are 6, we need 6 more.
        7331231223 -> 3 312 3122 3
        3122 -> 122

        We get this answer:
        9 8 7 3 3122 3 633 -> 12
        ANS: 987331223633

        NOTE: Let us go over how to do it

        We had the following number
        2633322623185223292633232342336241353472323432337144252444247533312232433423423228632337331231223633

        Break the number wherever we get a max change
26333226231852232 9263323234233624135347232343233714425244424753331223243342342322 863233 7331231223 633
9 8 7331231223 633

        So we have
        9263323234233624135347232343233714425244424753331223243342342322 863233 7331231223 633

        Now because ahead of 8 (including 8) we have more than 11 elements, we can use 9 as the starter.
        Same for 7

        9 8 7331231223 633

        9 8 7333223 633
        9 8 7331223 633
        Now go from the last and recursively do this, when you get total 12 numbers: STOP.

        So in this case we will start with 3 and coz 3 can't break further we just return 3

        NOTE: Let us look at this case

        818181911112111
        818181 91111 2111
        Now because from 9 onwards we do not have 11 more elements, we need to take some from behind.

        If 9 ahead we do not have 11 elements, is it always better to take all the elements after 9.
        And remaining best elements from behind

        So now get_best(3, "818181")
        81 81 81
        888

        Final ANS: 888 91111 2111
    */

    ll n = bank.size();
    map<ll,vector<ll>> idxs;
    for (int i=0; i<n; i++) {
        ll val = bank[i];
        idxs[val].push_back(i);
    }

    vector<ll> ans;
    ll curr_idx = -1;
    while (ans.size() < BATTERIES_REQ) {
        get_best(curr_idx, bank, idxs, ans);
    }

    ll result = calculate_ans(ans);
    return result;
}

void solve() {
    vector<vector<ll>> banks;
    take_input(banks);

    // Check input
    // for (auto &bank : banks) {
    //     for (auto &ele : bank) cout << ele << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    ll total_joltage = 0;
    for (auto &bank : banks) {
        ll largest_joltage = get_largest_joltage(bank);
        total_joltage += largest_joltage;
    }

    cout << total_joltage << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

