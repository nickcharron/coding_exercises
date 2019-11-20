/*
  * Problem Description: https://www.hackerrank.com/challenges/qheap1/problem
  * Author: Nick Charron
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printHeap(vector<int> &v){
  cout << "Heap: ";
  for (auto i : v) cout << i << ' ';
  cout << "\nFront: " << v.front();
  cout << "\nBack: " << v.back() << "\n";
}

void printArray(const vector<int> &arr){
    for (int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

class heap2 {
  public:
    int size = 0;
    vector<int> data{};

    heap2(){}

    void swapElement(int &index1, int &index2){
      int tmp = data[index1];
      data[index1] = data[index2];
      data[index2] = tmp;
    }

    int getLeftIndex(int &index){
      return index * 2 + 1;
    }

    bool getLeftExists(int index){
        if (index * 2 + 1 < size){
          return true;
        } else {
          return false;
        }
    }

    int getRightIndex(int &index){
      return index * 2 + 2;
    }

    bool getRightExists(int index){
        if (index * 2 + 2 < size){
          return true;
        } else {
          return false;
        }
    }

    int getParentIndex(int &index){
      return (index - 1) / 2;
    }

    bool getParentExists(int index){
      if((index - 1) / 2 > 0){
        return true;
      } else {
        return false;
      }
    }

    void printMin(){
      cout << data[0] << "\n";
    }

    void add(int &a){
      data.push_back(a);
      size++;
      heapifyUpwards(size-1);
    }

    void remove(int &a){
      int iter = 0;
      while(iter < size){
        if(data[iter] == a){
          break;
        }
        iter++;
      }
      if (iter == size){
        throw invalid_argument{"Cannot remove element. Element not in heap."};
      }
      data[iter] = data[size-1]; // swap with end element
      data.erase(data.end() - 1, data.end());
      size--;
      heapifyDownwards(iter);
    }

    void heapifyUpwards(int index){
      if (!getParentExists(index)){
        return;
      }
      int parent_index = getParentIndex(index);
      if(data[index] < data[parent_index]){
        return;
      } else {
        swapElement(index, parent_index);
        heapifyUpwards(parent_index);
        return;
      }
    }

    void heapifyDownwards(int index){
      if (!getLeftExists(index)){
        return;
      }
      int leftIndex = getLeftIndex(index);
      int rightIndex = getRightIndex(index);
      if(data[leftIndex] > data[index]){
        return;
      } else {
        swapElement(leftIndex, index);
        heapifyDownwards(leftIndex);
        return;
      }
    }
};

class heap1 {
public:
  vector<int> data;
  heap1(){
    // make_heap (data.begin(), data.end()); // make max heap (top element is max)
    make_heap (this->data.begin(), this->data.end(), greater<int>{}); // make min heap
  }

  void add(int &a){
    this->data.push_back(a); // add element to vector
    // printHeap(data);
    // sort_heap (data.begin(), data.end()); // sort heap
    // make_heap (data.begin(), data.end()); // make heap
    sort_heap (this->data.begin(), this->data.end(), std::greater<int>{}); // sort heap
    make_heap (this->data.begin(), this->data.end(), std::greater<int>{}); // make heap
    // printHeap(data);
  }

  void remove(int &a){
      int iter = 0;
      while(iter < data.size()){
        if(data[iter] == a){
          data.erase(data.begin() + iter);
          sort_heap (data.begin(), data.end(), greater<int>{}); // sort heap
          make_heap (data.begin(), data.end(), greater<int>{}); // make heap
          // printHeap(data);
          return;
        }
        iter++;
      }
      throw invalid_argument{"Cannot remove element. Element not in heap."};
  }
  void printMin(){
    cout << data.front() << "\n";
  }
};

int main() {
    int n;
    cin >> n;

    int operation, value;
    // heap1 heap;
    heap2 heap;
    for (int i = 0; i<n; i++){
      cin >> operation;
      switch (operation) {
        case 1:
          cin >> value;
          heap.add(value);
          break;
        case 2:
          cin >> value;
          heap.remove(value);
          break;
        case 3:
          heap.printMin();
          break;
        default:
          throw invalid_argument{"invalid input."};
          break;
      }

    }
    return 0;
}
