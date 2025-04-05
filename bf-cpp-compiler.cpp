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

    int comma_count = 0;
     for (char ch : mes) {
        if (ch == ',') {
            comma_count++;
        }
    }

    queue<char> input_queue;
    if (comma_count > 0) {
        cout << "enter " << comma_count << " characters for input:\n";
        for (int i = 0; i < comma_count; ++i) {
            char input_char;
            cin >> input_char;
            input_queue.push(input_char);
        }
    }
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
            slots[pos].add();
            break;
        case '-':
            slots[pos].less();
            break;
        case '<':
            slots[pos].left();
            break;
        case '>':
            slots[pos].right();
            break;
        case '.':
            slots[pos].dot();
            break;
        case '[':
            if (slots[pos].get_var() == 0) {
                i = loop_pos[i];
            }
            break;
        case ']':
            if (slots[pos].get_var() != 0) {
                i = loop_pos[i];
            }
            break;
        case ',':
            slots[pos].input_use(input_queue);
            break;

        default:
            if (mes != "exit") {
                cout << "wrong symbol\n";
                break;
            }
        }  //cout << "pos: " << pos << endl;
    }

    cout << endl;

    return 0;
}
