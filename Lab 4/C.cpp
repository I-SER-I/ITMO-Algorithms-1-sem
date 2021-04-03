#include <fstream>
#include <string>
using namespace std;
 
int main() 
{     
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    string s;
    int last, l, f;
    char* stack = new char[10000];
    f = 0;
    for (int i = 0; i < 10000; i++)
        stack[i] = 0;
    while (fin >> s)
    {
        if (f > 0)
            fout << endl;
        last = 0;
        l = s.length();
        for (int i = 0; i < l; i++) 
	{
            if (last > 0 && (s[i] == ')' && stack[last - 1] == '(' || s[i] == ']' && stack[last - 1] == '[')) 
	    {
                last--;
            }
            else 
            {
                stack[last] = s[i];
                last++;
            }
        }
        if (last == 0)
            fout << "YES";
        else
            fout << "NO";
        f++;
    }
    return 0;
}