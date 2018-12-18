#include<iostream>
using namespace std;
// Based on insertion
void insertSort(int* arr, int n){
	int i, j, tmp;
	for(i = 1; i < n; ++i){
		tmp = arr[i];
		for(j = i-1; j >= 0 && tmp < arr[j]; j--)
			arr[j+1] = arr[j];
		arr[j+1] = tmp;
	}
}

void shellSort(int* arr, int n){
	int dk, i, j, tmp;
	for(dk = n/2; dk >= 1; dk /= 2)
		for(i = dk; i < n; ++i){
			tmp = arr[i];
			for(j = i-dk; j >= 0 && tmp < arr[j]; j -= dk)
				arr[j+dk] = arr[j];
			arr[j+dk] = tmp;
		}

}

void binarrryInsertSort(int* arr, int n){
	int i, j, tmp, pos;
	for(i = 1; i < n; i++){
		tmp = arr[i];
		int low = 0, high = i-1, mid = 0;
		while(low <= high){
			mid = (low + high)/2;
			if(tmp < arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		for(j = i-1; j >= low; j--)
			arr[j+1] = arr[j];
		arr[j+1] = tmp;
	}
}

// Based on swap
void bubbleSort(int* arr, int n){
	int i, j;
	bool flag;
	for(i = 0; i < n; i++){
		flag = false;
		for(j = 1; j < n-i; j++){
			if(arr[j] < arr[j-1]){
				swap(arr[j], arr[j-1]);
				flag = true;
			}
		}	
		if(flag == false)
			break;
	}
}

int partition(int low, int high, int arr[]){
	int tmp = arr[low];
	while(low < high){
		while(arr[high] > tmp && low < high) high--;
		arr[low] = arr[high];
		while(arr[low] < tmp && low < high) low++;
		arr[high] = arr[low];
	}
	arr[high] = tmp;
	return high;
}

void quickSort(int low, int high, int arr[]){
	if(low >= high)	// Notice here, don't forget '>' .
		return;
	else{		// low < high
		int pivot = partition(low, high, arr);
		quickSort(low, pivot-1, arr);
		quickSort(pivot+1, high, arr);
	}
}

// Based on selection
void selectSort(int* arr, int n){
	int i, j, tmp;
	for(i = 1; i < n; i++){
		tmp = arr[i];
		for(j = i-1; j >= 0 && tmp < arr[j]; j--){
				arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}

void adjustDown(int* arr, int k, int n){
	int tmp = arr[k];
	for(int i = 2*k; i <= n; i *= 2){
		if(i+1 <= n && arr[i+1] > arr[i])
			i++;
		if(tmp < arr[i]){
			arr[k] = arr[i];
			k = i;
		}
		else
			break;
	}
	arr[k] = tmp;

}

void buildMaxHeap(int* arr, int n){
	for(int i = n/2; i > 0; --i)
		adjustDown(arr, i, n);


}

void heapSort(int* &array, int n){
	int* arr= new int[n+1];
	for(int i = 1; i <= n; i++)
		arr[i] = array[i-1];
	arr[0] = 0;
	buildMaxHeap(arr, n);
	for(int i = n; i > 1; i--){
		swap(arr[i], arr[1]);
		adjustDown(arr, 1, i-1);
	}
	array = arr+1;
}


void printarr(int* A, int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

// mergeSort

int n;
int* B = new int[n];
void mergeCore(int* arr, int low, int mid, int high){
	for(int k = low; k <= high; ++k)
		B[k] = arr[k];
	int i, j, k;
	for(i = low, j = mid+1, k = i; i <= mid && j <= high; ++k){
		if(B[i] <= B[j])
			arr[k] = B[i++];
		else
			arr[k] = B[j++];
	}
	while(i <= mid)
		arr[k++] = B[i++];
	while(j <= high)
		arr[k++] = B[j++];
	
}

void mergeSort(int* arr, int low, int high){
	if(low >= high){
		return;
	}
	else{
		int mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		mergeCore(arr, low, mid, high);
	}

}

static int A[] = {23, 45, 34, 53, 78, 90, 12, 84};
static int C[] = {34, 56, 76, 51, 27, 48, 74, 23, 20, 32};
static int na = sizeof(A)/sizeof(int);
static int nc = sizeof(C)/sizeof(int);

void tested(){
	cout << "InsertSort:\t\t";
	insertSort(A, na);
	printarr(A, na);
	cout << "ShellSort:\t\t";
	shellSort(A, na);
	printarr(A, na);
	cout << "bubbleSort:\t";
	bubbleSort(C, nc);
	printarr(C, nc);
	cout << "quickSort:\t";
	quickSort(0, nc-1, C);
	printarr(C, nc);
	cout << "selectSort:\t";
	selectSort(C, nc);
	printarr(C, nc);
	cout << "heapSort:\t";
	int* p = A;
	heapSort(p, na);
	printarr(p, na);
}
int main(){
	//tested();
	cout << "mergeSort:\t";
	mergeSort(C, 0, nc-1);
	printarr(C, nc);
	
	return 0;
}
