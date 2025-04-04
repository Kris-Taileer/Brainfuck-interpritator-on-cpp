#include <iostream>
#include <vector>
#include <string>
#include "class.h"

using namespace std;

int main() {
    vector <Slot> slots(1000, 0);
    string mes;
    while (mes != "0") {
        while (cin >> mes) {

            if (mes == "+") {
                slots[pos].add(pos);
            }
            if (mes == "-") {
                slots[pos].less(pos);
            }
            if (mes == ">") {
                slots[pos].right();
            }
            if (mes == "<") {
                slots[pos].left();
            }
            if (mes == ".") {
                slots[pos].dot(pos);
            }
            if (mes == "0") {
                return 0;
            }
            //cout << "pos: " << pos << endl; // corpse of debug
        }

    }

    return 0;
}
