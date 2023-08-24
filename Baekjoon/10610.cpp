#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    string s;
    int res;
    vector<int> str;
    //cin>>n;
    n=30;
    s = to_string(n);
    for(int i=0; i<s.size(); i++){
        str.push_back(s[i]-'0');
      // cout<<str[i]<<endl;
    }
    sort(str.begin(), str.end());
    
    for(int i=s.size()-1; i>=0; i--){
        res = 0;
        res += str[i]* pow(10,i);
        for(int j=i-1; j>=0; j--){
            res += str[j]* pow(10,j);
        }
        if(res % 30 == 0)break;
        else res =-1;
    }
    cout<<res;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    vector<int> digits(10, 0); // 각 숫자의 개수를 저장하는 배열
    int sum = 0; // 모든 숫자의 합

    for (char c : n) {
        int digit = c - '0';
        digits[digit]++;
        sum += digit;
    }

    if (digits[0] == 0 || sum % 3 != 0) { // 0이 없거나 숫자들의 합이 3의 배수가 아니면 30의 배수가 아님
        cout << -1;
    } else {
        for (int i = 9; i >= 0; i--) { // 큰 숫자부터 차례대로 출력
            while (digits[i] > 0) {
                cout << i;
                digits[i]--;
            }
        }
    }

    return 0;
}
