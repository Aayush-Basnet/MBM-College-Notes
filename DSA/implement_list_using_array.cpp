#include <iostream>
using namespace std;
class ArrayList {
private:
    int capacity;
    int size;
    int* data;
public:
    ArrayList(int initialCapacity) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }
  void insert(int value) {
        if (size < capacity) {
            data[size++] = value;
        } else {
            cout << "List is full!" << endl; }  }
  void remove(int value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                index = i;
                break;  }  }
       if (index != -1) {
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        } else {
            cout << "Element not found!" << endl;
        }
    }
   void display() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
 ~ArrayList() {
        delete[] data;
    }
};
int main() {
    ArrayList arrList(5);
    arrList.insert(10);
    arrList.insert(20);
    arrList.insert(30);
    arrList.display();
    arrList.remove(20);
    arrList.display();
    return 0;
}

