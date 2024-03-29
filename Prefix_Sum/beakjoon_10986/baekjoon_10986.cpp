#include <iostream>
using namespace std;

int main(void){

    //시간절약용
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    //N, M 입력받기
    int N, M;
    cin >> N >> M;

    //N개의 수를 입력받기
    long S[N+1] = {0};
    int A;
    for(int i = 0; i < N; i++){
        cin >> A;
        S[i+1] = S[i] + A;
    }

    //for문 돌면서 나머지 별 개수 얻기
    int remainder;
    long C[M] = {0}; //이게 int 이면 실패 뜬다... why?
    for(int i = 0; i < N; i++){
    
        remainder = S[i+1] % M;
        C[remainder]++;
    
    }

    //선택의 개수 계산(cC2)해서 출력
    long result = 0;
    for(int i = 0; i < M; i++){

        result += C[i] * (C[i]-1) / 2;
    }
    result += C[0];
    cout << result << "\n";
    
}
