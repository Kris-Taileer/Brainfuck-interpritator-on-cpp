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

    void set_var(int i) {
        int new_var;
        cin >> new_var;
        var = new_var;
    }

    int get_var(int i) {
        return var;
    }

    void less(int i) {
        var--;
    }

    void dot(int i)  {
        char out = var;
        cout << out;
    }

    void right()  {
        pos_right(pos);
    }

    void left() {
        pos_left(pos);
    }

};
