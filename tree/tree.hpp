#ifndef __TREE_H_
#define __TREE_H_

#include "mechanics.hpp"

using inod = mechanics::nod;

class tree {
        public:
                // traversierung
                void in_order_tree_walk(inod *x);
                void pre_order_tree_walk(inod *x);
                void post_order_tree_walk(inod *x);
                // modifikation
                void insert(inod *z);
                // TODO loeschen
                void tree_delete(inod *z);
                // anfrage
                /*
                ** @brief   search for given key
                ** @note    if no match occurs the return value is nullptr
                ** @param x tree or subtree for searching
                ** @param k key what is searched for
                */
                inod *search (inod *x, int k);
                inod *minimum (inod *x);
                inod *maximum (inod *x);
                /*
                ** @note kein Nachfolger -> nullptr
                */
                inod *successor(inod *x);
                inod *predesessor(inod *x);
                // haushalt
                inod *gen_leave();
                inod *get_root();

        private:
                mechanics i_mech;
};

#endif // __TREE_H_
