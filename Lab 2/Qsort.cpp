#include <fstream>
#include <random>
#include <time.h>

using namespace std;

void QSort(int* arr, int left, int right){
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int key = arr[left + rand() % (right - left )];
    while(i <= j){
        while(arr[i] < key)
            i++;
        while(arr[j] > key)
            j--;
        if(i >= j)
            break;
        swap(arr[i++], arr[j--]);
    }
    QSort(arr, left, j);
    QSort(arr, j + 1, right);
}


int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
        fin >> arr[i];

    srand(time(NULL));
    QSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        fout << arr[i] << " ";
    return 0;
}
