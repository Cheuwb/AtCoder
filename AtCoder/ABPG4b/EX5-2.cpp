#include <bits/stdc++.h>
using namespace std;

int main() {
    int R; // current rating
    int G; // goal

    cin >> R >> G;

    // (R + s) / 2 = G
    // 2G - R = s

    cout << (2 * G) - R;
    return 0;
}