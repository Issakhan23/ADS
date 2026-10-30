#include <iostream>
#include <vector>
using namespace std;

class Minheap{
    vector <long long> heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

    void heapifyup(int i){
        while (i > 0){
            int p = parent(i);

            if (heap[i] < heap[p]){
                swap(heap[i], heap[p]);
                i = p;
            }
            else{
                break;
            }
        }
    }

    void heapifydown(int i){
        int n = heap.size();
        while (true){
            int cur = i;
            int l = left(i);
            int r = right(i);

            if (l < n && heap[l] < heap[cur]){
                cur = l;
            }
            if (r < n && heap[r] < heap[cur]){
                cur = r;
            }
            if (cur != i){
                swap(heap[i],heap[cur]);
                i = cur;
            }
            else{
                break;
            }
        }
    }
public:
    void insert(long long x){
        heap.push_back(x);
        int i = heap.size()-1;
        heapifyup(i);
    }

    long long top(){
        if (heap.empty()){return -1;}
        return heap[0];
    }

    long long extractTop(){

        if (heap.empty()){return -1;}

        long long t = top();
        int tail = heap.size()-1;
        swap(heap[0], heap[tail]);
        heap.pop_back();
        heapifydown(0);
        return t;
    }

    int size(){return heap.size();}


};

int main(){
    int n, m;
    Minheap heap;
    cin >> n >> m;

    for (int i = 0; i < n ; i++){
        long long num;
        cin >> num;
        heap.insert(num);
    }

    long long d = heap.top(), cnt = 0;

    while(heap.size() > 1 && m > heap.top()){
        d = heap.extractTop() + 2 * heap.extractTop();
        cnt ++;
        heap.insert(d);
    }

    if (d >= m){
        cout << cnt;
    }
    else{
        cout << -1;
    }
    return 0;
}