#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; // string length
    int A; // number of characters to remove from the beginning
    int B; // number of characters to remove from the end
    string S;

    // 7 1 3
    // Jasmine

    cin >> N >> A >> B >> S;

    //1st loop remove all the characters at the end
    for (int i = N-1; i > N-B-1; --i) {
        S.pop_back();
    }

    string s = S.erase(0, A);

    // return S
    cout << s << endl;

    return 0;
}

// a substring