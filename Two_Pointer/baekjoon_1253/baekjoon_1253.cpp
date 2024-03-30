#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 불합격!!
int main(void)
{
    //N과 N개의 수 입력 받기
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    //정렬하기
    sort(A, A+N);

    //가장 큰 수부터 보자
    //투 포인터로 양끝에서 가면서 찾자
    int count = 0;
    for(int i = 0; i < N; i++){ //i = 2부터가 아니다! 양수만이 아닌 음수도 가능하기 때문

        int start = 0;
        int end = N-1;
        long target = A[i];
        
        while(start < end){
            
            if(A[start] + A[end] > target){
                
                end--;
            }
            else if(A[start] + A[end] < target){

                start++;

            }
            else{

                if(start == i){
                    start++;
                }
                else if(end == i){
                    end--;
                }else{
                    count++;
                    break;//찾으면 즉시 끝내고 다음 수를 보자
                }
            }
        }
    }

    //출력하기
    cout << count << "\n";

}