#include<iostream>
using namespace std;
// Insertion 
void  insertSort(int arr[], int n){
	int i, j, tmp;
	for(i = 1; i < n; ++i){
		tmp = arr[i];
		for(j = i-1; j >= 0 && tmp < arr[j]; --j){
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}
void binaryInsertSort(int arr[], int n){
	int i, j, tmp;
	for(i = 1; i < n; ++i){
		tmp = arr[i];
		int low = 0, high = i-1, mid;
		while(low <= high){
			mid = (low + high)/2;
			if(tmp > arr[mid])
				low = mid + 1;
			else 
				high = mid -1;
		}
		// After forloop low is alway bigger than high by 1. 
		// And arr[high] < tmp < arr[low]
		for(j = i-1; j >= low; --j){
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}

void shellSort(int arr[], int n){
	int i, j, dk, tmp;
	for(dk = n/2; dk >= 1; dk /= 2)
		for(i = dk; i < n; ++i){
			tmp = arr[i];
			for(j = i-dk; j >= 0 && tmp < arr[j]; j -= dk){
				arr[j+dk] = arr[j];
			}
			arr[j+dk] = tmp;
		}
}
// Sentinel have two function: 1, tempraray store data; 2, prevention 
// cross-border. If we use sentinel, all the notation should be moved 
// backward by 1. For example:
// 
//	for(i=2; i<=n; ++i)
//		if(arr[i] < arr[i-1]){
//			arr[0] = arr[i];
//			for(j=i-1; arr[0] < arr[j]; --j)
//				arr[j+1] = arr[j];
//			arr[j+1] = arr[0];
//		}

// Swap
void bubbleSort(int arr[], int n){
	int i, j, tmp;
	for(i = 0; i < n; ++i)
		for(j = n-1; j > i; --j){
			if(arr[j] < arr[j-1]){
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
}

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	while(low < high){
		while(low < high && arr[high] >= pivot)
			--high;
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivot)
			++low;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return high;

}
void quickSort(int arr[], int low, int high){
	if(low < high){
		int pivotpos = partition(arr, low, high);
		quickSort(arr, low, pivotpos-1);
		quickSort(arr, pivotpos+1, high);
	}
}
// Selection
void selectSort(int arr[], int n){
	int i, j, min, tmp;
	for(i = 0; i < n-1; ++i){
		min = i;
		for(j = i+1; j < n; ++j)
			if(arr[j] < arr[min])
				min = j;
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}
// HeapSort:
// 由于完全二叉树的顺序存储下标之间的关系，当把数组第一个元素用作哨兵时，便于计算它的父节点(n/2)和子节点的下标(2n, 2n+1), 所以把头节点空出来不存储元素，这个空出来的节点可以当作暂存元素；
// 如此一来，可以在排序的第一步把原数据复制到一个新的比它大1的数组中，然后再进行操作，排序完成后，把结果再复制回原数组中；
// i is children, k is parents of i
// k is something like previous.
// k is last node larger than tmp
void adustUp(int arr[], int k, int n){
	arr[0] = arr[k];
	for(int i = k/2; i > 0 && arr[i] < arr[0]; i /= 2){
		arr[k] = arr[i];
		k = i;
	}
	arr[k] = arr[0];
}
// After adjustDown, all the element below k is a maxHeap.
void adjustDown(int arr[], int k, int n){
	arr[0] = arr[k];
	for(int i = 2*k; i <= n; i *= 2){
		if(i < n && arr[i] < arr[i+1])
			++i;
		if(arr[0] < arr[i]){
			arr[k] = arr[i];
			k = i;
		}
		else
			break;
	}
	arr[k] = arr[0];

}
void buildMaxHeap(int arr[], int n){
	for(int i = n/2; i > 0; --i){
		adjustDown(arr, i, n);
	}
}
void heapSort(int* &A, int n){
	int* arr = new int[n+1];
	arr[0] = 0;
	for(int i = 0; i < n; ++i)
		arr[i+1] = A[i];

	buildMaxHeap(arr, n);
	int tmp;
	for(int i = n; i > 1; --i){
		tmp = arr[i];
		arr[i] = arr[1];
		arr[1] = tmp;
		adjustDown(arr, 1, i-1);
	}
	A = arr+1;
}
void printArray(int A[], int n){
	for(int i=0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;

}

// mergeSort: for array

int n ;
int* B = new int[n];

void mergeCore(int A[], int low, int mid, int high){
	for(int k = low; k <= high; ++k)
		B[k] = A[k];
	int i, j, k;
	for(i = low, j = mid+1, k = i; i <= mid && j <= high; ++k){
		if(B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	while(i <= mid)  A[k++] = B[i++];
	while(j <= high) A[k++] = B[j++];
}

void mergeSort(int arr[], int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		mergeCore(arr, low, mid, high);
	}
}

// mergeSort: for linked-list
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	ListNode(){}
};

// It's important to set a bounder as NULL instead of using the 
// next node as bounder.Because It can be changed easily and we 
// can hardly notice it's change. 
// It's important to make arguement to be the type of reference, 
// Because we want the pointer to change after function effect, 
// not only the value pointed by it, but the also the pointer. 

void mergeCore(ListNode* &p1, ListNode* p2){
	static ListNode* dummy = new ListNode(0);
	ListNode* p = dummy;
	while(p1 && p2){
		if(p1->val <= p2->val){
			p->next = p1;
			p1 = p1->next;
			p = p->next;
		}
		else{
			p->next = p2;
			p2 = p2->next;
			p = p->next;
		}
	}
	if(p1) p->next = p1;
	if(p2) p->next = p2;
	p1 = dummy->next;
}

void mergeSort(ListNode* &head){
	if(head && head->next){
		ListNode* p1 = head;
		ListNode* p2 = head;
		while(p2->next && p2->next->next){
			p1 = p1->next;
			p2 = p2->next->next;
		}
		p2 = p1->next;

		p1->next = NULL;
		p1 = head;
	
		mergeSort(p1);
		mergeSort(p2);
		mergeCore(p1, p2);
		head = p1;
	}
}

ListNode* createList(int A[], int n){
	if(n < 1)
		return NULL;
	ListNode* dummy = new ListNode(0);
	ListNode* p = dummy;
	for(int i = 0; i < n; ++i){
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	return dummy->next;
}

void printList(ListNode* head){
	if(!head)
		return;
	ListNode* p = head;
	for(ListNode* p = head; p; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

int main(){
	int i, j;
	int A[] = {34, 56, 76, 51, 27, 48, 74, 23, 20, 32};
	n = sizeof(A)/sizeof(int);
	int* p = A;
	ListNode* head = createList(p, n);
	mergeSort(head);
	printList(head);
	return 0;
}
