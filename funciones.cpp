#include <iostream>
#include <vector>

using namespace std;



int main(){
	vector <int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<v[i]<<endl;
	}

	cout<<"begin: "<<*v.begin()<<endl;
    cout<<"end: "<<*(v.end() - 1)<<endl;
	cout<<"size: "<<v.size()<<endl;
	cout<<"empty: "<<v.empty()<<endl;
	cout<<"capacity: "<<v.capacity()<<endl;
	cout<<"operator[]: "<<v[5]<<endl;
	cout<<"at(i): "<<v.at(5)<<endl;
	cout<<"front: "<<v.front()<<endl;
	cout<<"back: "<<v.back()<<endl;
	v.push_back(10);
	v.pop_back();
	v.insert(v.begin() + 5, 10);
	v.erase(v.begin() + 2);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout<<"find: "<<*find(v.begin(), v.end(), 5)<<endl;
	cout<<"count: "<<count(v.begin(), v.end(), 5)<<endl;
	cout<<"sort: "<<"sort(v.begin(), v.end())"<< endl;
	cout<<"reverse: "<<"reverse(v.begin(), v.end())"<< endl;
	cout<<"swap: "<<"swap(v1, v2)"<< endl;
	swap(v[0], v[1]);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout<<"clear: "<<"v.clear()"<< endl;
	return 0;
}