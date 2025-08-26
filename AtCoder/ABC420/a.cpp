#include <bits/stdc++.h>
using namespace std;

int main() {
    //TWO INPUTS [X, Y]
    int x, y;
    cin >> x >> y;

    int z = (x + y) % 12;
    if (z == 0) z = 12;

    cout << z;

    return 0;
}