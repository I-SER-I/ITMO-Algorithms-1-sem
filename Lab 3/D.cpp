#include <fstream>
using namespace std;
 
void SiftDown(int* arr, int i , int n){
    while(2 * i + 1 < n){
        int leftson = 2 * i + 1;
        int rightson = 2 * i + 2;
        int j = leftson;
        if(rightson < n && arr[rightson] < arr[leftson])
            j = rightson;
        if(arr[i] <= arr[j])
            break;
        swap(arr[i], arr[j]);
        i = j;
    }
}
 
void BuildHeap(int* arr, int n){
    for(int i = n / 2; i >= 0; i--)
        SiftDown(arr, i, n);
}
 
void HeapSort(int* arr, int n){
    BuildHeap(arr, n);
    int heapsize = n;
    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        SiftDown(arr, 0, i);
    }
}
 
int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    int* arr = new int[n];
 
    for(int i = 0; i < n; i++)
        fin >> arr[i];
 
    HeapSort(arr, n);
 
    for(int i = n - 1; i >= 0 ; i--)
        fout << arr[i] << " ";
}