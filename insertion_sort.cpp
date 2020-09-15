//C++ program to implement insertion sort.
#include <iostream>
using namespace std;

int main(){
	int no_of_elements,swap=0,comparision=0;
	cout<<"Enter the number of elements: ";
	cin>>no_of_elements;
	int array[no_of_elements];
	cout<<"Enter the elements: ";
	for(int i=0;i<no_of_elements;i++)
		cin>>array[i];
	for(int i=1;i<no_of_elements;i++){
		int key=array[i];
		int j=i-1;
		if(array[j]<key)
			comparision++;
		while(j>=0&&array[j]>key){
			array[j+1]=array[j];
			j=j-1;
			swap++;
			comparision++;
		}
		array[j+1]=key;
	}
	cout<<"The sorted array is: "<<endl;
	for(int i=0;i<no_of_elements;i++)
		cout<<array[i]<<" ";
	cout<<endl<<"The number of comparisions made= "<<comparision;
	cout<<endl<<"The number of swapping made= "<<swap;
}
