#include <iostream>
using namespace std;
int main(){
    int x=0;
    int y=5;
    int *xp = &x;
    int *yp = &y;
    int z = *yp;
    int k = *xp;
    cout<<z+k;
    
    return 0;
}