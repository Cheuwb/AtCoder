#include <bits/stdc++.h>
using namespace std;

// Ex5.01 a new year

int main() {
    // today, december 30
    // input M = hour on Dec 30
    // New year = Jan 1
    // 24 hours + 24 - M = remaining time
    int M;
    cin >> M;
    cout << 24 + (24 - M); 
    return 0;
}
