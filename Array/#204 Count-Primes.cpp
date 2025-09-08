class Solution {
public:
    int countPrimes(int n) {
        if (n <=2) return 0; // if n is less then 2 , then there is no prime number
        int *isPrime = new int[n]; // Making array for counting isPrime or not
        for (int i=0;i<n;i++)
        {
            isPrime[i] = 1; // initializing all the values as true ,(assuming all are prime)
        }
        isPrime[0] = isPrime[1] = 0; // since 0 and 1 are not prime numbers
        
        for(int p = 2 ; p*p < n ; p++) // going to check only for root(n)
        {
            if(isPrime[p] == 1) // true for all values of p (We initialize all with 1)
            {
                for(int multiple = p*p ; multiple<n ; multiple +=p) // remove all the multiple of selected prime numbers
                {
                    isPrime[multiple] = 0;
                }
            }
        }
        int count = 0; // counting number of 1s which is the value of prime numbers
        for(int i = 2 ; i<n;i++)
        {
            if(isPrime[i] == 1)
            count ++;
        }
        delete[] isPrime; // since we allocated dynamic array by new keyword hence we have to release it by delete keyword and for array delete[]
        return count;
        
    }
};