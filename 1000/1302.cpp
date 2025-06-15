#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> m;

int main(int argc, char* argv[]){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    // Find Max Value
    map<string, int> ::iterator p;
    int maxValue = 0;

    for(p = m.begin(); p != m.end(); p++){
        if(p->second > maxValue){
            maxValue = p->second;
        }
    }

    vector<string> v;
    for(p = m.begin(); p != m.end(); p++){
        if(p->second == maxValue){
            v.push_back(p->first);
        }
    }

    sort(v.begin(), v.end());
    
    cout << v[0];

    return 0;
}