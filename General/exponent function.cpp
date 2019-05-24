// Implement an exponent function (bonus: now try in log(n) time)


#include <iostream>
#include <cmath>
using namespace std;

float power(float x, int y) {
    
    float temp;
    if (y == 0) return 1;
    
    temp = power(x, y/2);
    if (y%2 == 0) return (temp * temp);
    
    else {
        if(y > 0) return (x * temp * temp);
        else return ((temp * temp ) / x);
    }
}

int main() {

    float x = 2;
    int y = -3;
    cout << power(x, y) << endl;
}




/*
// or just use the stl library to call the exp function
 
int main () {
    double param, result;
    param = 5.0;
    result = exp (param);
    cout << "The exponential value of " << param << " is: " << result << endl;
}
*/
