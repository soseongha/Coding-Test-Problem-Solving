#include <iostream>
using namespace std;

int main(void){

    //재료 개수 N int 입력받기
    int N;
    cin >> N;

    //갑옷 만들 때 필요한 수 M int 입력받기
    int M;
    cin >> M;

    //N개의 재료 배열 mat에 입력받기
    int A;
    int mat[15001] = {0};
    for(int i = 1; i <= N; i++){
        cin >> A;
        mat[i] = A; 
    }

    //mat[]를 정렬하기
    for(int i = 1; i < N; i++){
        for(int j = i + 1 ; j <= N ; j++){
            if(mat[i] > mat[j]){
                int temp = mat[j];
                mat[j] = mat[i];
                mat[i] = temp; 
            }
        }
    }
    
    //정렬된 mat[]에 투포인터로 접근하기
    int *start = &mat[1]; 
    int *end = &mat[N]; 
    int count = 0;


    while( *start < *end ){
        
        if(*start + *end < M){

            start++;

        }else if(*start + *end > M){
            
            end--;

        }else{
            
            count++;
            start++;
            end--; //여기서 포인터 둘 다 움직이면서, 포개질수도 안포개지고 엇갈릴수도 있음!!!
        }
    }

    //출력
    cout << count << "\n";
}