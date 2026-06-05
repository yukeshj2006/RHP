#include <iostream>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int L=s.length();
    for(int ctr=1;ctr<(1<<L);ctr++){
        string combi="";
        for(int sh=0;sh<10;sh++){
            if((ctr&(1<<sh))>0){
                combi+=s[sh];
            }
        }
        cout<<combi<<endl;
    }
}

int main() {
    // Write C++ code here
    solve();

    return 0;
}