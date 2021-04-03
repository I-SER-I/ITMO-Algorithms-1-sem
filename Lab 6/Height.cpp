#include <fstream>
using namespace std;
int height, n;
int tree[200003][3];

-
void TreeSearch (int prev, int hei){
    if (height < hei)
        height = hei;
    if (tree[prev][1] > 0)
        TreeSearch(tree[prev][1], hei + 1);
    if (tree[prev][2] > 0)
        TreeSearch(tree[prev][2], hei + 1);
}

int main() {
	ifstream fin("height.in");
	ofstream fout("height.out");
    fin >> n;
    height = 0;
    if (n == 0) {
        fout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
        fin >> tree[i + 1][0] >> tree[i + 1][1] >> tree[i + 1][2];
    TreeSearch(1, 1);
    fout << height << "\n";
    return 0;
}
