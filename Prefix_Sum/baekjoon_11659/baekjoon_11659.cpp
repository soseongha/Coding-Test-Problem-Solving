#include <iostream>
using namespace std;

int main(void){

    //시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N, M 입력받기
    int N, M;
    cin >> N >> M;

    //N개의 수 입력받기 -> 입력받는 즉시 구간합 배열에 입력
    int S[N + 1];
    int a = 0;
    S[0] = 0; //index 하나씩 뒤로 밀림

    for(int i = 0; i < N; i++){

        cin >> a;
        S[i + 1] = S[i] + a;
    }

    //M개의 질의 반복
    //한번 질의 할 때, 구간합 배열에서 계산해서 결과 바로 출력
    int rangeI, rangeJ;
    for(int i = 0; i < M; i++){

        cin >> rangeI >> rangeJ;
        cout << S[rangeJ] - S[rangeI-1] << "\n";
    }

    

}