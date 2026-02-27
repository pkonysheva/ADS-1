//Copyright 202 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    bool res = true;
    if (value <= 1) return false;
    if (value <= 3) return true;
    for (uint64_t i = 2; i < value; i++) {
        if (value % i == 0) {
            res = false;
            break;
        }
    }
    if (res == false) return false;
    else return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t cnt = 0;
    uint64_t k = 1;
    while (cnt < n) {
        k++;
        if (checkPrime(k)) cnt++;
    }
    return k;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num1 = value + 1;
    while (!checkPrime(num1)) {
        num1++;
    }
    uint64_t num2 = value - 1;
    while (!checkPrime(num2)) {
        num2--;
    }
    if ((value - num1) > (num2 - value)) return num1;
    else return num2;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t res = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) res += i;
    }
    return res;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t res = 0;
    for (uint64_t i = lbound; i < hbound - 2; i++) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            res++;
        }
    }
    return res;
}
