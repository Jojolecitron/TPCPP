#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int is_prime(unsigned long long int value){
    int i(0);
    if (value == 1){
        return 0;
    }
    if (value == 2){
        return 1;
    }
    else if (value%2 == 0){
        return 0;
    }
    for(i = 3; i<sqrt(value); i+=2){
        if(!(value%i)){
            return 0;
        }
    }
    return 1;
}

int time_is_prime(void){
    int start = time(NULL);
    for(int i=0; i<1000000; i++){
        cout << i << " is prime; " << (is_prime(i) ? "True": "False") << endl;
    }
    return time(NULL) - start;
}


int main(){
    unsigned long long int n;
    cin >> n;
    do{
        cout << n << " is a prime: " << (is_prime(n) ? "True": "False") << '\n';
        cin >> n;
    }while(cin);
    // int t = time_is_prime();
    // cout << "finished in : " << t << " seconds" << endl;
    return 0;
}
