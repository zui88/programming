#include <chrono>
#include <iostream>
#include "ascq.hpp"


struct StdOut : my::Command {
    void excecute() override{
        std::cout << my::toString(42, "Hey", 5.3) << '\n';
    }
};
struct StdOut1 : my::Command {
    void excecute() override{
        std::cout << my::toString(4211, "Hey12", 521.3) << '\n';
    }
};


int main() {

    my::ASCQ cq;
    cq.assign(StdOut());
    cq.assign(StdOut1());
    cq.invoke();
    cq.assign(StdOut1());
    cq.invoke();

    std::cout << "Hello, World!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    return 0;

}
