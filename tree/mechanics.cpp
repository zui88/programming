#include "mechanics.hpp"

void mechanics::transplant(nod *u, nod *v){
    if (u->parent == nullptr)
        this->root = v;
    else if (u->parent->right == v->parent)
        u->parent->right = v;
    else
        u->parent->left = v;
    if (v != nullptr)
        v->parent = u->parent;
}
