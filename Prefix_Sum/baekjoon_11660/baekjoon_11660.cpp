#include <iostream>
using namespace std;
int S[1025][1025]= {0};

int main(void){
    
    //시간절약용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N,M을 입력받아 int로 저장
    int N, M;
    cin >> N >> M;

    int A;

    //N*N번 recursive로 
    //위에서 읽은 동시에 합배열 S를 2차원 배열로 저장
    //식은 S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
        
        cin >> A;
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A;

        }
    }

    //구간합 = S[x2][y2] - S[x2][y1-1] - S[x1-1,y2] + S[x1-1][y1-1] 
    int x1, x2, y1, y2;
    for(int i = 1; i <= M; i++){

        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1] << "\n"; 
    }
}