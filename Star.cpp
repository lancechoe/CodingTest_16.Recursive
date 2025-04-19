/*
Problem
Let's take a picture of the star in a recursive pattern. If N is a power of 3, 9, 27, ..., the pattern of magnitude N is in the shape of an N×N square.

The pattern of size 3 is a pattern with a space in the center and a star in all compartments except the center.

***
* *
***
When N is greater than 3, the pattern of size N surrounds the (N/3)×(N/3) square in the middle filled with a blank pattern of size N/3. For example, a pattern of size 27 is shown in Example 1.

Input
The first line is given by N. N is a power of 3. That is, for some integer k, n = 3k, where 1 ≤ k < 8.

Output
It outputs stars from the first line to the Nth line.
*/

#include <iostream>
using namespace std;

char board[2200][2200]; // 최대 2187 x 2187

void fillBlank(int x, int y, int size) {
    if (size == 1) return;

    int block = size / 3;

    // 가운데를 공백으로 바꾸기
    for (int i = x + block; i < x + 2 * block; ++i) {
        for (int j = y + block; j < y + 2 * block; ++j) {
            board[i][j] = ' ';
        }
    }

    // 9개의 부분 중 가운데 제외한 8개를 재귀 호출
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            fillBlank(x + i * block, y + j * block, block);
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 일단 전체를 별로 채움
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = '*';

    fillBlank(0, 0, N); // 재귀 시작

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}
