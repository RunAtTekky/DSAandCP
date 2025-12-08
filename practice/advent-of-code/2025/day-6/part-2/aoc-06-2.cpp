#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const char ADDITION = '+';

void take_input(vector<string>& grid, string& operations) {
    vector<string> inputs; string input_line;
    while (getline(cin, input_line)) {
        inputs.push_back(input_line);
    }

    for (int i=0; i+1<inputs.size(); i++) grid.push_back(inputs[i]);

    operations = inputs.back();
}

ll do_homework(vector<string>& grid, string& operations) {
    ll result = 0;
    // TODO: Do homework

    ll cols = grid[0].size(), rows = grid.size();

    ll idx = 0, curr_calculation = 1;
    char curr_operation = '+';
    for (int col=0; col<cols; col++) {
        string number = "";
        if (operations[col] != ' ') {
            curr_operation  = (operations[col] == ADDITION) ? '+' : '*';
        }

        for (int row=0; row<rows; row++) {
            char ch = grid[row][col];
            if (ch != ' ') number.push_back(ch);
        }

        if (number == "" || (col == cols-1) ) {
            ll old_result = 0;
            if (curr_operation == ADDITION) {
                result += (number == "") ? 0 : stoll(number);
            } else {
                result += curr_calculation;
                curr_calculation = 1;
            }
            idx++;
            // cout << "diff: " << " " << result - old_result << "\n";
            continue;
        }

        if (curr_operation == ADDITION) {
            // cout << "number: " << " " << number << "\n";
            result += stoll(number);
        } else {
            curr_calculation *= stoll(number);
        }
    }

    return result;
}

void solve() {
    // TODO: Solve the problem
    vector<string> grid;
    string operations;

    take_input(grid, operations);

    // for (auto &line : grid) cout << line << "\n";
    // cout << "\n";
    //
    // cout << operations << "\n";

    ll homework_result = do_homework(grid, operations);
    cout << homework_result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

