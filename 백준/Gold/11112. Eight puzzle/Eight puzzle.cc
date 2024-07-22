#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

// Custom hash function for int[9]
struct ArrayHash {
    size_t operator()(const int* arr) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i = 0; i < 9; ++i) {
            seed ^= hasher(arr[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// Custom comparator for int[9]
struct ArrayEqual {
    bool operator()(const int* lhs, const int* rhs) const {
        return std::equal(lhs, lhs + 9, rhs);
    }
};

// Node structure
struct Node {
    int state[9]; // board state
    int x, y;     // empty space coordinates
    int h, g;     // g: depth of node, h: heuristic value (misplaced tiles)

    Node(const int* b, int emptyX, int emptyY, int hVal, int gVal)
        : x(emptyX), y(emptyY), h(hVal), g(gVal) {
        copy(b, b + 9, state);
    }

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
        if(pattern[i] != b[i]) 
            ++h;
    }
    return h;
}

void swap_tiles(const int* b, int x, int y, int nx, int ny, int* new_board) {
    copy(b, b + 9, new_board);
    swap(new_board[y * 3 + x], new_board[ny * 3 + nx]);
}

bool isGoal(const int* b) {
    return equal(b, b + 9, pattern);
}

bool isSolvable() {
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
    unordered_set<int*, ArrayHash, ArrayEqual> visited; // check visited states

    pq.push(Node(board, initX, initY, calcH(board), 0));

    if (!isSolvable()) {
        return -1;
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (isGoal(cur.state)) {
            return cur.g;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (is_oob(ny, nx))
                continue;

            int next[9];
            swap_tiles(cur.state, cur.x, cur.y, nx, ny, next);

            if (visited.count(next))
                continue;

            pq.push(Node(next, nx, ny, calcH(next), cur.g + 1));
            int* next_state = new int[9];
            copy(next, next + 9, next_state);
            visited.insert(next_state);
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
                // save the # as 0
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