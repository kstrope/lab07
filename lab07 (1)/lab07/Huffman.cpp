#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
  int freq;
  int id;
  Node *left;
  Node *right;
};

class MinHeap {

  Node **set;
  int max_size;
  int current_size;

public:
  MinHeap(int size);

  int parent(int i) {
    return (i-1)/2;
  }

  int left(int i) {
    return 2*i+1;
  }

  int right (int i) {
    return 2*i+2;
  }

  Node* extractMin();
  void minHeapify(int i);
  void insert(Node *j);
}

  MinHeap::MinHeap(int size) {
    current_size = 0;
    max_size = size;
    set = new int[size];
  }

Node* MinHeap::extractMin() {
  if (current_size <= 0)
    return 0;
  if (current_size == 1) {
    current_size--;
    return set[0];
  }
  Node* root = set[0];
  set[0] = set[current_size-1];
  current_size--;
  minHeapify(0);
  return root;
}



void MinHeap::minHeapify(int i) {
  int x = left(i);
  int y = right(i);
  int z = i;
  Node* temp = new Node;
  if (x < current_size && set[x]->freq < set[i]->freq) {
    z = x;
  }
  if (y < current_size && set[y]->freq < set[z]->freq) {
    z = y;
  }
  if (z != i) {
    temp = set[i];
    set[i] = set[z];
    set[z] = temp;
    MinHeapify(z);
  }
}

void MinHeap::insert(Node *j) {
  Node* temp = new Node;
  current_size++;
  int check = current_size - 1;
  set[check] = j;

  while (check != 0 && set[parent(check)]->freq > set[check]->freq) {
    temp = set[check];
    set[check] = set[parent(check)];
    set[parent(check)] = temp;
    check = parent(check);
  }
}

void print(Node* Q, string code){
	if (!Q) {
		return;
	}
	cout << code;
	print(Q->left, code + "0");
	print(Q->right, code + "1");
	cout << endl;
}

void Huffman (MinHeap Q, int size) {
  Node* x = new Node;
  Node* y = new Node;
  Node* z = new Node;
  for (int i = 0; i < n-1; i++) {
    x = Q.extractMin();
	y = Q.extractMin();
	if (x->freq == y->freq) {
		if (x->id < y->id) {
			z->left = x;
			z->right = y;
		}
		else if (y->id < x->id) {
			z->left = y;
			z->right = x;
		}
	}
    z->freq = x->freq + y->freq;
    z->id = x->id;
    Q.insert(z);
  }
  print (Q.extractMin(), "");
  
}



int main (){
  int num;
  int id = 0;
  cin >> num;
  int input;
  MinHeap Q(num);
  for (int i = 0; i < num; i++) {
    Node* temp = new Node;
    cin >> input;
    temp->freq = input;
    temp->id = id;
    temp->left = NULL;
    temp->right = NULL;
    Q.insert(temp);
    id++;
  }
  
  Huffman(Q, num);
  return 0;
}
