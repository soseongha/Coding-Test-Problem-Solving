#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void){

    //수열의 개수 n
    int n;
    cin >> n;

    //스택 선언
    stack<int> myStack;
    queue<char> operation;
    int input = 1;

    //n번 루프
    for(int i = 0; i < n ; i++){

        //현재 숫자 입력 받기
        int now;
        cin >> now;

        //top에 now가 있다면 pop
        if( !myStack.empty() && myStack.top() == now){
            
            myStack.pop();
            operation.push('-');
            
        }//top에 now보다 큰 수가 있다면 실패
        else if(!myStack.empty() && myStack.top() > now){
        
            cout << "NO\n";
            return 0;

        }//그런게 아니라면 아직 수가 나오지 않은 것이니 now가 나올때까지 push, 나오면 pop
        else{

            while( myStack.empty() || myStack.top() != now){
                
                myStack.push(input);
                input++;
                operation.push('+');
                
            }
            myStack.pop();
            operation.push('-');
            
        } 
    }

    //출력
    while( !operation.empty() ){

        cout << operation.front() <<"\n";
        operation.pop();
    }
}

