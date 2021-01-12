#include <World.hpp>
#include <iostream>

int main () {
    std::cout << "Press `s' to start (the cube will start to move).\n"
              << "Press `x', `X', `y', `Y', `z' or `Z' to change its direction.\n"
              << "Press `f' or `b' to change the projection plane\n";
    World w{};
    w.Loop();
}
