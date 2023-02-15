#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    //시간단축
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //N개의 수 입력받기
    int N;
    cin >> N;
    vector<pair<int,int>> arr(N); //first = value, secode = index;

    for(int i = 0; i < N; i++){

        cin >> arr[i].first;
        arr[i].second = i;
    }

    //N개의 수 정렬하기(O(nlongn))
    sort(arr.begin(), arr.end());//first 오름차순, secode 오름차순으로 알아서 sort됨

    //정렬된 N개의 수 출력
    int max = 0;
    for(int i = 0; i < N; i++){

        if(arr[i].second - i + 1 > max){
            max = arr[i].second - i + 1;
        }
    }

    //max = 요소 중에서 가장 많이 왼쪽으로 이동한 요소의 이동 칸수 + 1
    cout << max << "\n";
    return 0;

}