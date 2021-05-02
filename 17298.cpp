#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int ans[1000001];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i <= N; i++) ans[i] = -1;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
}
