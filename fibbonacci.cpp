#include <iostream>
using namespace std;

int fibbonacci(int n){
    if(n <=1){
        return n;
    }
    return fibbonacci(n-1) + fibbonacci(n-2);
}
int main(){
    cout << "Fibbonacci of 8 is: " << fibbonacci(8) << endl;
    return 0;
}