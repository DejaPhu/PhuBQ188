#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<int> arr;
vector<int> current;

// Hàm in kết quả
void inKetQua() {
    for (int i = 0; i < current.size(); i++) {
        cout << current[i];
        if (i < current.size() - 1) cout << " ";
    }
    cout << endl;
}

// Hàm quay lui để sinh tổ hợp
void sinhToHop(int batDau, int soLuong) {
    // Nếu đã chọn đủ K phần tử
    if (soLuong == K) {
        inKetQua();
        return;
    }
    
    // Duyệt các phần tử còn lại
    for (int i = batDau; i < N; i++) {
        // Chọn phần tử thứ i
        current.push_back(arr[i]);
        
        // Gọi đệ quy cho phần tiếp theo
        sinhToHop(i + 1, soLuong + 1);
        
        // Bỏ chọn (quay lui)
        current.pop_back();
    }
}

int main() {
    int soBoTest;
    cin >> soBoTest;
    
    while (soBoTest--) {
        cin >> N >> K;
        
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        // Sắp xếp mảng để đảm bảo thứ tự tăng dần
        sort(arr.begin(), arr.end());
        
        // Xóa kết quả cũ
        current.clear();
        
        // Sinh tất cả tổ hợp
        sinhToHop(0, 0);
    }
    
    return 0;
}
