//Bubble Sort
#include<iostream>
using namespace std;

static int comparision=0;
void swap(int *xp,int *yp);

void bubbleSort(int array[],int size){
	for(int i=0;i<size-1;i++)
		for(int j=i+1;j<size;j++)
			if(array[i]>array[j]){
				comparision++;
				swap(&array[i],&array[j]);
			}
}

void swap(int *xp,int *yp){
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}

int main(){
	int size;
	cout<<"Bubble Sort "<<endl;
	cout<<"Enter the number of elements: ";
	cin>>size;
	int array[size];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<size;i++)
		cin>>array[i];
	bubbleSort(array,size);
	cout<<"The sorted elements are: "<<endl;
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	cout<<endl<<"The number of comparision(s) is(are): "<<comparision;
	cout<<endl;
}
