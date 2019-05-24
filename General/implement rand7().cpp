// Given a function rand5() that returns a random int between 0 and 5, implement rand7()





#include <iostream>
using namespace std;

int rand5() { // given method that returns 1 to 5 with equal probability

    // some code here
}

int rand7() { // returns 1 to 7 with equal probability

    int i = 5 * rand5() + rand5() - 5;
    if (i < 22) return (i % 7 + 1);
    return rand7();
}


int main() {
    cout << rand7() << endl;
}



// program just to implement rand7() using the given rand5() func.
