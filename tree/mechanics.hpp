#ifndef __MECHANICS_H_
#define __MECHANICS_H_

struct mechanics {
    struct nod {
        nod *left=nullptr, *right=nullptr, *parent=nullptr;
        int key;
    };
    nod *root=nullptr;
};

#endif // __MECHANICS_H_
