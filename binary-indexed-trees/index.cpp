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

const int MaxIdx = 16;
int tree[MaxIdx + 1] = {};
std::vector<std::string> strStdout;

int binaryIndexedTree() {
    std::cout << "init" << std::endl;

    //int tree[MaxIdx + 1] = {};
    int f[] = {0, 1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2};
    int c[MaxIdx + 1] = {};

    int r;
    int idxIndicesFrom;

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
        //strStdout.push_back("c = " + std::to_string(c[idx]));
        //strStdout.push_back("(idx & -idx) = " + std::to_string((idx & -idx)));
        //strStdout.push_back("idxIndicesFrom = " + std::to_string(idxIndicesFrom));
        strStdout.push_back("tree = " + std::to_string(tree[idx]));

        std::cout << implode("; ", strStdout) << std::endl;
    }

    /*int cumulativeFrequency = readingCumulativeFrequency(13);
    //changeFrequencyAtSomePositionAndUpdateTree(5, 1);

    std::cout << std::endl;

    scalingTheEntireTreeByConstantFactor(2);

    for (int idx = 1; idx <= MaxIdx; idx++) {
        //strStdout.clear();
        //strStdout.push_back("idx = " + std::to_string(idx));
        //strStdout.push_back("Cumulative Frequency = " + std::to_string(readingCumulativeFrequency(idx)));
        //strStdout.push_back("The Actual Frequency At Position , to wit f[idx] V1 = " +
        //                    std::to_string(readTheActualFrequencyAtPositionV1(idx)));
        //strStdout.push_back("V2 = " +
        //                    std::to_string(readTheActualFrequencyAtPositionV2(idx)));
        //strStdout.push_back("V3 = " +
        //                    std::to_string(readTheActualFrequencyAtPositionV3(idx)));
        //std::cout << implode("; ", strStdout) << std::endl;

        //readTheActualFrequencyAtPositionV2(idx);

        strStdout.clear();
        strStdout.push_back("idx = " + std::to_string(idx));
        strStdout.push_back("f = " + std::to_string(f[idx]));
        //strStdout.push_back("c = " + std::to_string(c[idx]));
        //strStdout.push_back("(idx & -idx) = " + std::to_string((idx & -idx)));
        //strStdout.push_back("idxIndicesFrom = " + std::to_string(idxIndicesFrom));
        strStdout.push_back("tree = " + std::to_string(tree[idx]));

        std::cout << implode("; ", strStdout) << std::endl;

    }

    std::cout << std::endl;

    scalingTheEntireTreeByConstantFactor(0.5);

    for (int idx = 1; idx <= MaxIdx; idx++) {
        strStdout.clear();
        strStdout.push_back("idx = " + std::to_string(idx));
        strStdout.push_back("f = " + std::to_string(f[idx]));
        strStdout.push_back("tree = " + std::to_string(tree[idx]));
        std::cout << implode("; ", strStdout) << std::endl;
    }*/

    int cumulativeFrequencyIndex = findIndexWithGivenCumulativeFrequency(21);

    strStdout.clear();
    strStdout.push_back("cumulativeFrequencyIndex = " + std::to_string(cumulativeFrequencyIndex));
    std::cout << implode("; ", strStdout) << std::endl;

    return 0;
}

int readingCumulativeFrequency(int idx) { // read
    int sum = 0;
    //std::cout << std::endl;
    //std::cout << "Reading cumulative frequency" << std::endl;

    while (idx > 0) {
        //strStdout.clear();
        //strStdout.push_back("idx = " + std::to_string(idx));
        //strStdout.push_back("idx binary = " + std::bitset<8>(idx).to_string());

        sum += tree[idx];
        idx -= (idx & -idx);

        //strStdout.push_back("tree[idx] = " + std::to_string(tree[idx]));
        //strStdout.push_back("sum = " + std::to_string(sum));
        //std::cout << implode("; ", strStdout) << std::endl;

    }
    return sum;
}

