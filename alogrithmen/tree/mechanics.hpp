#ifndef __MECHANICS_H_
#define __MECHANICS_H_

struct mechanics {
    struct nod {
        nod *left=nullptr, *right=nullptr, *parent=nullptr;
        int key;
    };
    nod *root=nullptr;

    // hilfsfunktionen

    /*
    ** @brief replacement of the nod u with the give subtree v
    ** @param u  to remove
    ** @param v  replacing subtree
    ** @warning  subtree of u not regarded! The high level function must care about reordering
    */
    void transplant (nod *u, nod *v);
};

#endif // __MECHANICS_H_
