//
// Created by Marco on 06.09.2020.
//

#ifndef UTIL_HPP
#define UTIL_HPP


#include <sstream>


#define __BEGIN_MY__ namespace my {
#define __END_MY__ }


__BEGIN_MY__


    /////////////////////////////////////////////////////////////////////////
    // For formatting
    //
    /////////////////////////////////////////////////////////////////////////
    template <typename ... T> std::string toString(T&& ... t) {
        std::stringstream ss;
        (ss << ... << std::forward<T>(t));
        return ss.str();
    }


__END_MY__


#endif // UTIL_HPP
