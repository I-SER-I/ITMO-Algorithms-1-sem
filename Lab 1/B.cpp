#include <fstream>
using namespace std;
 
int main()
{
    long long a, b;
    ifstream fin("aplusbb.in");
    ofstream fout("aplusbb.out");
    fin >> a >> b;
    fout << a + b * b << endl;
    fin.close();
    fout.close();
    return 0;
}