#include <iostream>
using namespace std;

long A[1000001] = {0};
long S[1000001] = {0};
long C[1001] = {0};

int main(void){

    //시간 절약용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N,M int로 입력받기
    int N, M;
    long temp = 0;
    long count = 0;
    cin >> N >> M;

    //N개의 수 A[]에 입력받기, for문
    //for문 S[]에 부분합 저장하기
    for(int i = 1; i <= N; i++){

        cin >> temp;
        A[i] = temp;
        S[i] = S[i-1] + A[i];
    }

    //for문 S[]의 값들을 M으로 mod 연산해서 저장
    for(int i = 1; i <= N; i++){

        S[i] = S[i] % M;
        //만약 합배열의 mod 후 값이 0이라면 count++
        if(S[i] % M == 0){
            count++;
        }
        C[S[i]] += 1;
    }

    //나머지의 값이 같은 것들끼리 짝지어지는 수를 계산해야하므로, Combination 연산!
    for(int i = 0; i < M; i++){

        if(C[i] > 1){
            count += C[i] * (C[i]-1) / 2;
        }
    }

    //count 출력
    cout << count <<"\n";
}