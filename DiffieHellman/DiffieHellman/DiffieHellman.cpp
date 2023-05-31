#include <iostream>
#include <cmath>

long long powerMod(long long base, long long exponent, long long modulus) 
{
    long long result = 1;
    
    base = base % modulus;
    
    while (exponent > 0) 
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }

        exponent = exponent >> 1;
        
        base = (base * base) % modulus;
    }

    return result;
}

bool isPrime(long long n) 
{
    if (n <= 1)
    {
        return false;
    }

    if (n <= 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (long long i = 5; i * i <= n; i += 6) 
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

long long findPrimitiveRoot(long long q) 
{
    for (long long a = 2; a < q; a++) 
    {
        bool isPrimitive = true;
        
        for (long long i = 2; i < q - 1; ++i) 
        {
            if (powerMod(a, i, q) == 1) 
            {
                isPrimitive = false;
                break;
            }
        }

        if (isPrimitive)
        {
            return a;
        }
    }

    return -1;
}

int main() 
{
    long long q, a;
    
    std::cout << "Enter the prime number: ";
    
    std::cin >> q;

    std::cout << std::endl;

    if (!isPrime(q)) 
    {
        std::cout << "The given number is not prime. Please try again." << std::endl;
        return 0;
    }

    a = findPrimitiveRoot(q);
    
    if (a == -1) 
    {
        std::cout << "No primitive root found for the given prime number." << std::endl;
        return 0;
    }

    std::cout << "The primitive root of the given prime number is " << a << "." << std::endl << std::endl;

    long long XA, XB;
    
    std::cout << "Enter X for A: ";
    
    std::cin >> XA;

    std::cout << std::endl;
    
    std::cout << "Enter X for B: ";
    
    std::cin >> XB;

    std::cout << std::endl;

    long long YA = powerMod(a, XA, q);
    long long KA = powerMod(YA, XB, q);

    long long YB = powerMod(a, XB, q);
    long long KB = powerMod(YB, XA, q);

    std::cout << "Y for A: " << YA << ", K for A: " << KA << std::endl;

    std::cout << std::endl;

    std::cout << "Y for B: " << YB << ", K for B: " << KB << std::endl;

    return 0;
}