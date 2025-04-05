#include <iostream>
#include <vector>
#include <string>
#include "class.h"
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
    vector <Slot> slots(30000, 0);
    string mes;
    getline(cin, mes);
    const string tmp_mes = mes;
    unordered_map<int, int> loop_pos;
    stack<int> temp;
    for (int i = 0; i < tmp_mes.size(); ++i) {
        if (tmp_mes[i] == '[') {
            temp.push(i);
        } else if (tmp_mes[i] == ']') {
            if (temp.empty()) {
                cout << "useless ], erase it, silly: " << i << "\n";
                return 1;
            }
            int loop_start = temp.top(); //indx of [
            temp.pop();
            loop_pos[loop_start] = i;
            loop_pos[i] = loop_start;
        }
    }

    if (!temp.empty()) {
        cout << "u forgot ]\n";
        return 1;
    }

    if (mes == "exit") { return 0; }
    for (int i = 0; i < mes.size(); ++i) {
        char ch = mes[i];
        switch (ch) {

        case '+':
            slots[pos].add(pos);
            break;
        case '-':
            slots[pos].less(pos);
            break;
        case '<':
            slots[pos].left();
            break;
        case '>':
            slots[pos].right();
            break;
        case '.':
            slots[pos].dot(pos);
            break;
        case '[':
            if (slots[pos].get_var(pos) == 0) {
                i = loop_pos[i];
            }
            break;
        case ']':
            if (slots[pos].get_var(pos) != 0) {
                i = loop_pos[i];
            }
            break;
        case ',':
            slots[pos].set_var(pos);
            break;

        default:
            if (mes != "exit") {
                cout << "wrong symbol\n";
                break;
            }
        }  //cout << "pos: " << pos << endl;
    }

    return 0;
}
