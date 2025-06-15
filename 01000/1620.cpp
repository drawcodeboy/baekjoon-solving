// atoi(iostream에 있음)이랑 string.c_str()이 핵심인 문제
// map을 안다는 가정하에
#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, int> m1;
map<int, string> m2;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 1;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string a; cin >> a;
        m1[a] = cnt;
        m2[cnt] = a;
        cnt++;
    }

    for(int i = 0; i < M; i++){
        string a; cin >> a;
        if(atoi(a.c_str()) != 0){
            cout << m2[atoi(a.c_str())] << '\n';
        }
        else{
            cout << m1[a] << '\n';
        }
    }

    return 0;
}