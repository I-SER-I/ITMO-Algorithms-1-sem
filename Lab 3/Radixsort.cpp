#include <fstream>
using namespace std;
int n , m;

char Digit(string str , int i){
    return str[i];
}

void RadixSort(string *A , int k){
    int C[m];
    string B[n];
    for(int i = 0 ; i < m; i++)
        C[i] = 0;
    for(int i = 0 ; i < n; i++)
        C[Digit(A[i] , k) - 'a']++;
    for(int i = 1 ; i < m; i++)
        C[i] += C[i - 1];
    for(int i = n - 1; i >= 0; i--)
    {
        B[C[Digit(A[i], k) - 'a'] - 1] = A[i];
        C[Digit(A[i], k) - 'a']--;
    }
    for(int i = 0; i < n; i++)
        A[i] = B[i];
}

int main(){
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    int k;
    fin >> n >> m >> k;
    string result[n];
    for(int i = 0; i < n; i++)
        fin >> result[i];
    for(int i = m - 1; i > m - 1 - k; i--)
        RadixSort(result, i);
    for(int i = 0; i < n; i++)
        fout << result[i] << endl;
    fin.close();
    fout.close();
    return 0;
}
