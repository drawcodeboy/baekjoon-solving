#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int N;
    cin >> N;

    unsigned long long f_n2, f_n1;
    f_n2 = 0;
    f_n1 = 1;
    unsigned long long f_n = 0;

    if (N == 0 || N == 1){
        cout << N;
    }
    else{
        for (int i = 2; i <= N; i++){
        f_n = f_n1 + f_n2;
        f_n2 = f_n1;
        f_n1 = f_n;
        }
        cout << f_n;
    }

    return 0;
}