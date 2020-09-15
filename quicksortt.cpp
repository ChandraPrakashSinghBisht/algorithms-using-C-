#include<iostream>
using namespace std;

void quickSort(int E[],int first,int last );
int partition(int E[],int pivot,int first,int last);
int extendLargeRegion(int E[],int pivot,int lowVac,int high);
int extendSmallRegion(int E[],int pivot,int low,int highVac);
static int comparision=0;

void quickSort(int E[],int first,int last){
	if(first<last){
		int pivot=E[first];
		int splitpoint=partition(E,pivot,first,last);
		E[splitpoint]=pivot;
		quickSort(E,first,splitpoint-1);
		quickSort(E,splitpoint+1,last);
	}
}

int partition(int E[],int pivot,int first,int last){
	int low,high;
	low=first;
	high=last;
	while(low<high){
		int highVac=extendLargeRegion(E,pivot,low,high);
		int lowVac=extendSmallRegion(E,pivot,low+1,highVac);
		low=lowVac;
		high=highVac-1;
	}
	return low;
}

int extendLargeRegion(int E[],int pivot,int lowVac,int high){
	int highVac,curr;
	highVac=lowVac;
	curr=high;
	while(curr>lowVac){
		comparision++;           //comparision++
		if(E[curr]<pivot){
			E[lowVac]=E[curr];    //succeed
			highVac=curr;
			break;
		}
		curr--;
	}
	return highVac;
}

int extendSmallRegion(int E[],int pivot,int low,int highVac){
	int lowVac,curr;
	lowVac=highVac;			//Assume failure
	curr=low;
	while(curr<highVac){
		comparision++;			//comparision++
		if(E[curr]>=pivot){
			E[highVac]=E[curr];
			lowVac=curr;
			break;
		}
		curr++;
	}
	return lowVac;
}

int main(){
	int no_of_numbers;
	cout<<"Enter the number of elements: ";
	cin>>no_of_numbers;
	int array[no_of_numbers];
	cout<<"Enter the elements :"<<endl;
	for(int i=0;i<no_of_numbers;i++)
		cin>>array[i];
	quickSort(array,0,no_of_numbers-1);
	cout<<endl<<"The sorted elements are: "<<endl;
	for(int i=0;i<no_of_numbers;i++)
		cout<<array[i]<<" ";
	cout<<endl<<"The no. of comaprision(s) is/are: "<<comparision;
	cout<<endl;
}

