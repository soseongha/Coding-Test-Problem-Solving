#include <iostream>
using namespace std;

int main(void){

    //아래만으로도 시간초과이므로 추가
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //수의 개수 N과 합의 개수 M을 int로 입력받고 저장
    int N = 0, M = 0;
    cin >> N >> M;    

    //N번 for문으로 돌려서 A를 int로 입력받고 동시에 합배열 S도 저장함
    int A;
    int S[100000];
    for(int i = 0; i < N; i++){

        cin >> A;
        if(i == 0){
            S[i] = A;
        }else{
            S[i] = S[i-1] + A;
        }
    }

    //M번을 for문으로 돌려서 i,j를 int로 입력받고, 동시에 부분합 공식을 통해 S[i,j] = S[j] - S[i-1]을 계산하고 출력 
    int begin = 0, end = 0;
    for(int i = 0; i < M; i++){

        cin >> begin >> end;
        begin--;
        end--;
        if(begin == 0){
            cout << S[end] - 0 <<"\n";
        }
        else{
            cout << S[end] - S[begin - 1] <<"\n";
        }
    }

}