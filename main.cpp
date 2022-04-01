#include <iostream>
#include <sys/time.h>
using namespace std;
const int maxN = 6000;
float Data[maxN][maxN];
struct timeval start,ending;
int n = 0;
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Data[i][j]=float (i+1) + float (j+1)*1.3;
        }
    }
}
void GaussElimi(){
    for (int k = 0; k < n; ++k) {
        for (int j = k+1; j < n; ++j) {
            Data[k][j]=Data[k][j]/Data[k][k];
        }
        Data[k][k]=1.0;
        for (int i = k+1; i < n; ++i) {
            for (int j = k+1; j < n; ++j) {
                Data[i][j]=Data[i][j]-Data[i][k]*Data[k][j];
            }
            Data[i][k]=0.0;
        }
    }
}
int main() {
    init();
    int step=10;
    int count=0;
    for (int i = 10; i <= 1000; i+=step) {
        n=i;
        gettimeofday(&start,NULL);
        gettimeofday(&ending,NULL);
        count=0;
        while(float (ending.tv_sec-start.tv_sec)<5){
            GaussElimi();
            gettimeofday(&ending,NULL);
            count++;
        }
        float x=float(ending.tv_sec-start.tv_sec);
        cout<<i<<","<<count<<','<<float(ending.tv_sec-start.tv_sec)<<","<<x/float(count)<<endl;
        if (n==100)
            step=100;
    }
    return 0;
}
