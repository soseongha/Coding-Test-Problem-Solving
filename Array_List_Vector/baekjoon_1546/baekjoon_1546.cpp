#include <iostream>
using namespace std;

int main(void){

    //N 읽고 저장하기   
    int N = 0;
    cin >> N;

    //N번의 int형 점수 읽고 배열에 저장하기
    int subjects[1000]; //평균은 double일 수 있지만, 점수는 int라고 명시됨!!
    int temp = 0;
    for(int i = 0; i < N; i++){
        cin >> temp;
        subjects[i] = temp; 
    }

    //배열에서 가장 큰 수 찾기(O(n))
    int max = 0;
    for(int i = 0; i < N; i++){
        if(subjects[i] > max){
            max = subjects[i];
        } 
    }

    //모든 과목의 점수 다시 계산하기(O(n)) + 평균내기
    long sum = 0;
    double average = 0;
    for(int i = 0; i < N; i++){
        sum += subjects[i];
    }
    average = sum * 100.0 / max/ N; // 100 대신 100.0을 씀으로써 이 계산식을 double로 암시적 형변환

    //출력
    cout << average << "\n";

}