#include<bits/stdc++.h>
using namespace std;
// Brute force
class Solution {
public:
    int maxVowels(string s, int k) {
        int temp=0,best=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<i+k;j++){
                if(s[j]=='a' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='e')
                temp++;   
            }
            best=max(best,temp);
             temp=0;
        }
        return best;
  }        
};
   

// This is sliding window approach best solution with no extra spcae.
class Solution {
public:
    int maxVowels(string s, int k) {

        int temp=0,best=0;
        int i=1,j,n=s.length();
         for(j=0;j<k;j++){
             if(s[j]=='a' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='e')
            temp++,best++;
    
         }
         
          while(j<=n){

          if(s[i-1]=='a' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u' || s[i-1]=='e')
           temp--;
         
           if(s[j]=='a' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='e')
           temp++;

            best=max(best,temp);
              i++,j++;
            }

            return best;

        }
};
   