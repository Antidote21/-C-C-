#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
  
  int x,y;
	x = (b * f - e * c) / (b * d - a * e);
	y = (a * f - d * c) / (a * e - b * d);

	cout << x << " " << y;
}

#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    
    cin >> a >> b >> c >> d >> e >> f;
    
    for(int i = -999; i <= 999; i++)
    {
        for(int j = -999; j <= 999; j++)
        {
            if(a * i + b * j == c && d * i + e * j == f)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
}
