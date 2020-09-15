//C++ program to implement heap sort.
#include<iostream>
using namespace std;

int static comparision=0;
int count1=0;
int count2=0;

int max_heapify(int array[],int i,int n){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&array[l]>array[largest]){
		largest=l;
		comparision++;
	}
	if(r<n&&array[r]>array[largest]){
		largest=r;
		comparision++;
	}
	if(largest!=i){
		//comparision++;
		swap(array[i],array[largest]);
		max_heapify(array,largest,n);
	}
	return comparision;
}

void build_maxheap(int array[],int n){
	for(int i=n/2-1;i>=0;i--)
		count1=max_heapify(array,i,n);
	cout<<"comparisions: "<<count1<<endl;
}

void heapsort(int array[],int n)
{
	int count=0;
	build_maxheap(array,n);
	for(int i=n-1;i>=0;i--){
		swap(array[0],array[i]);
		count=max_heapify(array,0,i);
	}
	cout<<"The total no of comparision is: "<<count<<endl;
}

void swap(int &x,int &y){
	int temp=x;
	x=y;
	y=temp;
}

int main(){
	int no_of_elements;
	cout<<"Enter the number of elements: ";
	cin>>no_of_elements;
	int array[no_of_elements];
	cout<<"Enter the elements of the array: ";
	for(int i=0;i<no_of_elements;i++)
		cin>>array[i];
	heapsort(array,no_of_elements);
	cout<<endl<<"The sorted array is: "<<endl;
	for(int i=0;i<no_of_elements;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	//cout<<"The number of comparisions performed is: "<<comparision;
	cout<<endl;
}


