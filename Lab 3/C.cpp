#include <fstream>
using namespace std;
 
int main(){
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
 
    long long n;
    fin >> n;
    long long* arr = new long long[n + 1];
    for(int i = 1; i <= n; i++)
        fin >> arr[i];
 
    for (int i = 1; i <= n; i++){
        if((i * 2 <= n && arr[i] > arr[i * 2]) || (i * 2 + 1 <= n) && (arr[i] > arr[i * 2 + 1])){
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
}