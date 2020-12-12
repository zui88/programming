#include "tree.hpp"
#include <iostream>

inod *tree::gen_leave(){
    return new inod;
}

inod *tree::get_root(){
    return this->i_mech.root;
}

inod *tree::search(inod *x, int k){
    if (x == nullptr || k == x->key)
        return x;
    if (x->key > k)
        return search(x->left, k);
    else
        return search(x->right, k);
}

inod *tree::minimum (inod *x){
    if (x == nullptr)
        return nullptr;
    while (x->left != nullptr)
        x = x->left;
    return x;
}

inod *tree::maximum (inod *x){
    if (x == nullptr)
        return nullptr;
    while (x->right != nullptr)
        x = x->right;
    return x;
}

inod *tree::successor(inod *x){
    if (x != nullptr && x->right != nullptr)
        return this->minimum(x->right);
    inod *y = x->parent;
    while (y != nullptr && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

inod *tree::predesessor(inod *x){
    if (x != nullptr && x->left != nullptr)
        return this->maximum (x->left);
    inod *y = x->parent;
    while (y != nullptr && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

void tree::in_order_tree_walk(inod *x) {
    if (x != nullptr) {
        this->in_order_tree_walk(x->left);
        std::cout << "x.key: " << x->key << '\n';
        this->in_order_tree_walk(x->right);
    }
}

void tree::pre_order_tree_walk(inod *x){
    if (x != nullptr){
        std::cout << "x.key: " << x->key << '\n';
        pre_order_tree_walk(x->left);
        pre_order_tree_walk(x->right);
    }
}

void tree::post_order_tree_walk(inod *x){
    if (x != nullptr){
        post_order_tree_walk(x->left);
        post_order_tree_walk(x->right);
        std::cout << "x.key: " << x->key << '\n';
    }
}

void tree::insert(inod *z) {
    // knoten, an dem eingefeugt werden soll
    inod *y = nullptr;
    // hilfsvariable
    //     ist wurzel
    inod *x = this->i_mech.root;
    // an unterste ebene eingefuegt
    while (x != nullptr){
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // x wird nicht mehr gebraucht
    // y unterste ebene oder root oder nil
    // z an y einhaengen
    //     order beachten: z.k < y.k -> links
    //                     z.k > y.k -> rechts
    z->parent = y;
    if (y == nullptr)
        this->i_mech.root = z; // neue wurzel
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

// TODO
void tree::tree_delete(inod *z){

}
