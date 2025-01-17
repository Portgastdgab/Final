
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

void F1(int* ar, int n, int* s)
{
    for ( int i = 0; i < xn; i++ )
    {
        *s += ar[i];
    }
}

int main()
{
    int ar[16] = {2,6,3,1,7,8,9,6,4,3,2,8,9,11,13,1};
    int xsum[4] = {0,0,0,0};
    int sum = 0;
    
    int i = 0, nt = 4;
    
    vector<thread> ths(nt);
    for ( i = 0; i < nt; i++ )
        ths[i] = thread(F1, &ar[i*4], 4, &xsum[i]);

    for ( i = 0; i < nt; i++ )
        ths[i].join();
    
    
    for ( i = 0; i < nt; i++ )
        sum += xsum[i];
    
    cout<<"\n sum: "<<sum;

    getchar();
    return 0;
}

