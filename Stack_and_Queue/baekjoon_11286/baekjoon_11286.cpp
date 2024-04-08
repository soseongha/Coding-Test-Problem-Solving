#include <iostream>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(int n1, int n2){
		
		if(abs(n1) > abs(n2)) return true;
		else if(abs(n1) < abs(n2)) return false;
		else{
			if(n1 > n2) return true;
			else return false;
		}
	}
};

int main(void){

	//N load
	int N;
	cin >> N;

	//make abs heap
	priority_queue<int, vector<int>, cmp> pq;	

	//for N times, calculate
	for(int i = 0; i < N; i++){
		//if not zero push the number

		int input;
		cin >> input;
		if(input != 0) pq.push(input);
		else{
			if(pq.empty()){
				cout << "0\n";
			}else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		
	}	
}
