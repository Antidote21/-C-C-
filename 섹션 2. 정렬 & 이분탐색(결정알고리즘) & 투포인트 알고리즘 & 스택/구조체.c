#include<iostream>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;  

struct Loc {
    int x, y, z;
    Loc(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    } 
    bool operator<(const Loc &b) const { 
        return x < b.x;
    }
};

int main() {
    vector<Loc> XY;
    XY.push_back(Loc(2, 3, 5));
    XY.push_back(Loc(3, 6, 7));
    XY.push_back(Loc(2, 3, 1));
    XY.push_back(Loc(5, 2, 3));
    XY.push_back(Loc(3, 1, 6));
    sort(XY.begin(), XY.end());
    for(auto pos : XY) {
        std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    }
    return 0;
}
