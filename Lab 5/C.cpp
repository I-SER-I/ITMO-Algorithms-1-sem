#include <fstream>
#include <vector>
 
using namespace std;
struct badlist {
    string key;
    string value;
    badlist *next = NULL;
    badlist *prev = NULL;
};
 
vector <vector<badlist>> mylinkedmap(100003);
 
int gethash(string val) {
    int summ = 0;
    for (int i = 0; i < val.length(); i++){
        summ += (53 * summ + val[i]);
        summ %= 100003;
    }
    return summ;
}
 
int main()
{
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string command;
    string key, value;
    badlist *prev = NULL;
    while (fin >> command){
        if (command == "put"){
            fin >> key >> value;
            int hashfun = gethash(key) % 100003;
            bool flag = false;
            for (int i = 0; i < mylinkedmap[hashfun].size(); i++) {
                if (mylinkedmap[hashfun][i].key == key) {
                    flag = true;
                    mylinkedmap[hashfun][i].value = value;
                }
            }
            if (flag == false) {
                if (mylinkedmap[hashfun].size() == 0)
                    mylinkedmap[hashfun].reserve(10);
                badlist x;
                x.key = key;
                x.value = value;
                x.next = NULL;
                x.prev = prev;
                mylinkedmap[hashfun].push_back(x);
                if(prev != NULL)
                    prev->next = &mylinkedmap[hashfun][mylinkedmap[hashfun].size() - 1];
                prev = &mylinkedmap[hashfun][mylinkedmap[hashfun].size() - 1];
 
            }
        }
        else if (command == "delete") {
            fin >> key;
            int hashfun = gethash(key) % 100003;
            for (int i = 0; i < mylinkedmap[hashfun].size(); i++){
                if (mylinkedmap[hashfun][i].key == key){
                    if (mylinkedmap[hashfun][i].next == NULL)
                        prev = mylinkedmap[hashfun][i].prev;
                    else
                        mylinkedmap[hashfun][i].next->prev = mylinkedmap[hashfun][i].prev;
                    if (mylinkedmap[hashfun][i].prev != NULL)
                        mylinkedmap[hashfun][i].prev->next = mylinkedmap[hashfun][i].next;
                    mylinkedmap[hashfun][i].value = "";
                    mylinkedmap[hashfun][i].next = NULL;
                    mylinkedmap[hashfun][i].prev = NULL;
                    mylinkedmap[hashfun][i].key = "";
                    break;
                }
            }
        }
        else if (command == "get") {
            fin >> key;
            int hashfun = gethash(key);
            bool flag = false;
            for (int i = 0; i < mylinkedmap[hashfun].size(); i++){
                if (mylinkedmap[hashfun][i].key == key){
                    fout << mylinkedmap[hashfun][i].value << "\n";
                    flag = true;
                }
            }
            if (!flag)
                fout << "none\n";
        }
        else if (command == "prev") {
            fin >> key;
            int hashfun = gethash(key) % 100003;
            bool flag = false;
            for (int i = 0; i < mylinkedmap[hashfun].size(); i++) {
                if (mylinkedmap[hashfun][i].key == key) {
                    if (mylinkedmap[hashfun][i].prev != NULL) {
                        fout << mylinkedmap[hashfun][i].prev->value << "\n";
                        flag = true;
                    }
                }
            }
            if (!flag)
                fout << "none\n";
        }
        else if (command == "next") {
            fin >> key;
            int hashfun = gethash(key) % 100003;
            bool flag = false;
            for (int i = 0; i < mylinkedmap[hashfun].size(); i++) {
                if (mylinkedmap[hashfun][i].key == key) {
                    if (mylinkedmap[hashfun][i].next != NULL) {
                        fout << mylinkedmap[hashfun][i].next->value << "\n";
                        flag = true;
                    }
                }
            }
            if (!flag)
                fout << "none\n";
        }
    }
    return 0;
}