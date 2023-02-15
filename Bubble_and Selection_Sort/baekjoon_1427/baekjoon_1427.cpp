#include <iostream>
using namespace std;

int main(void){

    
    //숫자 nums[]에 입력받기
    string str;
    int nums[11];
    cin >> str;
    
    int size = str.size();
    for(int i = 0; i < size; i++){

        nums[i] = str[i] - '0';
    }

    //선택 정렬로 정렬하기
    for(int i = 0; i < size-1; i++){

        //현재 범위에서 최솟값을 구함
        int max = -1;
        int max_index = -1;
        for(int j = i; j < size; j++){
            
            if(nums[j] > max){
                max = nums[j];
                max_index = j;
            }
        }
        
        //최솟값과 현재 인덱스 값을 swap
        int temp = nums[i];
        nums[i] = nums[max_index];
        nums[max_index] = temp;
    }

    //출력
    for(int i = 0; i < size; i++){

        cout << nums[i];
    }
    cout << "\n";
    return 0;

}