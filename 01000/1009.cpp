#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int a, b; cin >> a >> b;
        vector<int> last;
        int orig = a;
        last.push_back(a % 10);
        while(true){
            a = (a * orig) % 10;
            if(a == last[0]) break;
            last.push_back(a);
        }

        int index = (b % last.size());
        index = (index == 0) ? last.size() - 1 : index - 1;
        int result = last[index];
        if (result == 0){
            cout << 10 << '\n';
        }
        else {
            cout << result << '\n';
        }
    }
    return 0;
}