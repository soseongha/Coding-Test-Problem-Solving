#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){


    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N개의 수
    int N;
    cin >> N;//밑에서 nums, answ 초기화하려면 N 먼저 입력받아야돼 이게 위에 있어야해
    vector<int> nums(N, 0);
    vector<int> answ(N, 0); //얘네 초기화 하는 거 잊지말자, 초기화 안해놓고 여기에 인덱스로 접근하면 runtime error
    stack<int> myStack;
   

    //N개의 수 입력받기
    for(int i = 0; i < N; i++){

        cin >> nums[i];
    }

    //본격적으로 !
    for(int i = 0; i < N; i++){

        //현재 새 수가 스택의 top보다 크다면, 오큰수로 출력하고 top을 pop함(top이 안클때까지 반복)
        while( !myStack.empty() && nums[myStack.top()] < nums[i] ){

            answ[myStack.top()] = nums[i];
            myStack.pop();
        }

        //현재의 수를 push
        myStack.push(i);

    }

    //스택에서 남은 수만큼 -1 찍기
    while( !myStack.empty()){
        
        answ[myStack.top()] = -1;
        myStack.pop();
    }

    //전체 answer 배열 출력하기
     for(int i = 0; i < N; i++){
    
        cout << answ[i] << " ";
    }

    return 0;
}