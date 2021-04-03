#include <vector>
#include <fstream>
using namespace std;
 
vector < pair<int , int> > que;
 
void SiftDown(int i){
    while (2 * i + 1 < que.size()){
        int leftson = 2 * i + 1;
        int rightson = 2 * i + 2;
        int j = leftson;
        if(rightson < que.size() && que[rightson].first < que[leftson].first)
            j = rightson;
        if(que[i].first <= que[j].first)
            break;
        swap(que[i], que[j]);
        i = j;
    }
}
 
void SiftUp(int i){
    while (i != 0 && que[i].first < que[(i - 1) / 2].first){
        swap(que[i], que[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
 
void Add(int val, int com_cou){
    que.push_back(make_pair(val, com_cou));
    SiftUp(que.size() - 1);
}
 
int ExtractMin(){
    int min = que[0].first;
    que[0] = que[que.size() - 1];
    que.pop_back();
    SiftDown(0);
    return min;
}
 
void Decrease(int ind, int val){
    for(int i = 0; i < que.size(); i++)
        if(que[i].second == ind){
            que[i].first = val;
            SiftUp(i);
            break;
        }
}
 
int main(){
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
    string command;
    int value, index, new_value;
    int command_counter = 1;
    while (fin >> command){
        if (command == "push"){
            fin >> value;
            Add(value, command_counter);
        }
        else if (command == "extract-min"){
            if (que.empty())
                fout << "*" << "\n";
            else
                fout << ExtractMin() << "\n";
        }
        else if (command == "decrease-key"){
            fin >> index >> new_value;
            Decrease(index, new_value);
        }
        command_counter++;
    }
}