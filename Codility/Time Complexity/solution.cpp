/*
<math.h>
floor:내림
ceil:올림
round:반올림
*/
#include <math.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    return ceil((Y-X)/(double)D);
}
