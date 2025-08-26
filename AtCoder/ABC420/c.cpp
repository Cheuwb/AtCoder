#include <bits/stdc++.h>
using namespace std;

//ABC420 - C, Sum of Min Query
int minSum(const vector<int>& A, const vector<int>&B, int Nlegnth);

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

    // for each query, read in the query
    // process into the sequence
    // calculate using the min sum function
    for (int i =0; i < Qlength; ++i) {
        string C;
        int X;
        int V;
        cin >> C >> X >> V;

        if (C == "A") {
            // changes to sequene A
            Asequence[X-1] = V;
        } else {
            // changes to sequence B
            Bsequence[X-1] = V;
        }
        // calculate the minimumSum after sequence change
        cout << minSum(Asequence, Bsequence, Nlength) << endl;
    }

    return 0;
}

int minSum(const vector<int>& A, const vector<int>&B, int Nlength) {
    int minSum = 0;
    for (int n = 0; n < Nlength; ++n) {
        minSum += min(A[n], B[n]);
    }
    return minSum;
}