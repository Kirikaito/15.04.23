#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,in,full = 0,answ=0;
    vector<int> cup,space;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> in;
        cup.push_back(in);
        space.push_back(0);
    }
    sort(cup.begin(), cup.end(), greater<int>());
    
    int i = 0, j = n - 1;
    while(full != n and full != n - 1){
        cup[i]--;
        cup[j]--;
        answ++;
        if(cup[i] == 0){
            full++;
            i++;
        }
        if(cup[j] == 0){
            full++;
            j--;
        }
    }
    cout << answ;
    return 0;
}
