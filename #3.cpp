#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct rocket {
    int n;    
    long long t;  
    long long v;
};

bool comp(const rocket& a, const rocket& b) {
    return a.t < b.t;
}

int main() {

    long long t, v;
    vector <rocket> r(4);
    long long mn = 1;
    for (int i = 0; i < 4; i++) {
        cin >> t >> v;
        r[z].n = i;
        r[z].t = t;
        r[z].v = v;
        mn *= v;
    }
    long long dt, d;
    cin >> dt >> d;
    for (int z = 0; z < 4; z++) {
        r[z].t = r[z].t * mn + d * mn / r[z].v;
    }
    dt *= mn;
    sort(r.begin(), r.end(), comp); 
    for (int i = 1; i < 3; i++)     
        if (r[i].t == r[i + 1].t)  
            if (abs(r[i - 1].n - r[i].n) == 2) swap(r[i], r[i + 1]);
    int count = 1;   
    int i = 1;
    while (i < 4) { 
        if (r[i - 1].t + dt * (abs(r[i].n - r[i - 1].n) % 2 == 0 ? 2 : 1) <= r[i].t) {
            count++;
            i++;
        }
        else break;
    }
    if (count < 4) cout << count;
    else cout << "ALIVE";
    return 0;
}
