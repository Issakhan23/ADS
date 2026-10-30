#include <iostream>
#include <vector>
using namespace std;

class Minheap{
private:
    vector <long long> heap;

    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

    void heapifyup(int i){
        while(i > 0){
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
            int curidx = i;
            int leftidx = left(i);
            int rightidx = right(i);
            
            if (leftidx < n && heap[leftidx] < heap[curidx]){
                curidx = leftidx;
            }
            if (rightidx < n && heap[rightidx] < heap[curidx]){
                curidx = rightidx;
            }
            if(curidx != i){
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
        int i = heap.size() - 1;
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
        int tailidx = heap.size()-1;

        swap(heap[0], heap[tailidx]);
        heap.pop_back();
        heapifydown(0);

        return t;
    }

    int size(){
        return heap.size();
    }

};

int main(){

    int q, k;
    long long sum = 0;
    cin >> q >> k;
    Minheap heap;

    for (int i = 0; i < q; i++){
        string com;
        cin >> com;

        if (com == "insert"){
            long long num;
            cin >> num;

            if (k > heap.size()){
                heap.insert(num);
                sum += num;
            }
            else{
                long long a = heap.extractTop();
                if (a > num){heap.insert(a);}
                else{
                    sum -= a;
                    sum += num;
                    heap.insert(num);
                }
            }
        }
        if (com == "print"){
            cout << sum << "\n";
        }

    }

    return 0;
}