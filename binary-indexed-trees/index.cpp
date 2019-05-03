//
// Created by GSU on 03.05.2019.
//
#include "index.h"

#include <iostream>
#include <bitset>
#include <bits/stdc++.h>
#include <string>

/*

 BIT - Binary Indexed Tree
 MaxIdx - maximum index which will have non-zero frequency
 f[i] - frequency at index i, i = 1 .. MaxIdx
 c[i] - cumulative frequency at index i (f[1] + f[2] + ... + f[i])
 tree[i] - the sum of frequencies stored at index i of BIT
 num¯ - complement of integer num (integer where each binary digit is inverted: 0 -> 1; 1 -> 0 )
 idx - index of BIT
 r - position in idx of its last non-zero digit in binary notation, i.e., r is the position of the least significant non-zero bit of idx

 */


int binaryIndexedTree() {
    std::cout << "start" << std::endl;

    int MaxIdx = 16;
    int f[] = { 0, 1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2 };
    int c[MaxIdx + 1] = {};
    int tree[MaxIdx + 1] = {};
    int r;
    int idxIndicesFrom;
    std::vector<std::string> strStdout;

    c[0] = 0;
    tree[0] = 0;

    for (int idx = 1; idx <= MaxIdx; idx++) {
        c[idx] = 0;
        tree[idx] = 0;
        for (int iF = 1; iF <= idx; iF++) {
            c[idx] += f[iF];
        }

        r = (log2(idx & -idx) + 1);
        //idxIndicesFrom = (idx - 2^r + 1);
        idxIndicesFrom = idx - ((idx & -idx) - 1);

        for (int iF = idxIndicesFrom; iF <= idx; iF++) {
            tree[idx] += f[iF];
        }

        strStdout.clear();
        strStdout.push_back("idx = " + std::to_string(idx));
        strStdout.push_back("f = " + std::to_string(f[idx]));
        strStdout.push_back("c = " + std::to_string(c[idx]));
        strStdout.push_back("(idx & -idx) = " + std::to_string((idx & -idx)));
        strStdout.push_back("idxIndicesFrom = " + std::to_string(idxIndicesFrom));
        strStdout.push_back("tree = " + std::to_string(tree[idx]));

        std::cout << implode("; ", strStdout) << std::endl;
    }




    return 0;
}

std::string implode(const std::string &glue, const std::vector <std::string> &pieces) {
    std::string a;
    int leng = pieces.size();
    for (int i = 0; i < leng; i++) {
        a += pieces[i];
        if (i < (leng - 1))
            a += glue;
    }
    return a;
}