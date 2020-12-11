#include <iostream>
#include <random>
#include <string>
#include "tree.hpp"

int main (int args, char **argv){
        tree t;

        //generate random numbers
        std::default_random_engine rnd;
        std::uniform_int_distribution<int> distribution(1,420);

        for(int i=0;i<5;++i){
            int dice = distribution(rnd);
            auto leave = t.gen_leave();
            std::cout << "insert " << i+1 << ": " << dice << '\n';
            leave->key = dice;
            t.insert(leave);
        }
        // sorted out
        std::cout << "in order tree walk\n";
        t.in_order_tree_walk(t.get_root());
        // TODO pre-order
        // Heap
        std::cout << "pre order tree walk\n";
        t.pre_order_tree_walk(t.get_root());
        // TODO post-order
        // RPN
        std::cout << "post order tree walk\n";
        t.post_order_tree_walk(t.get_root());

        auto min = t.minimum(t.get_root());
        if (min != nullptr)
            std::cout << "minimum: " << min->key << '\n';
        else
            std::cout << "baum leer\n";

        auto max = t.maximum(t.get_root());
        if (max != nullptr)
            std::cout << "maximum: " << max->key << '\n';
        else
            std::cout << "baum leer\n";

        // // wenn argument uebergeben, dann suchen
        // if (args == 2){
        //     auto res = t.search(t.get_root(), std::stoi(argv[1]));
        //     if (res != nullptr)
        //         std::cout << "result: " << res->key << '\n';
        //     else
        //         std::cout << "Wert nicht enthalten\n";
        // }
        if (args == 2){
            auto res = t.search(t.get_root(), std::stoi (argv[1]));
            if (res != nullptr){
                auto successor = t.predesessor(res);
                if (successor != nullptr)
                    std::cout << "successor: " << successor->key << '\n';
                else
                    std::cout << "kein successor\n";
            }
        }
}
