#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
public:
    Slot(int _var = 0): var(_var) {}

    void add() {
        var++;
    }

    void input_use(queue<char>& input_queue) {
        if (!input_queue.empty()) {
            var = input_queue.front();
            input_queue.pop();
        }
    }

    int get_var() {
        return var;
    }

    void less() {
        var--;
    }

    void dot()  {
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
