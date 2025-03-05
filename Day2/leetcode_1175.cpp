class Solution {
public:
    int mod=1e9+7;
    int isprime(int n){
        if(n<2) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int prime_count(vector<int>vec,int n){
        int count=0;
        for(int i=0;i<vec.size();i++){
            if(isprime(vec[i])==1){
                count++;
            }
        }
        return count;
    }

    unsigned long long factorial(int n){
        unsigned long long res=1;
        for(int i=2;i<=n;i++){
            res=(res*i)%mod;
        }
        return res;
    }
    int numPrimeArrangements(int n) {

        vector<int>vec;
        for(int i=1;i<=n;i++){
            vec.push_back(i);
        }
        int prime_counts=prime_count(vec,n);
        int non_prime_count=n-prime_counts;
        return ((factorial(prime_counts)%mod)* (factorial(non_prime_count)%mod))%mod;
    }
};
