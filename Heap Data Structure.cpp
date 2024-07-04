#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    // Constructor for the heap
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        int ind = ++size;
        arr[ind] = val;

        while (ind > 1) {
            int par = ind / 2;

            if (arr[par] < arr[ind]) {
                swap(arr[par], arr[ind]);
                ind = par;
            } else {
                return;
            }
        }
    }

    // Deletion of root node
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is Empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size) {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int largest = i;

            if (leftChild <= size && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }
            if (largest == i) return;
            else {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }

    void print() {
        cout << "Max Heap: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n && arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }
    if (rightChild <= n && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

////Heap Sorting
void heapSort(int arr[] ,int size){
    while(size > 1){
        swap(arr[1] , arr[size]);
        size--;
        heapify(arr , 1 , size);
    }
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Heap h;
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);
    h.print();
    h.deleteRoot();
    h.print();

}
