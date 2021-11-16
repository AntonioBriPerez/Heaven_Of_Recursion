#include <iostream>
using namespace std;




//return x + 1
int suc(int x) {
    return x + 1;
}


//return x+y
int suma(int x, int y){
    if (x == 0) return y;
    if (y == 0) return x;
    else{
        return suc(suma(x, y - 1));
    }
}

//return x*y
int mult(int x, int y){
    if (x == 0   || y == 0) return 0;
    if (x== 1) return y;
    if (y== 1) return x;
    else {
        return suma(x , mult(x, y - 1));
    }
}

// return x^y
int exp(int x, int y) {
    if(x==0) return 0;
    if(y==0) return 1;
    else{
        return mult(x,  exp(x, y - 1));
    }
}
int main(){
    cout << exp(2, 4) << endl;
    cout << mult(10, 3) << endl;
    cout << suma(5, 7) << endl;
}