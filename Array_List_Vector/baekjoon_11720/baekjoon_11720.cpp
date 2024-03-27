#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    
    string numbers;
    cin >> numbers;

    int total = 0;

    for(int i = 0; i < N; i++){
        
        total += numbers[i] - '0';
        
    }
    cout << total << "\n";

}