#include <bits/stdc++.h>
using namespace std;

//ABC420 - C, Sum of Min Query
long long minSum(const vector<int>& A, const vector<int>&B, int Nlegnth);

int main() {
    int Nlength;
    int Qlength;

    cin >> Nlength >> Qlength;

    vector<int> Asequence(Nlength);
    vector<int> Bsequence(Nlength);

    for (int i=0; i<Nlength; ++i) {
        cin >> Asequence[i];
    }

    for (int i=0; i<Nlength; ++i) {
        cin >> Bsequence[i];
    }

    long long sum = minSum(Asequence, Bsequence, Nlength);

    // for each query, read in the query
    // process into the sequence
    // calculate using the min sum function
    for (int i =0; i < Qlength; ++i) {
        string C;
        int X;
        int V;
        cin >> C >> X >> V;

        int oldMin = min(Asequence[X-1], Bsequence[X-1]);

        if (C == "A") {
            Asequence[X-1] = V;
        } else {
            Bsequence[X-1] = V;
        }

        int newMin = min(Asequence[X-1], Bsequence[X-1]);

        sum += newMin - oldMin;

        cout << sum << endl;
    }

    return 0;
}

long long minSum(const vector<int>& A, const vector<int>&B, int Nlength) {
    long long minSum = 0;
    for (int n = 0; n < Nlength; ++n) {
        minSum += min(A[n], B[n]);
    }
    return minSum;
}