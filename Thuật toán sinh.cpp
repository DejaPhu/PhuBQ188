#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

void ktao(){
	for (int i = 1; i <= n; i++) a[i] = 0; // ktao cấu hình đầu tiên
}

void sinh(){
	int i=n;
	while(i >= 1 && a[i] == 1){  // khi chưa phải cáu hình cuối
		a[i] = 0;
		--i;
	}
	if(i == 0) ok = 0; // cấu hình cuối
	else a[i] = 1;
}

bool check(){  // hàm kiểm tra thuận nghịch
	int l = 1, r = n;
	while(l <= r){
		if(a[l] != a[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}

int main(){
	cin >> n;
	ok = 1;
	ktao();
	while(ok){
		if(check()){
		
		for(int i = 1; i <= n; i++){
			cout << a[i] << " "; // in ra cấu hình hiện tại
		}
		cout << endl;
	}
		sinh(); // sinh cấu hình tiếp theo
	}
}
