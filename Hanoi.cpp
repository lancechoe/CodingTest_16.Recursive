/*
Problem
There are three poles, and the first pole is stacked with n disks of different radii. Each disk is stacked in the order of its largest radius. Now the monks try to move from the first pole to the third pole according to the following rule.

Only one disk can be moved to another tower at a time.
The stacked disk should always be smaller than the top.
Write a program that outputs the sequence of movements required to perform this task; however, the number of movements should be minimal.

The figure below is an example of a case where there are five disks.



Input
In the first line, the number N (1 ≤ N ≤ 20) of disks stacked on the first pole is given.

Output
Outputs the number of times K transferred to the first line.

Starting with the second line, we output the sequence. Over K lines from the second line, we output two integers, A B, with a blank space between them, which means that the disk at the top of the A-th tower is moved to the top of the B-th tower.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> moves;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }
    hanoi(n - 1, from, aux, to);
    moves.push_back({from, to});
    hanoi(n - 1, aux, to, from);
}

int main() {
    int N;
    cin >> N;

    hanoi(N, 1, 3, 2); // N개의 원판을 1번에서 3번으로, 2번은 보조

    cout << moves.size() << '\n';
    for (auto m : moves) {
        cout << m.first << " " << m.second << '\n';
    }

    return 0;
}
