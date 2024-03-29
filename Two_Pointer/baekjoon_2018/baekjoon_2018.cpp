#include <iostream>
#include <vector>
using namespace std;

int main(void){

    //시간절약용
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    //N 입력받기(int 범위임)
    int N;
    cin >> N;

    //두 개의 포인터 선언, 구간합 선언
    int start = 1, end = 1;
    int sum = 1; //long 고려해봐
    int count = 0;

    //맨 앞 두개의 수에서 시작
    //합이 N보다 작으면 오른쪽 포인터를 오른쪽으로 이동
    //합이 N보다 크면 왼쪽 포인터를 오른쪽으로 이동
    //합이 N과 같으면 카운트 +1 하고 오른쪽 포인터를 오른쪽으로 이동
    //start = end = N이 되면 끝
    while(end != N){ //!!!여기서 start > end가 되더라도 다시 end가 따라가므로 이렇게 조건 다는게 맞다

        if(sum < N){
            end++;
            sum += end;
        }
        else if(sum > N){
            start++;
            sum -= start-1;
        }
        else{
            count++;
            end++;
            sum += end;
        }
    }

    //자기 자신 카운트
    count++;

    cout << count << "\n";


}