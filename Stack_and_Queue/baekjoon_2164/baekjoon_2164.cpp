#include <iostream>
#include <deque>
using namespace std;


int main(void){
	
	//insert N
	int N;
	cin >> N;

	//declare queue
	deque<int> q;

	//push all cards
	for(int i = N; i > 0; i--){
		q.push_front(i);
	}

	//for statement
	//pop top one
	//pop next top one and push floor
	while(q.size() > 1){
		q.pop_front();
		q.push_back(q.front());
		q.pop_front();

	}
		
	//print output
	cout << q.front() << "\n";
    }

