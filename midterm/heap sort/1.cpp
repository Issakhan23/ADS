//min heap

class Minheap {
private:
    vector<int> heap;
    int parent (int i) {return (i-1)/2;}
    int left(int i) {return i*2+1;}
    int right(int i) {return i*2+2;}

    void heapup (int i) {
        while (i > 0) {
            int p = parent(i);
            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
    }
    void heapdw(int i) {
        int n = heap.size();

        while (true) {
            int curidx = i;
            int leftidx = left(i);
            int rightidx = right(i);

            if (leftidx < n && heap[leftidx] < heap[curidx]) {
                curidx = leftidx;
            } 
            if (rightidx < n && heap[rightidx] < heap[curidx]) {
                curidx = rightidx;
            }

            if (curidx != i) {
                swap(heap[i], heap[curidx]);
                i = curidx;
            } else {
                break;
            }
        }
    }
public:
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size()-1;
        heapup(i);
    }

    int top() {
        if (heap.empty()) {
            return -1;
        }
        return heap[0];
    }

    int extract() {
        if (heap.empty()) {return -1;}
        int t = top();
        int tail = heap.size()-1;
        swap(heap[0], heap[tail]);
        heap.pop_back();
        heapdw(0);
        return t;
    }

    int size() {
        return heap.size();
    }

};

int main() {
    Minheap heap;
    for () {
        cin >> x;
        heap.insert(x);
    }
    return 0;
}