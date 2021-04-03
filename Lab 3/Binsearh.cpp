#include <fstream>
using namespace std;
 
int leftSearch(int *A , int key , int n){
    int left = -1 , right = n , middle;
    while(left < right - 1){
        middle = (left + right) / 2;
        if(A[middle] < key)
            left = middle;
        else
            right = middle;
    }
    if(right == n)
        return -2;
    if(A[right] == key)
        return right;
    else
        return -2;
}
 
int rightSearch(int *A , int key , int n){
    int left = -1 , right = n , middle;
    while(left < right - 1){
        middle = (left + right) >> 1;
        if(A[middle] <= key)
            left = middle;
        else
            right = middle;
    }
    if(left == -1)
        return -2;
    if(A[left] == key)
        return left;
    else
        return -2;
}
 
int main(){
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");
    int n;
    fin >> n;
    int *A = new int[n];
    for(int i = 0 ; i < n ; i++)
        fin >> A[i];
    int m;
    fin >> m;
    int x, result;
    for(int i = 0; i < m; i++){
        fin >> x;
        fout << leftSearch(A , x , n) + 1 << " " << rightSearch(A , x , n) + 1 << endl;
    }
    return 0;
}