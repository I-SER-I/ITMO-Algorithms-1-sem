#include <fstream>
using namespace std;

void Merge(string* country, string* name, int left , int mid , int right){
    string country_result[right - left], name_result[right - left];
    int it1 = 0, it2 = 0;
    while(left + it1 < mid && mid + it2 < right){
        if(country[left + it1].compare(country[mid + it2]) > 0){
            country_result[it1 + it2] = country[left + it1];
            name_result[it1 + it2] = name[left + it1];
            it1++;
        }
        else{
            country_result[it1 + it2] = country[mid + it2];
            name_result[it1 + it2] = name[mid + it2];
            it2++;
        }
    }
    while(left + it1 < mid){
        country_result[it1 + it2] = country[left + it1];
        name_result[it1 + it2] = name[left + it1];
        it1++;
    }
    while(mid + it2 < right){
        country_result[it1 + it2] = country[mid + it2];
        name_result[it1 + it2] = name[mid + it2];
        it2++;
    }
    for(int i = 0; i < it1 + it2; i++){
        country[left + i] = country_result[i];
        name[left + i] = name_result[i];
    }
}

void MergeSort(string *country, string *name, int n){
    for(int i = 1; i < n; i *= 2)
        for(int j = 0; j < n - i; j += 2 * i)
            Merge(country , name , j , j + i , min(j + 2 * i , n));
}

int main()
{
    ifstream fin("race.in");
    ofstream fout("race.out");

    int n;
    fin >> n;
    string* country = new string[n];
    string* name = new string[n];

    for(int i = 0; i < n; i++)
        fin >> country[i] >> name[i];

    MergeSort(country, name, n);

    for(int i = n - 1; i > -1; i--){
        if(country[i] != country[i + 1])
            fout << "=== " << country[i] << " ===" << endl;
        fout << name[i] << endl;
    }
    return 0;
}
