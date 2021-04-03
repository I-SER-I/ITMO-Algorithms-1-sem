#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int modulo = 65536;
vector <string> commands;
vector <int> registers(26);
vector <pair <string, int> > labels;
queue <int> quack;
int n = 0, l = 0;

int jump(string label) {
	for (int i = 0; i < l; i++)
		if (labels[i].first == label)
            return labels[i].second;
}

int main() {
	ifstream fin("quack.in");
	ofstream fout("quack.out");
	string com, label;
	int i, a, b, x;
	bool run = true;
	char reg;
	while (fin >> com) {
        commands.push_back(com);
        n++;
    }
	for (i = 0; i < n; i++)
		if (commands[i][0] == ':') {
			labels.push_back(make_pair(commands[i].substr(1), i));
			l++;
		}
    i = 0;
	while (i < n) {
		com = commands[i];
		switch (com[0]) {
            case '+':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a + b) & (modulo - 1);
                quack.push(x);
                break;
            case '-':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a - b) & (modulo - 1);
                quack.push(x);
                break;
            case '*':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a * b) & (modulo - 1);
                quack.push(x);
                break;
            case '/':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                if (!b)
                    x = 0;
                else
                    x = (a / b) & (modulo - 1);
                quack.push(x);
                break;
            case '%':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                if (!b)
                    x = 0;
                else
                    x = (a % b) & (modulo - 1);
                quack.push(x);
                break;
            case '>':
                reg = com[1];
                x = quack.front();
                quack.pop();
                registers[reg - 'a'] = x;
                break;
            case '<':
                reg = com[1];
                x = registers[reg - 'a'];
                quack.push(x);
                break;
            case 'P':
                if (com.length() == 1) {
                    x = quack.front();
                    quack.pop();
                }
                else {
                    reg = com[1];
                    x = registers[reg - 'a'];
                }
                fout << x << '\n';
                break;
            case 'C':
                if (com.length() == 1) {
                    x = quack.front();
                    quack.pop();
                }
                else {
                    reg = com[1];
                    x = registers[reg - 'a'];
                }
                fout << char(x % 256);
                break;
            case ':':
                break;
            case 'J':
                label = commands[i].substr(1);
                i = jump(label);
                break;
            case 'Z':
                reg = com[1];
                label = commands[i].substr(2);
                if (!registers[reg - 'a'])
                    i = jump(label);
                break;
            case 'E':
                label = commands[i].substr(3);
                if (registers[com[1] - 'a'] == registers[com[2] - 'a'])
                    i = jump(label);
                break;
            case 'G':
                label = commands[i].substr(3);
                if (registers[com[1] - 'a'] > registers[com[2] - 'a'])
                    i = jump(label);
                break;
            case 'Q':
                run = false;
                break;
            default:
                x = atoi(com.c_str());
                quack.push(x);
                break;
		}
		i++;
		if (!run)
            break;
	}
	return 0;
}
