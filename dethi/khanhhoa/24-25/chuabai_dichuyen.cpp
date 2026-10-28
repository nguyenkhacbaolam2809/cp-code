#include <bits/stdc++.h>
#define int long long 
#define file "dichuyen"
using namespace std;

const int INF = 1e18 + 18;
int n, m, k, q;
int a[75][75]; 
int dist[75][75]; 
int next_dist[75][75];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m;
    
    // Khởi tạo đồ thị
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = INF;
        }
        a[i][i] = 0; // Đứng yên tốn 0 chi phí
    }

    // ĐỌC VÀ LỌC ĐA CẠNH (Rất quan trọng dù là code trâu)
    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = min(a[u][v], c);
    }

    cin >> k >> q;

    // Giới hạn K cho code trâu để tránh treo máy ở các test 50% cuối (K = 10^9)
    // Các subtask nhỏ có K <= 70 nên ta min với 100 là an toàn chạy qua.
    int limit_k = min(k, 100LL); 

    // dist[i][j] ban đầu là bước 0
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Thực hiện nới lỏng (DP) limit_k lần
    for(int step = 1; step <= limit_k; step++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                next_dist[i][j] = dist[i][j]; // Kế thừa từ bước trước (cho phép đi < K bước)
                
                // Thử nối thêm 1 cạnh từ l tới j
                for(int l = 1; l <= n; l++) {
                    if(dist[i][l] != INF && a[l][j] != INF) {
                        next_dist[i][j] = min(next_dist[i][j], dist[i][l] + a[l][j]);
                    }
                }
            }
        }
        
        // Cập nhật lại kết quả cho bước tiếp theo
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = next_dist[i][j];
            }
        }
    }

    // Trả lời các truy vấn
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(dist[u][v] == INF) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }

    return 0;
}