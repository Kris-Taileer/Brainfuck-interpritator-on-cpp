#include <iostream>
#include <vector>
#include <string>
#include "class.h"

using namespace std;

int main() {
    vector <Slot> slots(1000, 0);
    string mes;


    while (true) {
        getline(cin, mes);
        if (mes == "0") { break; }
        for (char ch : mes) {

            if (ch == '+') {
                slots[pos].add(pos);
            }
            if (ch == '-') {
                slots[pos].less(pos);
            }
            if (ch == '>') {
                slots[pos].right();
            }
            if (ch == '<') {
                slots[pos].left();
            }
            if (ch == '.') {
                slots[pos].dot(pos);
            }
            if (ch == '0') {
                return 0;
            }
        }   //cout << "pos: " << pos << endl;
    }

    return 0;
}
