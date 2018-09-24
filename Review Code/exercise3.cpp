#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

template<class T,int N>

class Point{
public:
	vector<T> ele;
	//vector<int> ir;

	Point(T *arr){

		for(int i=0;i<3;i++){	
			ele.push_back(arr[i]);

		}
	}
};

template<class T,int N>

double euclideanDistance(Point<T,N> const &p1,Point<T,N> const &p2){
	double dist=0;

	for(int i=0;i<p1.ele.size();i++){
		dist+=((p2.ele[i]-p1.ele[i])*(p2.ele[i] - p1.ele[i]));
	}
	
	return sqrt(dist);
}

int main(){
	int dim;
	float dist;
	
	int threed = 3;
	//cout<<"Enter the dimension: ";
	//in>>dim;
	double arr1[dim];
	cout<<"\nEnter the values for each dimension of point 1: \n";
	for(int i=0;i<threed;i++)
	    cin>>arr1[i];
	    
	double arr2[dim];
	cout<<"\nEnter the values for each dimension of point 2: \n";
	for(int i=0;i<threed;i++)
	    cin>>arr2[i];
	    
	Point<double,3> p1(arr1);
	Point<double,3> p2(arr2);
	dist=euclideanDistance(p1,p2);
	cout<<"\nEuclidean distance: "<< dist << endl;
	
	//Second part of part 3 of the exercise
	
	int twod = 2;
	int arr3[dim];
	cout<<"\nEnter the values for each dimension of point 1: \n";
	for(int i=0;i<twod;i++)
	    cin>>arr3[i];
	    
	int arr4[dim];
	cout<<"\nEnter the values for each dimension of point 2: \n";
	for(int i=0;i<twod;i++)
	    cin>>arr4[i];
	    
	Point<int,2> p3(arr3);
	Point<int,2> p4(arr4);
	dist=euclideanDistance(p3,p4);
	cout<<"\nEuclidean distance: "<< dist << endl;
	
	
	
}