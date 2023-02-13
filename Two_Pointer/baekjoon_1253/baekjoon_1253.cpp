#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    //1부터 2000까지의 정수 N 받고, int형 N개의 정수를 다음 줄에 받음
    int N;
    cin >> N;
    vector<int> nums(N,0);
    for(int i = 0; i < N; i++){

        cin >> nums[i];
    }

    //오름차순으로 정렬
    sort(nums.begin(), nums.end());

    //좋은 수 = 다른 두 수의 합인 수
    int count = 0;
    int val = 0;
    for(int k = 0; k < N; k++){

        int i = 0;
        int j = N-1;

        while(i < j){ 

            if(nums[i] + nums[j] == nums[k]){
                if(i != k && j != k){
                    count++;
                    break;
                }//만약 i, j가 k랑 겹치면 걔는 제외얌
                else if(i == k){
                    i++;//i랑 겹쳤으면 안겹치게 i를 조정해 
                }
                else if(j == k){
                    j--;//j랑 겹쳤으면 안겹치게 j를 조정해  
                }
            }
            else if(nums[i] + nums[j] < nums[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }


    //출력
    cout<<count<<"\n";

}