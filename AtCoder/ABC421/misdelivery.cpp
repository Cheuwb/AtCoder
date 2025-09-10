#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // number of rooms

    vector<string> names;

    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
    }

    int x;
    cin >> x; // room #
    string y;
    cin >> y; // delivery name

    if (names[x-1] == y) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}