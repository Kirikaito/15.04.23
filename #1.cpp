#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,sec, mult = 3600,Min,answ;
    cin >> n;
    string in,t;
    vector <string> clocks;
    vector <int> clocksec,movesec;
    for(int i=0;i<n;i++){
        sec = 0;
        t = "";
        cin >> in;
        for(int i = 0;i<in.size();i++){
            if(in[i] == ':'){
                sec += stoi(t)*mult;
                t = "";
                mult /= 60;
                i++;
            }
            t = t + in[i];
        }
        sec += stoi(t);
        clocks.push_back(in);
        clocksec.push_back(sec);
    }
    
    sec = 0;
    for(int j=1;j<n;j++){
        sec += (86400 + clocksec[0] - clocksec[j])%86400;
    }
    Min = sec;
    answ = 0;
    for(int i=1;i<n;i++){
        sec = 0;
        for(int j=0;j<n;j++){
            if(i == j){j++;}
            sec += (86400 + clocksec[i] - clocksec[j])%86400;
        }
        Min = min(Min,sec);
        if(Min == sec){answ = i;}
    }
    cout << clocks[answ];
    return 0;
}
