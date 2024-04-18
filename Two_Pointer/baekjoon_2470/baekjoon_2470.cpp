#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

	//N, numbers insert
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	//sort
	sort(A, A+N);

	//use two pointer to get optimal values
	int left = 0, right = N-1;
	int min = abs(A[left] + A[right]);
	int optLeft = left, optRight = right;
	while(left < right){
		
		if(abs(A[left] + A[right]) < min){
			min = abs(A[left] + A[right]);
			optLeft = left;
			optRight = right;
		}

		if(A[left] + A[right] >= 0){
			right--;
		}else{
			left++;
		}
	}

	//print output
	cout << A[optLeft] << " " << A[optRight] << "\n";

}
