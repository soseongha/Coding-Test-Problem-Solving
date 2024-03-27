#include <iostream>
using namespace std;

int main(void){

    //N 정의하고 읽기
    int N;
    cin >> N;

    //성적들 돌면서 하나씩 읽기, 최댓값 업데이트 실시간으로, sum이 충분히 작으므로 sum 미리 구하기
    float subjects[N];
    int max = 0;
    int swap;
    double sum = 0;
    
    for(int i = 0; i < N; i++){

        cin >> subjects[i];
        if(subjects[i] > max) max = subjects[i];
        sum += subjects[i];
    }
    
    //새로운 평균 계산하기
    cout << sum / max * 100 / N << "\n";

    return 0;

}