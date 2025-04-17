/*
Problem
An integer N greater than or equal to zero is given. In this case, write a program that outputs N!.

Input
The first line is given an integer N (0 ≤ N ≤ 20).

Output
Output N! on the first line.
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long ans = 1;
    for(int i=1;i<N+1;i++){
        ans = ans * i;
    }

    cout << ans;
}