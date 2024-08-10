// main.cpp
#include <list.hpp>

int main() {
    Node<int> list = {0, 1, 2, 3, 4};
    list.print(); 

    list.append(5);
    list.print(); 

    list.insert(6, 3);
    list.print(); 

    list.remove(2);
    list.print(); 

    list.remove_data(6);
    list.print(); 

    return 0;
}

