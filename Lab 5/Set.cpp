#include <vector>
#include <fstream>
#include <string>
using namespace std;
 
int main() 
{ 
    ifstream fin("set.in");
    ofstream fout("set.out");
    vector<vector<int>> Hesh(1001);
    string command;
    int number, a, index;
    bool t;
    while (fin >> command) 
    {
        fin >> number;
        a = number % 1001;
        if (a < 0)
            a = -a;
        t = false;
        for (int i = 0; i < Hesh[a].size(); i++) 
	{
            if (Hesh[a][i] == number) 
	    {
                t = true;
                index = i;
                break;
            }
        }
        if (t && command == "delete")
            Hesh[a].erase(Hesh[a].begin() + index);
        if (!t && command == "insert")
            Hesh[a].push_back(number);
        if (command == "exists") 
	{
            if (t)
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
    }
    return 0;
}