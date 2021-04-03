#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("sortland.in");
    ofstream fout("sortland.out");
    int n;
    fin >> n;
    vector<pair<double, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i].first;
        arr[i].second = i + 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].first > arr[j + 1].first)
                swap(arr[j], arr[j + 1]);
    fout << arr[0].second << " " << arr[n / 2].second << " " << arr[n - 1].second;
    return 0;
}