#include <iostream>
using namespace std;

class heap{
private:
    int arr[100000];
    int heap_count = 0;
public:
    void swap(int *a, int *b);
    int size();
    void push(int data);
    int pop();
};

void heap::swap(int *a, int *b){
    int tmp = *a; *a = *b; *b = tmp;
}
int heap::size(){
    return heap_count;
}
void heap::push(int data){
    arr[++heap_count] = data;
    int child = heap_count;
    int parent = child/2;
    while(child > 1 && arr[parent] > arr[child]){
        swap(&arr[parent],&arr[child]);
        child = parent;
        parent = child/2;
    }
}
int heap::pop() {
    int result = arr[1];
    swap(&arr[1], &arr[heap_count]);
    heap_count--;
    
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_count) {
        child = (arr[child] < arr[child + 1]) ? child : child + 1;
    }
    
    while (child <= heap_count && arr[parent] > arr[child]) {
        swap(&arr[parent], &arr[child]);
        
        parent = child;
        child = child * 2;
        if (child + 1 <= heap_count) {
            child = (arr[child] < arr[child + 1]) ? child : child + 1;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n;
    heap h;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0) {
            if (h.size() == 0)
                cout << 0 << "\n";
            else
                cout << h.pop() << "\n";
        }
        else
            h.push(num);
    }
}
