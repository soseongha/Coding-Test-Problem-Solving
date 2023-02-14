#include <iostream>
#include <deque>
using namespace std;
typedef pair<int,int> Node;//value와 index를 담는 노드


int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    //N개의 수, 범위 L
    int N, L;
    cin >> N >> L;

    //N개의 노드를 덱으로 관리
    deque<Node> mydeque;
    for(int i = 0; i < N; i++){
        
        //새 노드 생성
        int value;
        cin >> value;
        Node newNode = {value, i};

        //맨 뒤 노드가 새 노드보다 크면 계속 pop
        while(mydeque.size() > 0 && mydeque.back().first > newNode.first){
            mydeque.pop_back();
        }
        
        //뒤에서 뺄 거 다 빼고 난 뒤에 새 노드 push
        
        mydeque.push_back(newNode);
        
        //맨 앞에서 범위 벗어나는 노드 pop
        if(mydeque.back().second - mydeque.front().second >= L){
            mydeque.pop_front();
        }

        //맨 앞 노드 = 최솟값 프린트
        cout << mydeque.front().first << " ";

    }

}