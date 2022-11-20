// cpp program for queue implementation 
// Example of push() and pop()
#include <iostream>
#include <queue>
using namespace std;

//function to print the queue 
void printQueue(queue<int> q)
{
	// printing content of queue
	while (!q.empty()) {
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
}

//Main finction
int main()
{
	// declaring an empty queue
	queue<int> Q;
	
	//inserting elements 
	Q.push(10);
	Q.push(20);
	Q.push(30);
	Q.push(40);
	Q.push(50);
	cout<<"Queue elements after inserting elements:"<<endl;
	printQueue(Q);
	cout<<Q.front()<<"\n";
	//removing elements
	Q.pop();
	Q.pop();
	cout<<"Queue elements after removing elements:"<<endl;
	printQueue(Q);
	
	return 0;
}
