#include <bits/stdc++.h>
using namespace std;

/*
You can only ask 2n times
You want a binary string password of length n
With bruteforce it is going to take 2^n queries 

Waitttttt..... I think it is really simple
Lets say we have a bigggg binary string
First we try to find if half as big 0's are a part of it
Then half as big 1's are a part of it.



*/

int n; 

string getPassword(string suffix) {
        if (suffix.size() == n) return suffix;

        cout << "? 1" << suffix << "\n";

        // Flushing the output buffer
        cout.flush();

        // Program gives a result (1 Correct) (0 Incorrect) (-1 Error)
        int response; cin >> response;

        if (response == -1) return suffix;

        if (response == 1) {
            return getPassword("1" + suffix);
        }

        cout << "? 0" << suffix << "\n";

        // Flushing the output buffer
        cout.flush();

        // Program gives a result (1 Correct) (0 Incorrect) (-1 Error)
        cin >> response;

        if (response == -1) return suffix;

        if (response == 1) {
            return getPassword("0" + suffix);
        }

        return suffix;


}

string getSuffix(string guess) {
        if (guess.size() == n) return guess;
        cout << "? " << guess << "0" << "\n";

        // Flushing the output buffer
        cout.flush();

        // Program gives a result (1 Correct) (0 Incorrect) (-1 Error)
        int response; cin >> response;

        if (response == -1) return guess;

        if (response == 1) {
            return getSuffix(guess+"0");
        }

        cout << "? " << guess << "1" << "\n";

        // Flushing the output buffer
        cout.flush();

        // Program gives a result (1 Correct) (0 Incorrect) (-1 Error)
        cin >> response;

        if (response == -1) return guess;

        if (response == 1) {
            return getSuffix(guess+"1");
        }

        return guess;

}


void solve() {
    cin >> n;

    string suffix = getSuffix("");

    string password = getPassword(suffix);

    cout << "! "<< password << "\n";

    cout.flush();

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
