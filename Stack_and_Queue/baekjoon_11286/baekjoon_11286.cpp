#include <iostream>
#include <queue>
using namespace std;

struct comp{

    bool operator()(int parent, int child){

        if( abs(parent) > abs(child) ) return true;
        else if( abs(parent) == abs(child) ){
            
            if(parent > child) return true;
            else return false;
        }
        else return false;
    }
};

int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //우선순위 큐 정의
    priority_queue<int, vector<int>, comp> pq;

    //연산의 개수 N 입력받기
    int N;
    cin >> N;

    //N번의 연산 하기
    for(int i = 0; i < N; i++){

        int inst;
        cin >> inst;

        //만약 0을 입력받았다면
        if(inst == 0){

            //큐가 비어있다면 0 출력
            if(pq.empty()){

                cout << "0\n";
            }//아니라면 top 출력
            else{

                cout << pq.top() << "\n";
                pq.pop();
            }
        }//만약 0이 아니라면 push
        else{

            pq.push(inst);
        }
    }

    return 0;
}