#include <iostream>
#include <vector>
using namespace std;

int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받자
    int N;
    cin>>N;
    vector<int> P(N,0);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    //삽입정렬로 정렬해보자
    for(int i  = 0; i < N; i++){

        int ins_pos = i;
        int ins_val = P[i];
        for(int j = 0; j < i; j++){
            
            if(P[i] < P[j]){

                ins_pos = j;
                break;
            }
        }
        P.erase(P.begin() + i);
        P.insert(P.begin() + ins_pos, ins_val);
    }

    //정렬된 것에서 합 구하기
    int sum = 0;
    for(int i = 0; i < N; i++){

        sum += P[i] * (N-i);
    }
    cout << sum << "\n";
    return 0;
    
}