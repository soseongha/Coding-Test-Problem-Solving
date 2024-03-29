#include <iostream>
#include <algorithm>
using namespace std;

int main(void){

    //N, M 입력 받기
    int N, M;
    cin >> N >> M;

    //N개의 재료들 입력 받기
    int materials[N];
    for(int i = 0; i < N; i++){
        
        cin >> materials[i];
    }

    //재료들 정렬하기
    sort(materials, materials + N);

    //1 2 3 4 5 7

    //투포인터를 사용해서 카운팅하기
    //sum > M이면 end--
    //sum < M이면 start++
    //sum == M이면 count++, end--;
    //start와 end가 엇갈리면 그만
    int *start = &materials[0];
    int *end = &materials[N-1]; //주소는 이렇게 할당해야해 
    int count = 0;
    while(start < end){

        if(*start + *end > M){
            end--;
        }
        else if(*start + *end < M){
            start++;
        }
        else{
            count++;
            end--;
        }
    }

    //출력
    cout << count << "\n";

}