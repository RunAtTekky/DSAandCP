#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char ROLL = '@';
const char FLOOR = '.';

void take_input(vector<string>& walls) {
    string wall;
    while (cin >> wall) {
        walls.push_back(wall);
    }
}

bool can_pickup_roll(vector<string>& walls, ll i, ll j) {
    ll rows = walls.size(), cols = walls[0].size();

    ll rolls_picked_up = 0;
    ll UP = i-1, DOWN = i+1, LEFT = j-1, RIGHT = j+1;

    if (LEFT >= 0 && walls[i][LEFT] == ROLL) rolls_picked_up++;
    if (RIGHT < cols && walls[i][RIGHT] == ROLL) rolls_picked_up++;
    if (UP >= 0 && walls[UP][j] == ROLL) rolls_picked_up++;
    if (DOWN < rows && walls[DOWN][j] == ROLL) rolls_picked_up++;

    if (UP >= 0 && LEFT >= 0 && walls[UP][LEFT] == ROLL) rolls_picked_up++;
    if (UP >= 0 && RIGHT < cols && walls[UP][RIGHT] == ROLL) rolls_picked_up++;
    if (DOWN < rows && LEFT >= 0 && walls[DOWN][LEFT] == ROLL) rolls_picked_up++;
    if (DOWN < rows && RIGHT < cols && walls[DOWN][RIGHT] == ROLL) rolls_picked_up++;

    return rolls_picked_up < 4;
}


void remove_pickable_rolls(vector<pair<ll,ll>>& pickable_rolls, vector<string>& walls) {
    for (auto &[row,col] : pickable_rolls) {
        walls[row][col] = FLOOR;
    }
}

ll remove_pickable_rolls(vector<string>& walls, ll& total_rolls_removed) {
    ll rows = walls.size();
    ll cols = walls[0].size();

    vector<pair<ll,ll>> pickable_rolls;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (walls[i][j] != ROLL) continue;
            bool isValid = can_pickup_roll(walls, i, j);
            if (isValid) pickable_rolls.push_back({i,j});
        }
    }

    total_rolls_removed += pickable_rolls.size();
    remove_pickable_rolls(pickable_rolls, walls);

    return !pickable_rolls.empty();
}

void solve() {
    vector<string> walls;
    take_input(walls);

    ll total_rolls_removed = 0;
    while (true) {
        bool found = remove_pickable_rolls(walls, total_rolls_removed);
        if (!found) break;
    }
    cout << total_rolls_removed << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

