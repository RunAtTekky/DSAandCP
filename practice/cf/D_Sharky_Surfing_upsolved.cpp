#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,L;
    cin >> n >> m >> L;

    vector<pair<int,int>> hurdle_positions(n);
    // {l,r}

    for (int i=0; i<n; i++) {
        int l,r; cin >> l >> r;

        hurdle_positions[i] = {l,r};
    }

    vector<pair<int,int>> powerUps(m);

    for (int i=0; i<m; i++) {
        int x, v; cin >> x >> v;
        powerUps[i] = {x,v};
    }

    priority_queue<int> pq;

    int power_ups_required_in_total = 0;

    long long current_jump = 1;

    for (int hurdle_number=0, powerup_number=0; hurdle_number<n; hurdle_number++) {
        // Push all the powerups before the hurdle position
        while (powerup_number<m && powerUps[powerup_number].first < hurdle_positions[hurdle_number].first) {
            int power_value = powerUps[powerup_number].second;
            pq.push(power_value);
            powerup_number++;
        }

        // Use the powerups required to clear the hurdle
        int jump_required = hurdle_positions[hurdle_number].second - hurdle_positions[hurdle_number].first + 2;

        while (!pq.empty() && current_jump < jump_required) {
            int max_current_powerup = pq.top();
            current_jump += max_current_powerup;
            power_ups_required_in_total++;
            pq.pop();
        }

        if (current_jump < jump_required) {
            cout << "-1\n"; return;
        }

    }

    cout << power_ups_required_in_total << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
