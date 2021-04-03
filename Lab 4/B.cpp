#include <fstream>
using namespace std;
 
int main() 
{     
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    int size, last, first;
    fin >> size;
    int* queue = new int[size];
    last = 0;
    first = 0;
    char command;
    for (int i = 0; i < size; i++) 
    {
        fin >> command; 
        if (command == '+') 
	{
            fin >> queue[last];
            last++;
        } 
        if (command == '-') 
	{
            fout << queue[first] << endl;
            first++;
        }
    }
    return 0;
}