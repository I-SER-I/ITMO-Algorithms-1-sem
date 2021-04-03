#include <fstream>
using namespace std;

long long counter = 0;

void Merge(int* arr, int left, int mid, int right){
    int result[right - left];
    int it1 = 0, it2 = 0;
    while(left + it1 < mid && mid + it2 < right)
        if(arr[left + it1] <= arr[mid + it2]){
            result[it1 + it2] = arr[left + it1];
            counter += it2;
            it1++;
        }
        else{
            result[it1 + it2] = arr[mid + it2];
            it2++;
        }
    while(left + it1 < mid){
        result[it1 + it2] = arr[left + it1];
        counter += it2;
        it1++;
    }
    while(mid + it2 < right){
        result[it1 + it2] = arr[mid + it2];
        it2++;
    }
    for(int i = 0; i < it1 + it2; i++)
        arr[left + i] = result[i];
}

void MergeSort(int* arr, int n){
    for(int i = 1; i < n; i *= 2)
        for(int j = 0; j < n - i; j += 2 * i)
            Merge(arr, j, j + i, min(j + 2 * i, n));
}

int main()
{
    ifstream fin("inversions.in");
    ofstream fout("inversions.out");

    int n;
    fin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
        fin >> arr[i];
    MergeSort(arr, n);
    fout << counter;
}
