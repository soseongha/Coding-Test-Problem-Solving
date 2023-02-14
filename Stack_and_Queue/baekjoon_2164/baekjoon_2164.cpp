#include <iostream>
#include <deque>
using namespace std;


int main(void){

    //카드의 개수 N
    int N;
    cin >> N;

    //큐에 카드 구현
    deque<int> cards;
    for(int i = 1; i <= N; i++){
        
        cards.push_back(i);
    }

    //카드 셔플
    while(cards.size() > 1){

        //맨 앞의 카드를 빼기
        cards.pop_front();
        if(cards.size() <= 1){
            break;
        }

        //그 앞에 카드를 빼서 뒤로 넣기
        cards.push_back(cards.front());
        cards.pop_front();
    }

    //출력
    cout << cards.front() << "\n";
}

