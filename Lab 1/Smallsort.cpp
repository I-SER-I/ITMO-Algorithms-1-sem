#include <fstream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");
    fin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) 
	    {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";
    fin.close();
    fout.close();
    return 0;
}