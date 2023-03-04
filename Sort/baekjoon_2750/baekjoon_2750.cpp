#include <iostream>
#include <vector>
using namespace std;

int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N 입력받기
    int N;
    cin >> N;

    //N개의 수 입력받기
    vector<int> nums(N,0);
    for(int i = 0; i < N; i++){

        cin >> nums[i];
    }

    //N개의 수 버블정렬하기(2초인데 n<=1000이므로 시간 충분)
    for(int i = 0; i < N-1; i++){

        for(int j = 0; j < N-i-1; j++){

            if(nums[j] > nums[j+1]){
                
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    //정렬 결과 출력
    for(int i = 0; i < N; i++){

        cout << nums[i] << "\n";
    }

}