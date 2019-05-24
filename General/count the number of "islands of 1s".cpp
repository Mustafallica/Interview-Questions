// Given a 2D array of 1s and 0s, count the number of "islands of 1s" (e.g. groups of connecting 1s)

#include <iostream>
using namespace std;

int main() {
    int m,n;
    int a[100] [100];
    bool found = false;
    
    cout << " m & n :" ;
    cin>>m >>n;
    
    cout<<" Enter matrix elements : ";
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin>>a[i][j];
        }
    }
    
    int xiter [] = { 1, 0 , -1 ,0 };
    int yiter [] = { 0, 1 , 0 ,-1 };
    
    int island_count = 0;
    
    
    // Count number of islands -
    for (int i =0 ; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                bool island = true;
                a[i][j] = 2;
                for (int k = 0; k < 4; k++) {
                    int x = i+ xiter[k];
                    int y = j + yiter[k];
                    if (x < 0 || y < 0 || x >=m || y>= n)
                        continue;
                    if (a[x][y] == 1) {
                        a[x][y] = 2;
                    } else if (a[x][y] == 2) {
                        island = false;
                    }
                }
                if (island)
                    island_count++;
            }
        }
    cout << " Number of islands : " << island_count <<endl;
    
    return 0;
}
