#include <iomanip>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream fin("garland.in");
    ofstream fout("garland.out");
    int n;
    double A;
    fin >> n >> A;
    double left = 0, right = A, middle, previous, current, next, last = -1;
    bool aboveGround;
    while((right - left) > 0.01 / (n - 1)){
        middle = (left + right) / 2;
        previous = A;
        current = middle;
        aboveGround = current > 0;
        for(int i = 3 ; i <= n ; i++){
            next = 2 * current - previous + 2;
            aboveGround &= next > 0;
            previous = current;
            current = next;
        }
        if(aboveGround){
            right = middle;
            last = current;
        }
        else
            left = middle;
    }
    fout << setprecision(2) << fixed << last;
    return 0;
}