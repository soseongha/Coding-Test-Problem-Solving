#include <iostream>
#include <vector>
using namespace std;
void merge_sort(int start, int end, vector<int> &A);
void merge(int s1, int e1, int s2, int e2, vector<int> &A);

int main(void){

    //시간단축용
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

    //머지소트하기
    merge_sort(0, N-1, A);

    //출력하기
    for(int i = 0; i < N; i++){
        
        cout << A[i] <<"\n";
    }
    return 0;
}


//sets = 부분합의 개수
void merge_sort(int start, int end, vector<int> &A){


    //종결조건
    if(start >= end) return;
    
    //divide
    int mod = 0;
    mod = (start +end) / 2;
    merge_sort(start, mod, A);
    merge_sort(mod + 1, end, A);

    //conquer
    merge(start, mod, mod + 1, end, A);

}

void merge(int s1, int e1, int s2, int e2, vector<int> &A){
    

    vector<int> temp;
    int ptr1 = s1;
    int ptr2 = s2;

    //투포인터로 set 두 개를 다님
    //set1과 set2의 원소를 비교해서 더 작은걸 넣음
    while( ptr1 <= e1 && ptr2 <= e2 ){

        if( A[ptr1] < A[ptr2] ){
            temp.push_back(A[ptr1]);
            ptr1++;
        }else{
            temp.push_back(A[ptr2]);
            ptr2++;
        }
    }

    //둘 중 하나가 먼저 끝에 도달했다면, 다른 하나에 남은 원소 push하기
    while( ptr1 <= e1 ){
        
        temp.push_back(A[ptr1]);
        ptr1++;
    }
     while( ptr2 <= e2 ){
        
        temp.push_back(A[ptr2]);
        ptr2++;
    }

    //temp를 A에 덮어씌우기
    int j = 0;
    for(int i = s1; i <= e2; i++){

        A[i] = temp[j];
        j++;
    }
    return;
}