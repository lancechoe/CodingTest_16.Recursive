/*
Problem
The Fibonacci numbers begin with 0 and 1. The 0th Fibonacci number is 0, and the 1st Fibonacci number is 1. 
Then from the 2nd it is the sum of the previous two Fibonacci numbers.

Using this equation, Fn = Fn-1 + Fn-2 (n ≥ 2).

If you write the Fibonacci number until n=17, it is as follows.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

Write a program to find the nth Fibonacci number, given n.

Input
The first line is given by n. N is a natural number less than or equal to 20, or 0.

Output
Output the nth Fibonacci number on the first line.
*/

#include <iostream>
using namespace std;

int main(){
    int n1 = 0;
    int n2 = 1;
    int n3 = 1;
    int n;

    cin >> n;

    if(n == 0){
        cout << 0;

        return 0;
    }

    // n = 3이면
    for(int i=0;i<n-1;i++){
        n3 = n2 + n1; // n3 = 1 2
        n1 = n2; // n1 = 1 1
        n2 = n3; // n2 = 1 2
    } 
    
    
    cout << n3;
}