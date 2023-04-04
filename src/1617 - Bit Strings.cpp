/*
Task:              1617 Bit Strings
Sender:            lorenzo_ferrari
Submission time:   2020-04-30 13:26:11
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define M 1000000007

int fast_exp(long b, long e){
    long t = 1L; 
    for(; e; e>>=1){
        if(e&1)t = (t*b) % M; 
  
        b=(b*b)%M; 
    } 
    return t; 
} 

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fast_exp(2, n));
}