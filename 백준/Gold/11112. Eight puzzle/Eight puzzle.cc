#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

// Node structure
struct Node {
    int state; // packed board state as a single integer
    int x, y;  // empty space coordinates
    int h, g;  // g: depth of node, h: heuristic value (misplaced tiles)

    Node(int b, int emptyX, int emptyY, int hVal, int gVal)
        : state(b), x(emptyX), y(emptyY), h(hVal), g(gVal) {}

    // Define a comparator for the priority queue
    bool operator<(const Node &other) const {
        int f = g + h, other_f = other.g + other.h;
        if(f != other_f) return f > other_f;
        else return g > other.g;
    }
};

int n;
int board[9];
int pattern[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// Helper function to pack the board into an integer
int pack(const int* b) {
    int res = 0;
    for (int i = 0; i < 9; ++i) {
        res = res * 10 + b[i];
    }
    return res;
}

// Helper function to unpack the integer into a board
void unpack(int state, int* b) {
    for (int i = 8; i >= 0; --i) {
        b[i] = state % 10;
        state /= 10;
    }
}

// Helper function
void print_board(const int* b) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << b[i * 3 + j] << " ";
        }
        cout << endl;
    }
}

bool is_oob(int y, int x) {
    return y < 0 || y >= 3 || x < 0 || x >= 3;
}

// Calculate heuristic value (Manhattan distance)
int calcH(const int* b) {
    int h = 0;
    for (int i = 0; i < 9; ++i) {
        if (b[i] != 0) {
            int target = b[i] - 1;
            h += abs(i / 3 - target / 3) + abs(i % 3 - target % 3);
        }
    }
    return h;
}

void swap_tiles(const int* b, int* new_board, int x, int y, int nx, int ny) {
    copy(b, b + 9, new_board);
    swap(new_board[y * 3 + x], new_board[ny * 3 + nx]);
}

bool isGoal(const int* b) {
    return equal(b, b + 9, pattern);
}

bool isSolvable(const int* board) {
    int inv = 0;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == 0)
            continue;
        for (int j = 0; j < i; ++j) {
            if (board[j] > board[i])
                ++inv;
        }
    }
    return inv % 2 == 0; // if inv is even, it is solvable
}

int solve(int initX, int initY) {
    priority_queue<Node> pq;
    unordered_set<int> visited; // check visited states

    int initial = pack(board);
    pq.push(Node(initial, initX, initY, calcH(board), 0));
    visited.insert(initial);

    if (!isSolvable(board)) {
        return -1;
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int cur_board[9];
        unpack(cur.state, cur_board);

        if (isGoal(cur_board)) {
            return cur.g;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (is_oob(ny, nx))
                continue;

            int next[9];
            swap_tiles(cur_board, next, cur.x, cur.y, nx, ny);

            int packed_next = pack(next);

            if (visited.count(packed_next))
                continue;

            pq.push(Node(packed_next, nx, ny, calcH(next), cur.g + 1));
            visited.insert(packed_next);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--) {
        char temp[5];
        int initX, initY;

        for (int i = 0; i < 3; ++i) {
            cin >> temp;
            for (int j = 0; j < 3; ++j) {
                if (temp[j] == '#') {
                    board[i * 3 + j] = 0;
                    initY = i;
                    initX = j;
                    continue;
                }
                board[i * 3 + j] = temp[j] - '0';
            }
        }

        int moves = solve(initX, initY);
        if (moves == -1) {
            cout << "impossible" << endl;
        } else {
            cout << moves << endl;
        }
    }

    return 0;
}