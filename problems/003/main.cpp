/*
Problem:
    Largest prime factor
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143 ?

Usage:
    $ g++ main.cpp -o sln
    $ ./sln
*/

#include <stdio.h>
#include <stdint.h>
#include <map>
using std::map;

int       is_prime             ( uintmax_t );
uintmax_t largest_prime_factor ( uintmax_t );

int main (int argc, char* argv[])
{
    const uintmax_t NUM = 600851475143;
    // const uintmax_t NUM = 133700341223;

    printf("%ju\n", NUM);

    printf("%ju\n", largest_prime_factor(NUM));
    
    // printf("is_prime(6857):         %i\n", is_prime(6857));
    // printf("is_prime(600851475143): %i\n", is_prime(600851475143));
    // printf("600851475143 %% 6857:    %ju\n", NUM % 6857);

    return 0;
}

int is_prime (uintmax_t num) {
    static map<uintmax_t,int> primes;

    if (primes.count(num) == 0) {
        primes[num] = 1;

        uintmax_t i;
        uintmax_t half = num / 2;
        for (i = 2; i <= half; ++i) {
            if (num % i == 0) {
                printf("%ju\n", i);
                primes[num] = 0;
                // return 0;
                break;
            }
        }
    }

    return primes[num];
    // return 1;
}

uintmax_t largest_prime_factor (uintmax_t num) {
    uintmax_t largest = 1;

    uintmax_t i;
    for (i = num / 2; i > 1; --i) {
        // if 'i' is a factor and is also prime
        if (num % i == 0 && is_prime(i)) {
            largest = i;
            break;
        }
    }

    return largest;
}
