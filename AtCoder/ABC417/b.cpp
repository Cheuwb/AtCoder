#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, int> A;

    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        A[a]++;
    }

    for (int i=0; i<m; ++i) {
        int b;
        cin >> b;
        A[b]--;
    }

    for (const auto& pair: A) {
        // for value of pair print key that many times
        int count = pair.second;
        while (count > 0) {
            cout << pair.first << " ";
            count--;
        }
    }

    cout << endl;

    return 0;
}

// search and delete