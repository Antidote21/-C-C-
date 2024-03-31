#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];

int main(){
    
    int A, B, C, maxEnd=0;
    cin>>A>>B>>C;
    for(int i = 0; i < 3; i++){
        int start, end;
        cin>>start>>end;
        maxEnd = max(maxEnd, end);
        for(int j=start; j<end; j++){
            arr[j]++;
        }
    }
    
    int sum = 0;
    for(int i = 0; i <= maxEnd; i++){
		if(arr[i] == 1)
			sum += arr[i] * A;
		else if(arr[i] == 2)
			sum += arr[i] * B;
		else if(arr[i] == 3)
			sum += arr[i] * C;
	}
    cout<<sum;
    
}
