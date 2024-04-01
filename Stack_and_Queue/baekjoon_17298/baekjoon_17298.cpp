#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> Node; //index, value

int main(void){


    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //수열의 크기 N 입력 받기
    int N;
    cin >> N;
    int answer[N] = {0};
    stack<Node> stack;

    //N만큼 반복
    for(int i = 0; i < N; i++){
     
        //수 하나씩 입력 받기
        int A;
        cin >> A;

        //스택의 탑보다 값이 작거나 같으면 쌓고, 크면 스택을 pop하기
        //이때 pop된 요소의 오큰수는 현재 수이므로, 이를 정답배열에 입력
        if(stack.empty()){
            
            stack.push(Node{i, A});
        }
        else if(!stack.empty() && A <= stack.top().second){

            stack.push(Node{i, A});
        
        }else{

            while(!stack.empty() && A > stack.top().second){
        
                answer[stack.top().first] = A;
                stack.pop();
            }
            stack.push(Node{i, A});
        }
    }
 
    //스택에 남은 모든 애들의 오큰수는 -1로 정답배열에 입력
    while(!stack.empty()){
        answer[stack.top().first] = -1;
        stack.pop();
    }

    //정답배열 전체 출력
    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }
}