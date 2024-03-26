#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int x,y,w,h;
    int a, b;
    cin >> x >> y >> w >> h;
    a = min(x,y);
    b = min(w-x,h-y);
    cout << min(a,b);
}
