#include<bits/stdc++.h>
using namespace std;
// thuat toan sinh
int n, a[100], ok;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0; //<Khoi tao cau hinh dau tien>
	}
}
//<Khoi tao cau hinh dau tien>
void sinh(){
	int i = n;
	while( i >= 1 && a[i] == 1){ //while(<Khi chua phai cau hinh cuoi cung>){
		a[i] = 0;
		--i;
	}
	if(i == 0){
		ok = 0; // kiem tra xem co phai cau hinh cuoi cung khong?
	}
	else{
		a[i] = 1;
	}
}
//kiem tra thuan nghich
bool check(){
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
			for(int i = 1; i <=n; i++){
				cout << a[i] << " "; //	<In ra cau hinh hien tai>
		}
	cout << endl;
	}
	sinh();//	<Sinh ra cau hinh tiep theo
	}
}