void changeFrequencyAtSomePositionAndUpdateTree(int idx, int val) {
    //std::cout << std::endl;
    //std::cout << "Change frequency at some position and update tree" << std::endl;

    while (idx <= MaxIdx) {
        //strStdout.clear();
        //strStdout.push_back("idx = " + std::to_string(idx));
        //strStdout.push_back("idx binary = " + std::bitset<8>(idx).to_string());
        //strStdout.push_back("tree[idx] old = " + std::to_string(tree[idx]));

        tree[idx] += val;

        //strStdout.push_back("tree[idx] new = " + std::to_string(tree[idx]));

        idx += (idx & -idx);

        //std::cout << implode("; ", strStdout) << std::endl;
    }
}

int readTheActualFrequencyAtPositionV1(int idx) {
    int f_idx = 0;
    f_idx = (int) readingCumulativeFrequency(idx) - (int) readingCumulativeFrequency(idx - 1);
    return f_idx; // f[idx]
}

int readTheActualFrequencyAtPositionV2(int idx) {
    int f_idx = tree[idx]; // this sum will be decreased

    //std::cout << std::endl;
    //std::cout << "The Actual Frequency At Position V2" << std::endl;
    //strStdout.clear();
    //strStdout.push_back("idx = " + std::to_string(idx));
    //strStdout.push_back("f_idx = " + std::to_string(f_idx));
    //std::cout << implode("; ", strStdout) << std::endl;

    if (idx > 0) { // the special case
        int z = idx - (idx & -idx);

        //strStdout.clear();
        //strStdout.push_back("z = " + std::to_string(z));
        //std::cout << implode("; ", strStdout) << std::endl;

        idx--; // idx is not important anymore, so instead y, you can use idx
        while (idx != z) { // at some iteration idx (y) will become z

            //strStdout.clear();
            //strStdout.push_back("idx = " + std::to_string(idx));
            //strStdout.push_back("tree[idx] = " + std::to_string(tree[idx]));

            f_idx -= tree[idx];

            //strStdout.push_back("f_idx = " + std::to_string(f_idx));

            // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);

            //std::cout << implode("; ", strStdout) << std::endl;
        }

    }

    return f_idx; // f[idx]
}

void scalingTheEntireTreeByConstantFactor(double c) {
    for (int i = 1; i <= MaxIdx; i++) {
        /*strStdout.clear();
        strStdout.push_back(std::to_string(i));
        strStdout.push_back(std::to_string(tree[i]));
        strStdout.push_back(std::to_string(tree[i] / c));
        std::cout << implode("; ", strStdout) << std::endl;*/

        tree[i] = tree[i] * c;

    }
}

int findIndexWithGivenCumulativeFrequency(int cumFre) {
    // If in the tree exists more than one index with the same
    // cumulative frequency, this procedure will return
    // some of them
    // bitMask - initialy, it is the greatest bit of MaxIdx
    // bitMask stores the current interval that should be searched

    int idx = 0; // this variable will be the output
    int bitMask = MaxIdx;
    while (bitMask != 0) {
        int tIdx = idx + bitMask;// the midpoint of the current interval

        strStdout.clear();
        strStdout.push_back("tIdx = " + std::to_string(tIdx));

        bitMask >>= 1;// halve the current interval

        strStdout.push_back("bitMask = " + std::to_string(bitMask));
        strStdout.push_back("cumFre = " + std::to_string(cumFre));
        strStdout.push_back("tree[tIdx] = " + std::to_string(tree[tIdx]));
        strStdout.push_back("idx = " + std::to_string(idx));

        if (tIdx > MaxIdx)// avoid overflow
            continue;
        if (cumFre >= tree[tIdx]) {
            // if the current cumulative frequency is equal to cumFre,
            // we are still looking for a higher index (if exists)
            idx = tIdx;// update index
            cumFre -= tree[tIdx];// update the frequency for the next iteration
        }

        std::cout << implode("; ", strStdout) << std::endl;
    }
    if (cumFre != 0)// maybe the given cumulative frequency doesn't exist
        return -1;
    else
        return idx;
}



std::string implode(const std::string &glue, const std::vector<std::string> &pieces) {
    std::string a;
    int leng = pieces.size();
    for (int i = 0; i < leng; i++) {
        a += pieces[i];
        if (i < (leng - 1))
            a += glue;
    }
    return a;
}
