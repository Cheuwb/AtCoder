#include <bits/stdc++.h>
using namespace std;

// up down left right maze traversal
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int start_row = - 1, start_col = -1;
    int goal_row = -1, goal_col = -1;

    vector<string> maze(h);

    for (int i=0; i<h; ++i) {
        cin >> maze[i];

        for (int j=0; j<w; ++j) {
            if (maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
            if (maze[i][j] == 'G') {
                goal_row = i;
                goal_col = j;
            }
        }
    }

    //row, column, door toggle, # of steps taken
    queue<tuple<int, int, int, int>> q;
    vector<bool> door_toggle(2, false);
    vector<vector<bool>> row(w, door_toggle);
    // 3d matrix - two 2d matrix layered on top to track the different
    // states of the doors; treating visitation of each cell in the 2d matrix
    // differntly based on which triggered door toggles
    vector<vector<vector<bool>>> visited(h, row);

    q.push(make_tuple(start_row, start_col, 0, 0));
    // visited the initial starting position
    visited[start_row][start_col][0] = true;

    // BFS searching for path out
    while (!q.empty()) {
        auto [r, c, door_toggle, steps] = q.front();
        q.pop();

        if (r == goal_row && c == goal_col) {
            cout << steps << endl;
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            // out of bounds
            if (nr < 0 || nr >= h || nc < 0 || nc > w) continue;
            char cell = maze[nr][nc];
            int door_state = door_toggle;

            bool move = false;
            if (cell == '.' || cell == 'S' || cell == 'G') move = true;
            else if (cell == 'o') move = (door_state == 0);
            else if (cell == 'x') move = (door_state == 1);
            else if (cell == '?') {
                move = true;
                door_state = 1 - door_toggle;
            }

            if (move && !visited[nr][nc][door_state]) {
                visited[nr][nc][door_state] = true;
                q.push(make_tuple(nr, nc, door_state, steps + 1));
            }

        }
    }
    cout << -1 << endl;
    return 0;

}
