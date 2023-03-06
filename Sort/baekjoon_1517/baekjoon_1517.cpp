#include <iostream>
#include <vector>
using namespace std;
void merge_sort(int start, int end, vector<int> &A);
void merge_and_cnt(int start, int end, vector<int> &A);

//전역변수 정의
long long swap_cnt = 0;

int main(void){

    //시간 단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    int N;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++){

        cin >> A[i];
    }

    //머지소트 하면서, merge 할 때마다 swap된 수를 총합
    merge_sort(0, N, A);

    //출력
    cout << swap_cnt << "\n";

}

void merge_sort(int start, int end, vector<int> &A){

    //종결조건이라면 끝내고
    if( start >= end ) return;

    //아니라면 divide
    int mid = (start + end) / 2;
    merge_sort(start, mid, A);
    merge_sort(mid + 1, end, A);

    //conquer
    merge_and_cnt(start, end, A);
    return;
}

void merge_and_cnt(int start, int end, vector<int> &A){


    //기존 배열과 새 배열을 pair로 생성하기
    int arr_size = end-start+1;
    vector<pair<int,int>> origArr(arr_size, {0,0});
    for(int i = 0; i < arr_size; i++){
        origArr[i].first = A[start+i];
        origArr[i].second = i;
    }
    vector<pair<int,int>> newArr;

    //투 포인터 생성하기
    int mid = (start + end) / 2 - start; 
    int ptr1 = 0;
    int ptr2 = mid + 1; 

    //투 포인터로, 기존 2개 배열 이동하면서 작은 것부터 담기
    while(ptr1 <= mid && ptr2 <= end){

        if(A[ptr1] > A[ptr2]){
            newArr.push_back(origArr[ptr2]);
            ptr2++;
        }else{
            newArr.push_back(origArr[ptr1]);
            ptr1++;
        }
    }

    //하나 다 담았다면 남은 배열에 있는 것도 새 배열에 몽땅 담기
    while(ptr1 <= mid){
        newArr.push_back(origArr[ptr1]);
        ptr1++;
    }
    while(ptr2 <= end){
        newArr.push_back(origArr[ptr2]);
        ptr2++;
    }

    //새 배열과 기존 배열 간의 이동 차이 계산하기
    for(int i = 0; i < arr_size; i++){
        
        if(origArr[i].second - newArr[i].second > 0){
            swap_cnt += origArr[i].second - newArr[i].second;
        }
    }

    //새 배열을 기존 배열에 덮어쓰기
    for(int i = 0; i < arr_size; i++){
        
        A[start+i] = newArr[i].first;
    }
    return;

}