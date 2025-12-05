#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char ROLL = '@';

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

ll find_pickable_rolls(vector<string>& walls) {
    ll rows = walls.size();
    ll cols = walls[0].size();

    ll total_rolls = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (walls[i][j] != ROLL) continue;
            bool isValid = can_pickup_roll(walls, i, j);
            total_rolls += isValid;
        }
    }

    return total_rolls;
}

void solve() {
    vector<string> walls;
    take_input(walls);

    ll pickable_rolls = find_pickable_rolls(walls);

    cout << pickable_rolls << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

