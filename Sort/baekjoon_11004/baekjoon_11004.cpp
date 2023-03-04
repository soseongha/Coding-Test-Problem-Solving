/*
 * 문제는 시간초과임, 그러나 퀵소트 연습용이라서! 
*/
#include <iostream>
#include <vector>
using namespace std;
void quick_sort(int, int, vector<int> &A, int);

int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    int N, K;
    cin >> N >> K;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    //퀵소트로 정렬해보자!
    quick_sort(0, N, A, K);

    //출력하자
    cout << A[K] << "\n";
    return 0 ;

}

void quick_sort(int start, int end, vector<int> &A, int K){

    //종결조건
    if(start >= end){

        return;
    }

    //pivot 설정하기
    int pivot = start;
    int left = start + 1;
    int right = end;

    //pivot의 자리 탐색하기
    while( left > right ){

        while( A[left] < A[pivot] ) left++;
        while( A[right] > A[pivot] ) right--;
        
        //만약 left right가 순서 바뀌지 않았다면, swap
        if( left < right ){

            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
        }
    }

    //pivot을 새 자리로 옮기기
    A.insert(A.begin() + right, A[pivot]);
    A.erase(A.begin());

    //조기 종결 조건
    if(right == K){
        return;
    }

    //다음 분할로 들어가기
    quick_sort(start, right - 1, A, K);
    quick_sort(right + 1, end, A, K);

}