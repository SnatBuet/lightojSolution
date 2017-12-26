#include<vector>
#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstdio>
#include<stack>
#include<cmath>
#include<utility>
#include<list>
#include <string>
#include<map>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define PI acos(-1.0)
#define inf 1<<30
#define EPS 1e-6
#define DI(n) int n;scanf("%d",&n)
#define DII(a,b) int a,b;scanf("%d %d",&a,&b)
#define DIII(a,b,c) int a,b,c;scanf("%d %d %d",&a,&b,&c)
#define REP(i,st,t) int i;for(i = st;i<t;i++)
#define MAX 1000010
#define LIM 1010
int flagArr[MAX >> 6];
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))
int prime[1000021];
int primes = 2;
using namespace std;
void BitSeive()
{
    int i, j, k;
	for (i = 3; i<LIM; i += 2)
	{
		if (!ifComp(i))
		{
			for (j = i*i, k = i << 1; j<MAX; j += k)
				isComp(j);
		}
	}
	k = 2;
	prime[0] = 1;
	prime[1] = 2;
	for (i = 3; i<MAX ; i += 2)
	{
		if (!ifComp(i))
		{
			prime[k++] = i;
			primes++;
		}
	}
}


ll num_of_div(ll x) {
	ll total = 1;
	ll tempx=x,tempSq = (ll)sqrt(x);
	for (ll i = 1; i<primes && prime[i] <= tempSq; i++) {
		ll k = 0;
		while (tempx %prime[i] == 0) {
			tempx = tempx / prime[i];
			k++;
		}
		total *= (k + 1);
		tempSq = (ll)sqrt(tempx);
	}
	if (tempx > 1) {
		total *= 2;
	}
	return total - 1;
}

int main() {
	BitSeive();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ll x;
		scanf("%lld", &x);
		printf("Case %d: %lld\n", i + 1, num_of_div(x));
	}
	return 0;
}