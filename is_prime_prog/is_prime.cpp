#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int is_prime(long long int value){
    unsigned long long int i(0);
    if (value == 1){
        return 0;
    }
    if (value == 2){
        return 1;
    }
    else if (value%2 == 0){
        return 0;
    }
    for(i = 3; i<=sqrt(value); i+=2){
        if(!(value%i)){
            return 0;
        }
    }
    return 1;
}

int main(){
    unsigned long long int n;
    cin >> n;
    do{
        cout << n << " is a prime: " << (is_prime(n) ? "True": "False") << '\n';
        cin >> n;
    }while(cin);
    return 0;
}
