#include <fstream>
using namespace std;

void Kth(int* arr, int left, int right, int k){
    int i = left;
    int j = right;
    int key = arr[(right + left ) / 2];
    while(i <= j){
        while(arr[i] < key)
            i++;
        while(arr[j] > key)
            j--;
        if(i <= j)
            swap(arr[i++], arr[j--]);
    }
    if (j > left && k <= j)
        Kth(arr, left, j, k);
    if (i < right && k >= j)
        Kth(arr, j + 1, right, k);
}

int main()
{
    ifstream fin("kth.in");
    ofstream fout("kth.out");

    int n, k;
    int a, b, c;
    fin >> n >> k;
    int* arr = new int[n];
    if(n == 1)
        fin >> a >> b >> c >> arr[0];
    else
        fin >> a >> b >> c >> arr[0] >> arr[1];
    for(int i = 2 ; i < n ; i++)
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    Kth(arr, 0, n - 1, k - 1);
    fout << arr[k - 1];
    return 0;
}
