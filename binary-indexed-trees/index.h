//
// Created by GSU on 03.05.2019.
//
#include <iostream>
#include <bitset>
#include <bits/stdc++.h>
#include <string>

#ifndef WORK_DATA_STRUCTURES_INDEX_H
#define WORK_DATA_STRUCTURES_INDEX_H

std::string implode(const std::string &glue, const std::vector<std::string> &pieces);

int binaryIndexedTree();

int readingCumulativeFrequency(int idx);

void changeFrequencyAtSomePositionAndUpdateTree(int idx, int val);

int readTheActualFrequencyAtPositionV1(int idx);

int readTheActualFrequencyAtPositionV2(int idx);

void scalingTheEntireTreeByConstantFactor(double c);

int findIndexWithGivenCumulativeFrequency(int cumFre);


#endif //WORK_DATA_STRUCTURES_INDEX_H
