/////////////////////////////////////////////////////////////////////////
// Asynchronous Command Queue - ASCQ
//
// Created by Marco Burkhardt - 06/09/2020
//
// Version 0.1
//
/////////////////////////////////////////////////////////////////////////


#ifndef ASCQ_HPP
#define ASCQ_HPP


#include <memory>
#include <vector>
#include <thread>
#include "util.hpp"


__BEGIN_MY__


    /////////////////////////////////////////////////////////////////////////
    // Interface
    //
    // every concrete command needs to implement this interface
    //
    /////////////////////////////////////////////////////////////////////////
    struct Command {
       virtual void excecute() = 0;
    };


    /////////////////////////////////////////////////////////////////////////
    // Async command queue
    //
    // Manages the incoming commands and invokes them asynchronously by ASCQ::invoke()
    //
    /////////////////////////////////////////////////////////////////////////
    template<class T = Command> class ASCQ {
    private:
        std::vector<std::unique_ptr<T>> vector;

    public:
        /////////////////////////////////////////////////////////////////////////
        // Attach command
        //
        /////////////////////////////////////////////////////////////////////////
        template<class Type, class ... Args>
        void assign(Type commandObj, Args&& ... args);

        template<class Type> void assign(Type commandObj);

        /////////////////////////////////////////////////////////////////////////
        // Async invoker
        //
        /////////////////////////////////////////////////////////////////////////
        void invoke();

    };


    /////////////////////////////////////////////////////////////////////////
    // Definitions
    //
    /////////////////////////////////////////////////////////////////////////
    template<class T>
    void ASCQ<T>::invoke() {
        for (auto &vec : vector) {
            std::thread t(
                    [](std::unique_ptr<T> command) {
                        command->excecute();
                    },
                    std::move(vec));
            t.detach();
        }
        vector.clear();
    }

    template<class T>
    template<class Type, class... Args>
    void ASCQ<T>::assign(Type commandObj [[maybe_unused]], Args &&... args) {
        vector.emplace_back(std::make_unique<Type>((std::forward<Args>(args) , ...)));
    }

    template<class T>
    template<class Type>
    void ASCQ<T>::assign(Type commandObj [[maybe_unused]]) {
        vector.emplace_back(std::make_unique<Type>());
    }


__END_MY__


#endif // ASCQ_HPP