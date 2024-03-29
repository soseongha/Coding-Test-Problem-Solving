#include <iostream>
using namespace std;

int main(void){
    
    //시간절약용
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    //표의 크기 N, 질의 수 M 입력받기
    int N, M;
    cin >> N >> M;

    //for 돌면서 원본 배열 입력받기 -> 바로 구간합으로 생성
    int A;
    int S[N+1][N+1] = {0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            cin >> A;
            S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + A;  
        }
    }

    //for문 돌면서 질의 받기
    //미리 계산한 구간합 이용해서 출력
    int X1, Y1, X2, Y2;
    for(int i = 0; i < M; i++){

        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << S[X2][Y2] - S[X2][Y1-1] - S[X1-1][Y2] + S[X1-1][Y1-1] << "\n";

    }
}
    