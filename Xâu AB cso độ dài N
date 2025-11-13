#include<bits/stdc++.h>
using namespace std;

int n, a[1000], ok;

void ktao(){
	for(int i = 1; i <= n; i++) a[i] = 0;
} 

void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if(i == 0) ok = 0;
	else a[i] = 1;
	
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		ok = 1;
		ktao();
		while(ok){
			for(int i = 1; i <= n; i++){
				if(a[i]) cout << "B"; //chuyen doi 0/1 thanh A/B
				else cout << "A";
			}
			cout << " ";
			sinh();
		}
		cout << endl;
		
		
	}
}
