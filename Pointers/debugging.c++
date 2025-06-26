#include <bits/stdc++.h>
using namespace std;

// void SieveOfEratosthenes(int n)
// {
//     vector<bool> prime(n+1, true);
//     prime[0]=prime[1]=false;

//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p]) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false; // Mark multiples of p as not prime
//         }
//     }

//     for (int p = 2; p <= n; p++) {
//         if (prime[p])
//             cout << p << " ";
//     }
// }

// void fillPrimes(vector<int> &prime, int high)
// {
//     vector<bool> ck(high + 1, true);
//     for (int i = 2; (i * i) <= high; i++)
//     {
//         if (ck[i] == true)
//         {
//             for (int j = i * i; j <= sqrt(high); j = j + i)
//             {
//                 ck[j] = false;
//             }
//         }
//     }
//     for (int i = 2; i * i <= high; i++)
//     {
//         if (ck[i] == true)
//         {
//             prime.push_back(i);
//         }
//     }
// }

// void segmentedSieve(int low, int high)
// {
//     if (low < 2 and high >= 2)
//     {
//         low = 2;
//     }
//     vector<bool> prime(high - low + 1, true);
//     vector<int> chprime;
//     fillPrimes(chprime, high);
//     for (int i : chprime)
//     {
//         int lower = (low / i);
//         if (lower <= 1)
//         {
//             lower = i + i;
//         }
//         else if (low % i)
//         {
//             lower = (lower * i) + i;
//         }
//         else
//         {
//             lower = (lower * i);
//         }
//         for (int j = lower; j <= high; j = j + i)
//         {
//             prime[j] = false;
//         }
//     }

//     for (int i = low; i <= high; i++)
//     {
//         if (prime[i] == true)
//         {
//             cout << (i) << " ";
//         }
//     }
// }

bool isPrime(int n)
{
    if (n == 1)
        return false;
 
    for (int i = 2; i <= n / 2; i++)
        if (n % i)
            return false;
 
    return true;
}

int main()
{
    int n = 5;
    // SieveOfEratosthenes(n);
    // fillPrimes()
    isPrime(n);
     return 0;
}