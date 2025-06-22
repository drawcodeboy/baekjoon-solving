#include <iostream>
using namespace std;

int A, B;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> A >> B;

    int result = 1;

    while(true){
        // cout << B << '\n';
        if (B == A){
            cout << result;
            break;
        }
        else if(B < A){
            cout << -1;
            break;
        }
        else if (B % 2 == 0){
            B /= 2;
            result += 1;
        }
        else if ((B - 1) % 10 == 0){
            B /= 10;
            result += 1;
        }
        else{
            cout << -1;
            break;
        }
    }
}