
#include<bits/stdc++.h>
#include<string>
using namespace std;
int n, res;
int a[10], u[10], tmp[10];
bool stop;
void solve(){
	res++; // Số thứ tự hoán vị
	for(int i = 1; i <= n; i++){
		if(a[i] != tmp[i]) return;
	}
	stop = true;
}
// sinh hoán vị mới
void Try(int i){
	if(stop) return;
	for(int j = 1; j <= n; j++){
		if(!u[j]){
			a[i] = j;
			u[j] = 1;
			if(i == n) solve();
			else Try(i+1);
			u[j] = 0;
		}
	}
}
void Testcase(){
	cin >> n;
	res = 0; stop = false;
	memset(u, 0, sizeof(int));
	for(int i = 1; i <= n; i++){
		cin >> tmp[i];
	}
	Try(1);
	cout << res <<endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Testcase();
			
	}
}
