#include <iostream>
#include <string>
using namespace std;

int main(void){

    //시간절약용
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    //전체 문자열의 길이 S, 부분 문자열의 길이 P, 문자열 fullDNA, 각 염기의 수 입력 받기
    int S, P;
    string fullDNA;
    int A, C, G, T;

    cin >> S >> P;
    cin >> fullDNA;
    cin >> A >> C >> G >> T;
    
    //초반 부분문자열 P를 세기
    int partDNA[4] = {0, 0, 0, 0}; //A, C, G, T
    int count = 0;
    for(int i = 0; i < P; i++){
        
        if(fullDNA[i] == 'A') partDNA[0]++;
        else if(fullDNA[i] == 'C') partDNA[1]++;
        else if(fullDNA[i] == 'G') partDNA[2]++;
        else if(fullDNA[i] == 'T') partDNA[3]++;
    }
    if(partDNA[0] >= A && partDNA[1] >= C && partDNA[2] >= G && partDNA[3] >= T) count++;

    //전체 문자열을 한바퀴 돌기
    //그 안에서 P 길이 만큼만 다시 보되, 추가된 염기와 제거된 염기만 고려하기(시간복잡도 줄임)
    for(int i = 0; i < S-P; i++){
  
        if(fullDNA[i] == 'A') partDNA[0]--;
        else if(fullDNA[i] == 'C') partDNA[1]--;
        else if(fullDNA[i] == 'G') partDNA[2]--;
        else if(fullDNA[i] == 'T') partDNA[3]--;

        if(fullDNA[i+P] == 'A') partDNA[0]++;
        else if(fullDNA[i+P] == 'C') partDNA[1]++;
        else if(fullDNA[i+P] == 'G') partDNA[2]++;
        else if(fullDNA[i+P] == 'T') partDNA[3]++;

        if(partDNA[0] >= A && partDNA[1] >= C && partDNA[2] >= G && partDNA[3] >= T) count++;
    }

    //출력
    cout << count << "\n";

}