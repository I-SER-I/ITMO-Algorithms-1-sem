#include <vector>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
 
int main() 
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    vector<vector<pair<string, string>>> Hesh;
    Hesh.resize(1009);
    string command, key, value;
    int a, number, index;
    bool t;
    while (fin >> command) 
    {
        fin >> key;
        number = 0; 
        for (int i = key.length() - 1; i >= 0; i--)
            number += ((int)(key[i])) * i;
        a = number % 1009;
        t = false;
        for (int i = 0; i < Hesh[a].size(); i++) 
	{
            if (Hesh[a][i].first == key) 
	    {
                t = true;
                index = i;
                break;
            }
        }
        if (command == "put") 
	{
            fin >> value;
            if (t)
                Hesh[a][index].second = value;
            else
                Hesh[a].push_back(make_pair(key, value));
        }
        if (command == "get") 
	{
            if (t)
                fout << Hesh[a][index].second << endl;
            else
                fout << "none\n";
        }
        if (command == "delete" && t)
            Hesh[a].erase(Hesh[a].begin() + index);
    }
    return 0;
}