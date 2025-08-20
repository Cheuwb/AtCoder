#include <bits/stdc++.h>
using namespace std;

int main() {
    // N * N square
    // Paint input A white, then remaining B = black
    int N, A;

    cin >> N >> A;

    cout << (N * N) - A;

    return 0;
}