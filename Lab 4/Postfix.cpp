#include <fstream>
#include <string>
using namespace std;
 
int main() 
{     
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    char command;
    int last;
    int *stack = new int[100];
    for (int i = 0; i < 100; i++)
        stack[i] = 0;
    last = 0;
    while (fin >> command)
    {
        if (command == '+') 
	{
            last--;
            stack[last - 1] = stack[last - 1] + stack[last];
        } 
	else if (command == '-') 
	{
            last--;
            stack[last - 1] = stack[last - 1] - stack[last];
        } 
	else if (command == '*') 
	{
            last--;
            stack[last - 1] = stack[last - 1] * stack[last];
        } 
	else if (command == '/') 
	{
            last--;
            stack[last - 1] = stack[last - 1] / stack[last];
        }
	else if (command != ' ')
	{
            stack[last] = command - '0';
            last++;
        }
    }
    fout << stack[0];
    return 0;
}