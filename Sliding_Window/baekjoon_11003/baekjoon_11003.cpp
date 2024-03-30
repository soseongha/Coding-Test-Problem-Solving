#include <iostream>
#include <deque>
#include <vector>
using namespace std;

typedef pair<int, int> Number;

int main(void){

    //시간절약용
    ios::sync_with_stdio(false); //이거 false 없으면 적용이 안됑 
    cin.tie(NULL);
    cout.tie(NULL);

    //N, L, 수 배열 입력받기
    int N, L;
    cin >> N >> L;

    //덱 선언하기
    deque<Number> window;

    //슬라이딩 윈도우 알고리즘으로 구현
    for(int i = 0; i < N; i++){

        //입력도 즉석으로 받기
        int A;
        cin >> A;

        //비교해서 큰 것은 빼기
        while(window.size() && window.back().second > A){
            window.pop_back();
        }

        //덱에 현재 요소 삽입
        window.push_back(Number{i, A});
        
        //윈도우 범위 아닌 것 빼기
        if(window.front().first < i-L+1) window.pop_front();

        //현재의 최솟값 출력
        cout << window.front().second << " ";
    }

}