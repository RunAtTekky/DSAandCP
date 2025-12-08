#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char ADDITION = '+';
const char MULTIPLICATION = '*';

vector<char> get_operations(string line) {
    // TODO: Get operations
    vector<char> operations;
    int i = 0, n = line.size();
    while (i<n) {
        while (i<n && line[i] == ' ') i++;
        if (i>=n) break;
        operations.push_back(line[i]);
        i++;
    }
    return operations;
}
vector<ll> get_line(string line) {
    vector<ll> numbers;
    int i = 0, n = line.size();
    while (i<n) {
        while (i<n && line[i] == ' ') i++;
        if (i>=n) break;
        string number;
        while (i<n && line[i] != ' ') {
            number.push_back(line[i]);
            i++;
        }
        // cout << number << " ";
        // cout <<  "|" << number << "|" << "\n";
        numbers.push_back(stoll(number));
    }

    // cout << "\n";

    return numbers;
}

void read_input(vector<vector<ll>>& grid, vector<char>& operations) {
    vector<string> inputs;
    string input_line;
    while (getline(cin, input_line)) {
        inputs.push_back(input_line);
    }

    ll n = inputs.size();
    for (ll i=0; i+1<n; i++) {
        vector<ll> line = get_line(inputs[i]);
        grid.push_back(line);
    }

    operations = get_operations(inputs.back());

    // cout << grid.size() << "\n";
    // for (auto &line : grid) {
    //     for (auto &ele : line) cout << ele << "|";
    //     cout << "\n";
    // }
    //
    // for (auto &ele : operations) cout << ele << "|";
    // cout << "\n";
    
}

// /usr/include/c++/15.2.1/bits/stl_vector.h:1263: std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = char; _Alloc = std::allocator<char>; reference = char&; size_type = long unsigned int]: Assertion '__n < this->size()' failed.

ll do_math(vector<ll>& list, char operation) {
    ll ans = (operation == ADDITION) ? 0 : 1;
    for (auto &ele : list) {
        if (operation == ADDITION) ans += ele;
        else ans *= ele;
    }
    return ans;
}

ll do_homework(vector<vector<ll>>& grid, vector<char> operations) {
    ll answer = 0;

    ll cols = operations.size(), rows = grid.size();
    // cout << "cols: " << " " << cols << "\n";
    for (int col = 0; col<cols; col++) {
        vector<ll> list;
        for (int row = 0; row<rows; row++) {
            list.push_back(grid[row][col]);
        }
        ll res = do_math(list, operations[col]);
        // cout << "res: " << " " << res << "\n";
        answer += res;
    }
    return answer;
}

void solve() {
    vector<vector<ll>> grid;
    vector<char> operations;

    read_input(grid, operations);

    ll answer = do_homework(grid, operations);
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

