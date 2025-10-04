#include <iostream>
using namespace std;


bool prime(int n){
    if (n < 2 ) return false;
    for(int i = 2; i <n; i++)
        if(n % i == 0) return false;
    return true;
}

int main() 
{

    int a; cin >> a;

    if(prime(a)){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
    return 0;
}