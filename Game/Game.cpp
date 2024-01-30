
#include <iostream>
#include <ctime>

#define SIZE 3

using namespace std;

class drums {
    int* one;
    int max;
    int min;
public:
    drums() : one(0), max(0), min(0) {}
    drums(int speed);
    ~drums();
    void add(int c);
    bool full();
    bool clear();
    void show(const drums& secondwheel, const drums& thirdwheel);
    bool spinned();
    bool win(const drums& sec, const drums& third);
};

drums::~drums() {
    delete[] one;
}

drums::drums(int speed) {
    max = speed;
    one = new int[max];
    min = 0;
}

bool drums::full() {
    return min == max;
}

bool drums::clear() {
    min = 0;
    return true;
}

void drums::show(const drums& secondwheel, const drums& thirdwheel) {
    for (int i = 0; i < min; i++) {
        cout << one[i] << i << "-Drum ";
        cout << secondwheel.one[i] << i << "-Drum ";
        cout << thirdwheel.one[i] << i << "-Drum " << endl;
    }
}

void drums::add(int c) {
    if (!full()) {
        one[min++] = c;
    }
}

bool drums::spinned() {
    int random = rand() % 4;
    int x = one[0];
    for (int i = 0; i < random; i++) {
        for (int j = 0; j < min; j++) {
            one[j] = one[(j + 1) % min];
        }
        one[min - 1] = x;
    }
    return true;
}


bool drums::win(const drums& sec, const drums& third) {
    for (int i = 0; i < min; i++) {
        if (one[i] == sec.one[i] && one[i] == third.one[i]) {
            cout << "Congrats! You won: " << one[i]  << i << "-Drum" << endl;
            cout << sec.one[i] << i << "-Drum" << endl;
            cout << third.one[i] << i << "-Drum" << endl;
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));

    drums firstwheel(SIZE);
    drums secondwheel(SIZE);
    drums thirdwheel(SIZE);
    
    int i = 0;
    while ( i < SIZE) {
        firstwheel.add(rand() % 7);
        secondwheel.add(rand() % 7);
        thirdwheel.add(rand() % 7);
        i++;
    }
    cout << "Original result: " << endl;
    firstwheel.show(secondwheel, thirdwheel);

    cout << "Started roll: " << endl;
    firstwheel.spinned();
    secondwheel.spinned();
    thirdwheel.spinned();
    firstwheel.show(secondwheel, thirdwheel);
    

    cout << (firstwheel.win(secondwheel, thirdwheel) ? "Won" : "Lost") << endl;
    
    return 0;
}



