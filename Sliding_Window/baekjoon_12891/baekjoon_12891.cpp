#include <iostream>
#include <string>
using namespace std;

int main(void){

    //문자열의 길이 S, 부분문자열의 길이 P, 전체 DNA 문자열 fullDNA
    int S, P;
    cin >> S >> P;
    string fullDNA;
    string subDNA;
    cin >> fullDNA;
    
    //각 문자의 개수 A,C,G,T
    int A,C,G,T;
    cin >> A;
    cin >> C;
    cin >> G;
    cin >> T;

    //문자열 str 내에서 P개씩 잘라서 이동하되, 그게 문자 개수 조건 맞는지 확인하기
    int count = 0;
    int sA=0,sC=0,sG=0,sT=0;//subDNA 속 문자의 개수

    for(int i = 0; i < S-P+1; i++){
        
        //부분문자열에서 문자 개수를 카운팅
        if(i == 0){//첫번째 슬라이딩 때는 부분문자열에서 수동으로 문자 개수를 셈
            subDNA = fullDNA.substr(i,P);//index i부터 P개의 문자까지의 문자열 반환

            for(int j = 0; j < P; j++){
                if(subDNA[j] == 'A'){
                    sA++;
                }else if(subDNA[j] == 'C'){
                    sC++;
                }else if(subDNA[j] == 'G'){
                    sG++;
                }else if(subDNA[j] == 'T'){
                    sT++;
                }
            }

        }else{//두번째부터는 새로 생긴 문자 카운트하고, 없어진 문자 카운트 삭제
            int subDNALast = i+P-1;
            if(fullDNA[subDNALast] == 'A'){
                sA++;
            }else if(fullDNA[subDNALast] == 'C'){
                sC++;
            }else if(fullDNA[subDNALast] == 'G'){
                sG++;
            }else if(fullDNA[subDNALast] == 'T'){
                sT++;
            }

            int subDNALost = i-1;
            if(fullDNA[subDNALost] == 'A'){
                sA--;
            }else if(fullDNA[subDNALost] == 'C'){
                sC--;
            }else if(fullDNA[subDNALost] == 'G'){
                sG--;
            }else if(fullDNA[subDNALost] == 'T'){
                sT--;
            }
        }

        //카운팅이 끝난 후에 조건과 확인
        if(A <= sA && C <= sC && G <= sG && T <= sT){
            count++;
        }
        
    }

    //출력
    cout<<count<<"\n";

}