#include <fstream>
#include <vector>
using namespace std;
 
ifstream fin("multimap.in");
ofstream fout("multimap.out");
 
class Map {
    static const long long m = 317;
    long long size = 0;
    struct MapList {
        MapList* prev = NULL;
        string value;
        MapList* next = NULL;
    };
    vector<MapList*> set;
    static long long GetHash(string& val) {
        const int p = 31;
        long long hash = 0, p_pow = 1;
        for (char i : val) {
            hash += (i - 'a' + 1) * p_pow;
            p_pow *= p;
        }
        if (hash >= 0)
            return hash % m;
        else
            return (m - abs(hash) % m) % m;
    }
public:
    Map() {
        size = 0;
        set = vector<MapList*>(m);
    }
    MapList* CreateNode(string key) {
        auto node = new MapList;
        node->prev = NULL;
        node->value = key;
        node->next = NULL;
        return node;
    }
    MapList* AddNode(MapList* tail, string key) {
        MapList* node = CreateNode(key);
        node->prev = tail;
        tail->next = node;
        node->value = key;
        return node;
    }
    void add(string x) {
        long long h = GetHash(x);
        MapList* head = set[GetHash(x)];
        if (head == NULL) {
            set[GetHash(x)] = CreateNode(x);
            size++;
        }
        else {
            MapList* pointer = set[GetHash(x)];
            while (pointer->next != NULL) {
                if (pointer->value == x)
                    return;
                pointer = pointer->next;
            }
            if (pointer->value != x) {
                AddNode(pointer, x);
                size++;
            }
        }
    }
 
    void remove(string x) {
        MapList* pointer = set[GetHash(x)];
        if (pointer == NULL)
            return;
        if (pointer->value == x) {
            set[GetHash(x)] = pointer->next;
            size--;
            free(pointer);
            return;
        }
        while (pointer != NULL) {
            if (pointer->value == x)
            {
                if (pointer->prev != NULL)
                    pointer->prev->next = pointer->next;
                if (pointer->next != NULL)
                    pointer->next->prev = pointer->prev;
                size--;
                free(pointer);
                return;
            }
            pointer = pointer->next;
        }
 
    }
    void print() {
        fout << size << " ";
        for (long long i = 0; i < m; ++i)
        {
            if (set[i] != NULL)
            {
                MapList* pointer = set[i];
                while (pointer != NULL)
                {
                    fout << pointer->value << " ";
                    pointer = pointer->next;
                }
            }
        }
        fout << "\n";
    }
};
 
struct MapNode {
    MapNode* prev = NULL;
    string key;
    Map values;
    MapNode* next = NULL;
};
 
MapNode* MapCreateNode(string& key, string& value) {
    auto node = new MapNode;
    node->prev = NULL;
    node->key = key;
    node->values = Map();
    node->values.add(value);
    node->next = NULL;
    return node;
}
 
MapNode* MapAddNode(MapNode* tail, string& key, string& value) {
    MapNode* node = MapCreateNode(key, value);
    node->prev = tail;
    tail->next = node;
    return node;
}
 
long long GetHash(string& x) {
    const int p = 31;
    long long hash = 0, p_pow = 1;
    for (char i : x) {
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    long long m = 1000003;
    if (hash >= 0)
        return hash % m;
    else
        return (m - abs(hash) % m) % m;
 
}
 
void Put(string& key, string& value, vector<MapNode*>& set) {
    MapNode* head = set[GetHash(key)];
    if (head == NULL)
        set[GetHash(key)] = MapCreateNode(key, value);
    else {
        MapNode* pointer = set[GetHash(key)];
        while (pointer->next != NULL) {
            if (pointer->key == key) {
                pointer->values.add(value);
                return;
            }
            pointer = pointer->next;
        }
        if (pointer->key != key)
            MapAddNode(pointer, key, value);
        else
            pointer->values.add(value);
    }
}
 
void Delete(string key, string value, vector<MapNode*>& set) {
    MapNode* pointer = set[GetHash(key)];
    while (pointer != NULL) {
        if (pointer->key == key) {
            pointer->values.remove(value);
            return;
        }
        pointer = pointer->next;
    }
}
 
void DeleteAll(string key, vector<MapNode*>& set) {
    MapNode* pointer = set[GetHash(key)];
    if (pointer == NULL)
        return;
    if (pointer->key == key) {
        set[GetHash(key)] = pointer->next;
        free(pointer);
        return;
    }
    while (pointer != NULL) {
        if (pointer->key == key) {
            if (pointer->prev != NULL)
                pointer->prev->next = pointer->next;
            if (pointer->next != NULL)
                pointer->next->prev = pointer->prev;
            free(pointer);
            return;
        }
        pointer = pointer->next;
    }
 
}
 
bool Get(string& key, vector<MapNode*>& set) {
    MapNode* pointer = set[GetHash(key)];
    while (pointer != NULL) {
        if (pointer->key == key) {
            pointer->values.print();
            return true;
        }
        pointer = pointer->next;
    }
    fout << "0\n";
    return false;
}
 
 
int main() {
    vector<MapNode*> set = vector<MapNode*>(1000003);
    string command;
    string key, value;
    while (fin >> command) {
        fin >> key;
        if (command == "put") {
            fin >> value;
            Put(key, value, set);
        }
        else if (command == "delete") {
            fin >> value;
            Delete(key, value, set);
        }
        else if (command == "deleteall")
            DeleteAll(key, set);
        else if (command == "get")
            Get(key, set);
    }
    return 0;
}