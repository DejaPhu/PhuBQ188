#include<bits/stdc++.h>
using namespace std;

// Hàm đếm số ký tự chung giữa 2 xâu đã sắp xếp
int demKyTuChung(const string& xau1, const string& xau2) {
    int dem = 0;
    int i = 0, j = 0;
    
    // Duyệt qua cả 2 xâu cùng lúc
    while (i < xau1.length() && j < xau2.length()) {
        if (xau1[i] == xau2[j]) {
            dem++;      // Tìm thấy ký tự chung
            i++;
            j++;
        } 
        else if (xau1[i] < xau2[j]) {
            i++;        // Xâu 1 có ký tự nhỏ hơn
        }
        else {
            j++;        // Xâu 2 có ký tự nhỏ hơn
        }
    }
    return dem;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> danhSachXau(N);
    for (int i = 0; i < N; i++) {
        cin >> danhSachXau[i];
    }
    
    // Tạo thứ tự ban đầu: 0, 1, 2, ..., N-1
    vector<int> thuTu(N);
    for (int i = 0; i < N; i++) {
        thuTu[i] = i;
    }
    
    int soLapNhoNhat = INT_MAX; // Số lặp nhỏ nhất tìm được
    
    // Duyệt qua tất cả các cách sắp xếp
    do {
        int tongLap = 0;
        
        // Tính tổng số lặp giữa các xâu liên tiếp
        for (int i = 0; i < N - 1; i++) {
            int xauHienTai = thuTu[i];
            int xauTiepTheo = thuTu[i + 1];
            tongLap += demKyTuChung(danhSachXau[xauHienTai], danhSachXau[xauTiepTheo]);
        }
        
        // Cập nhật kết quả tốt nhất
        if (tongLap < soLapNhoNhat) {
            soLapNhoNhat = tongLap;
        }
        
    } while (next_permutation(thuTu.begin(), thuTu.end()));
    
    cout << soLapNhoNhat << endl;
    
    return 0;
}
