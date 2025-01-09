#pragma once

#include <vector>
#include <stdio.h>
#include <algorithm>

using Int = int;
using VecInt = std::vector<Int>;

#define SWAP(a, b) { auto temp = a; a = b; b = temp; }

struct Indexx {
    Int n;
    VecInt indx;

    template<class T>
    Indexx(const std::vector<T>& arr) {
        index(&arr[0], arr.size());
    }

    Indexx() {}

    template<class T>
    void sort(std::vector<T>& brr) {
        if (brr.size() != n) throw std::runtime_error("Bad size in Index sort");
        std::vector<T> tmp(brr);
        for (Int j = 0; j < n; j++) brr[j] = tmp[indx[j]];
    }

    template<class T>
    inline const T& el(const std::vector<T>& brr, Int j) const {
        return brr[indx[j]];
    }

    template<class T>
    inline T& el(std::vector<T>& brr, Int j) {
        return brr[indx[j]];
    }

    void rank(VecInt& irank) {
        irank.resize(n);
        for (Int j = 0; j < n; j++) irank[indx[j]] = j;
    }

    template<class T>
    void index(const T* arr, Int nn) {
        const Int M = 7, NSTACK = 64;
        Int i, indxt, ir, j, k, jstack = -1, l = 0;
        T a;
        VecInt istack(NSTACK);

        n = nn;
        indx.resize(n);
        ir = n - 1;

        for (j = 0; j < n; j++) indx[j] = j;

        for (;;) {
            if (ir - l < M) {
                for (j = l + 1; j <= ir; j++) {
                    indxt = indx[j];
                    a = arr[indxt];
                    for (i = j - 1; i >= l; i--) {
                        if (arr[indx[i]] <= a) break;
                        indx[i + 1] = indx[i];
                    }
                    indx[i + 1] = indxt;
                }
                if (jstack < 0) break;
                ir = istack[jstack--];
                l = istack[jstack--];
            } else {
                k = (l + ir) >> 1;
                SWAP(indx[k], indx[l + 1]);
                if (arr[indx[l]] > arr[indx[ir]]) {
                    SWAP(indx[l], indx[ir]);
                }
                if (arr[indx[l + 1]] > arr[indx[ir]]) {
                    SWAP(indx[l + 1], indx[ir]);
                }
                if (arr[indx[l]] > arr[indx[l + 1]]) {
                    SWAP(indx[l], indx[l + 1]);
                }
                i = l + 1;
                j = ir;
                indxt = indx[l + 1];
                a = arr[indxt];
                for (;;) {
                    do i++; while (arr[indx[i]] < a);
                    do j--; while (arr[indx[j]] > a);
                    if (j < i) break;
                    SWAP(indx[i], indx[j]);
                }
                indx[l + 1] = indx[j];
                indx[j] = indxt;
                jstack += 2;
                if (jstack >= NSTACK) throw std::runtime_error("NSTACK too small in index.");
                if (ir - i + 1 >= j - l) {
                    istack[jstack] = ir;
                    istack[jstack - 1] = i;
                    ir = j - 1;
                } else {
                    istack[jstack] = j - 1;
                    istack[jstack - 1] = l;
                    l = i;
                }
            }
        }
    }
};
