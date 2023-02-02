#include <iostream>
#include <vector>
using namespace std;

int main(void){

    //시간절약용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N을 입력받아 int로 저장(10,000,000이하 자연수)
    int N;
    int count = 1; //N 자체만으로 이미 하나의 경우의 수
    cin >> N;
    
    //1~N이 담긴 배열 생성 -> 없어도 될듯
    //sum = 0 초기화하고, 포인터 두 개 만듬
    int sum = 0;
    int start = 0, end = 0;

    //배열에서 투 포인터를 이용해 구함
    //while문 end가 N이 될 때까지 돌림
    //sum == N이면 end 한칸증가하고 sum 더함, 카운트 셈
    //sum > N이면 start 한칸증가하고 sum 뺌
    //sum < N이면 end 한칸증가하고 sum 더함
    while(end != N){

        if(sum == N){

            end++;
            sum += end;
            count++;

        }else if(sum > N){

            sum -= start;
            start++;
            
        }else{

            end++;
            sum += end;

        }
    }
    //count 출력
    cout << count <<"\n";


}