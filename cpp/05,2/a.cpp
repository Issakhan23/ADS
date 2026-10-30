#include <iostream>
#include <vector>
using namespace std;

class Minheap{
private:
    vector  <long long> heap;
    long parent(long i){return (i-1)/2;}
    long left(long i){return i*2+1;}
    long right(long i){return i*2+2;}

    void heapifyup(int i){
        while (i > 0){
            long p = parent(i);

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
            int curidx = i;
            int leftidx = left(i);
            int rightidx = right(i);

            if (leftidx < n && heap[leftidx] < heap[curidx]){
                curidx = leftidx;
            }

            if (rightidx < n && heap[rightidx] < heap[curidx]){
                curidx = rightidx;
            }

            if (curidx != i){
                swap(heap[i], heap[curidx]);
                i = curidx;
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
        if (heap.empty()){
            return -1;
        }
        return heap[0];
    }

    long long extractTop(){
        if (heap.empty()){return -1;}

        long long t = top();
        int tail = heap.size() - 1;

        swap(heap[0], heap[tail]);
        
        heap.pop_back();
        heapifydown(0);
        
        return t;
    }

    int size(){
        return heap.size();
    }
};

int main(){
    int n;
    cin >> n;
    Minheap heap;

    for (int i = 0; i < n; i++){
        long long num;
        cin >> num;
        heap.insert(num);
    }

    long long ans = 0;

    while (heap.size() > 1){
        long long sum = 0;
        sum += heap.extractTop() + heap.extractTop();
        heap.insert(sum);
        ans += sum;
    }

    cout << ans;
}