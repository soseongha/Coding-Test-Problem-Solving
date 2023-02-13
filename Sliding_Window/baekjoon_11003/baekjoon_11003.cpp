#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sub;
vector<int> sub_index;
void add(int, int);
void pop(int, int);

int main(void){

    //시간단축용
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    //N개의 수, 범위 L
    int N, L;
    cin >> N >> L;

    //N개의 수 A들
    vector<int> A(N,0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < L; i++){//처음에는 범위만큼 add만 함
        add(A[i], i);
        cout << sub[0] << " ";
        
    }

    for(int i = L; i < N; i++){//그 다음에는 하나 add, 하나 pop
        add(A[i], i);
        pop(A[i-L], i-L);
        cout << sub[0] << " ";
        
    }
    
}


//한 요소를 넣으면 서브배열에 요소를 넣어서 정렬하는 함수
void add(int value, int index){

    sub.insert(sub.begin(), value);//새 요소를 맨 앞에 insert
    sub_index.insert(sub_index.begin(), index);
        
    for(int i = 0; i < sub.size() - 1; i++){
        if(sub[i] > sub[i+1]){//하나씩 비교하다가 앞에거가 크면 swap
            
            int temp = sub[i];
            sub[i] = sub[i+1];
            sub[i+1] = temp;
            
            temp = sub_index[i];
            sub_index[i] = sub_index[i+1];
            sub_index[i+1] = temp; 
        }
    }

    return;
}

//한 요소를 빼면 서브배열에 요소를 빼는 함수
void pop(int value, int index){

    for(int i = 0; i < sub.size(); i++){//sub_index 배열에서 index 값과 값이 일치하는 것을 찾아서
        if(sub_index[i] == index){ //그 값을 pop함
            sub.erase(sub.begin() + i);
            sub_index.erase(sub_index.begin() + i);
        }    

    }

    return;
}