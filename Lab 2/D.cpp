#include <fstream>
using namespace std;
 
int main()
{
    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");
 
    int n;
    fin >> n;
    int arr[n];
 
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
 
    for(int i = 0; i < n; i++)
        swap(arr[i], arr[i / 2]);
 
    for(int i = 0; i < n; i++)
        fout << arr[i] << " ";
    fin.close();
    fout.close();
}