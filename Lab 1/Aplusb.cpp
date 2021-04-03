#include <fstream>
using namespace std;
 
int main()
{
    long long a, b;
    ifstream fin("aplusb.in");
    ofstream fout("aplusb.out");
    fin >> a >> b;
    fout << a + b << endl;
    fin.close();
    fout.close();
    return 0;
}