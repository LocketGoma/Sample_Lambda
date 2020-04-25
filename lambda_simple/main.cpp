#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int input;
	cin >> input;

	float a, b;
	cin >> a >> b;

	auto AddData = [=](auto A, auto B) {return A + B; }(a, b);



	cout << AddData << endl;

	//https://hwan-shell.tistory.com/88
	int total_elements = 1;
	vector<int> cardinal;

	cardinal.push_back(1);
	cardinal.push_back(2);
	cardinal.push_back(4);
	cardinal.push_back(8);

	for_each(cardinal.begin(), cardinal.end(), [&](int i) { total_elements *= i; });

	cout << "total elements : " << total_elements << endl;


	vector<int> multipleData;
	vector<int>::iterator iter = multipleData.begin();
	while ([&](vector<int>, int i = 0) { cout << i << endl; multipleData.push_back(i++); return (i < input); }(multipleData, input))
	
	//오히려 더 거추장스러워진 모습인데.. 아무튼 한줄임.

	for_each(multipleData.begin(), multipleData.end(), [](auto& n) {cout << n << endl; });
	


	std::system("Pause");

	return 0;
}
