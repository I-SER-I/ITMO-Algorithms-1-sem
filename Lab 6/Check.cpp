#include <fstream>
using namespace std;
int n;
int tree[200228][3];
bool check = true;

int TreeSearch(int prev, int min, int max) {
    if(tree[prev][0] <= min || tree[prev][0] >= max){
        check = false;
        return 0;
    }
    if(tree[prev][1] != 0)
        TreeSearch(tree[prev][1], min, tree[prev][0]);
    if(tree[prev][2] != 0)
        TreeSearch(tree[prev][2], tree[prev][0], max);
}

int main(){
    ifstream fin("check.in");
    ofstream fout("check.out");
    fin >> n;
    if (!n){
        fout << "YES\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
        fin >> tree[i + 1][0] >> tree[i + 1][1] >> tree[i + 1][2];
    TreeSearch(1, -1000000001, 1000000001);
    if (check)
        fout << "YES\n";
    else
        fout << "NO\n";
    return 0;
}
