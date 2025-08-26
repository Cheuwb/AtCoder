#include <bits/stdc++.h>
using namespace std;

int main() {
    int Nvoters, Mrounds;

    cin >> Nvoters >> Mrounds;

    vector<string> voteData(Nvoters);

    for (int round = 0; round < Nvoters; ++round) {
        cin >> voteData[round];
    }

    vector<int> voterScore(Nvoters);
    int maxScore = 0;

    for (int round = 0; round < Mrounds; ++round) {
        vector<int> voterState(Nvoters);
        int votedOne = 0;
        for (int voterID = 0; voterID < Nvoters; ++voterID) {
            // vote data per round casted by voter_id
            // cout << voteData[voterID][round];
            char vote = voteData[voterID][round];
            // the voter voted for vote's value (0 or 1)
            voterState[voterID] = vote - '0';

            // calculating round's minority vote
            if (vote - '0' == 1) {
                votedOne++;
            }
        }
        // 1. end of round, check for minority
        // 2. increase voters in minority's score
        if (votedOne == 0 || Nvoters - votedOne == 0) {
            for (int i = 0; i < Nvoters; ++i) {
                if (++voterScore[i] > maxScore) {
                    maxScore = voterScore[i];
                }
            }
        } else if (votedOne > Nvoters - votedOne) {
            // one majority == zero minority
            for (int i = 0; i < Nvoters; ++i) {
                if (voterState[i] == 0) {
                    if (++voterScore[i] > maxScore) {
                        maxScore = voterScore[i];
                    }
                }
            }
        } else {
            // one minority
            for (int i = 0; i < Nvoters; ++i) {
                if (voterState[i] == 1) {
                    if (++voterScore[i] > maxScore) {
                        maxScore = voterScore[i];
                    }
                }
            }
        }
    }

    // test the tallying
    for (int i =0; i < Nvoters; ++i) {
        if (voterScore[i] == maxScore) {
            cout << i + 1 << " ";
        }
        // cout << voterScore[i] + 1 << " ";
    }

    return 0;
}
