#include <iostream>
#include <vector>
using namespace std;

int main(void){

	//N insert
	int N;
	cin >> N;

	//numbers insert
	int numbers[N];
	for(int i = 0; i < N; i++){
		cin >> numbers[i];
	}
	
	//bubble sort
	int swap;
	for(int i = N-1; i > 0; i--){
		for(int j = 0; j < i; j++){

			if(numbers[j] > numbers[j+1]){
				swap = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = swap;
			}
		}
	}

	//print result
	for(int i = 0; i < N; i++){
		cout << numbers[i] << "\n";
	}
}
