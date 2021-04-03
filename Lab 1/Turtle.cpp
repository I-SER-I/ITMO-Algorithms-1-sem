#include <fstream>
#include <vector>
using namespace std;
 
int main()
{
    int width, height;
    ifstream fin("turtle.in");
    ofstream fout("turtle.out");
    fin >> height >> width;
    vector<int> matrix(width * height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            fin >> matrix[i * width + j];
    for (int i = height - 1; i >= 0; i--) 
        for (int j = 0; j < width; j++) 
	{
            int down = (i + 1 >= 0 && j >= 0 && i + 1 < height && j < width) ? matrix[(i + 1) * width + j] : 0;
            int left = (i >= 0 && j - 1 >= 0 && i < height && j - 1 < width) ? matrix[i * width + j - 1] : 0;
            matrix[i * width + j] = matrix[i * width + j] + ((down > left) ? down : left);
        }
    fout << matrix[width - 1];
    fin.close();
    fout.close();
    return 0;
}