#include <fstream>
using namespace std;
 
int main()
{     
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    int size, last;
    fin >> size;
    int* stack = new int[size];
    last = 0;
    char command;
    for (int i = 0; i < size; i++) 
    {     
        fin >> command;    
        if (command == '+') 
	{
            fin >> stack[last];
            last++;
        } 
        if (command == '-') 
	{
            last--;
            fout << stack[last] << endl;
        }
    }
    return 0;
}