/* Program for implementing stack using queue*/
#include <bits/stdc++.h> 
using namespace std; 
class Stackqueue
{ 
	queue<int> q1, q2; 
	int currsize;
	public: 
	Stack() 
	{ 
		currsize = 0; 
	}
	void pop() 
	{ 
		if (q1.empty()) 
			return;
		while (q1.size() != 1) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 
		q1.pop(); 
		currsize--; 
		queue<int> q = q1; 
		q1 = q2; 
		q2 = q; 
	} 
	void push(int x) 
	{ 
		q1.push(x); 
		currsize++; 
	} 
	int top() 
	{ 
		if (q1.empty()) 
			return -1; 
		while (q1.size() != 1) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 
		int temp = q1.front(); 
		q1.pop(); 
		q2.push(temp);  
		queue<int> q = q1; 
		q1 = q2; 
		q2 = q; 
		return temp; 
	}
	int size() 
	{ 
		return currsize; 
	} 
}; 
int main() 
{ 
	Stackqueue s; 
	int num=10;
	int arr[10];
    
	cout<<"Enter 10 elment to push into stack : \n";
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
		s.push(arr[i]);
	} 
	cout << "current size: " << s.size()<< endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop();
	cout << "current size: " << s.size()	<< endl; 
	return 0; 
} 