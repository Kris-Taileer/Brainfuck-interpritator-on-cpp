#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pos = 0;


void pos_left(int &pos) {
    if (pos == 0) cout << "Negative mem index\n";
    if (pos != 0) pos--;
}

void pos_right(int &pos) {
    pos++;
}

class Slot {
private:
    int var;
    int i;
public:
    Slot(int _var = 0): var(_var) {}

    void add(int i) {
        var++;
    }

    void less(int i) {
        var--;
    }

    void dot(int i)  {
        cout << var << endl;
    }

    void right()  {
        pos_right(pos);
    }

    void left() {
        pos_left(pos);
    }

};
