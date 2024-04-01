#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){

    //수열의 개수 n 입력 받기
    int n;
    cin >> n;

    vector<char> resultArray;
    stack<int> stack;
    int inserted;
    int pushed = 0;
    bool success = true;
    


    //n번 돌리기
    for(int i = 0; i < n; i++){
     
        //수 하나 입력 받기
        cin >> inserted;

        //만약 입력 받은 수 > 현재까지 push 한 수, 계속 push + pop
        if(inserted > pushed){

            while(inserted > pushed){
                stack.push(++pushed);
                resultArray.push_back('+');
            }
            stack.pop();
            resultArray.push_back('-'); 
            
        }   
        //만약 입력 받은 수 = 스택의 탑이라면, pop
        else if(inserted == stack.top()){
            stack.pop();
            resultArray.push_back('-');
        }
        //만약 입력 받은 수 != 스택의 답이라면, 오류를 출력 
        else{
            cout << "NO\n";
            success = false;
            break;
        }
        
    }

    //전체 출력하기
    if(success == true){
        for(int i = 0; i < resultArray.size(); i++){
            cout << resultArray[i] << "\n";
        }
    }
}

