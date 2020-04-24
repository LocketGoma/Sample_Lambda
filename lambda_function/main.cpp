#include <iostream>
#include <functional>
using namespace std;

int main() {
	// if a ==1 ? 1 : a-1;
	//람다 함수식 (재귀) : 팩토리얼
	function<unsigned long long(int)> fact;
	fact =
		[&fact](int n)-> unsigned long long {
		if (n <= 0) return 1;
		else
		{
			return (n * fact(n - 1));
		}
	};
	
	int input;
	cin >> input;

	//기본형 람다 (변수 리턴)
	auto addData = [](auto a, auto b) { return a + b };


	int ab = 3;
	[&](int abc){ std::cout << abc * abc << endl; }(ab);




	std::cout << fact(static_cast<int>(cin.get())-48) << endl;
	std::cout << fact(input) << endl;
	std::cout << fact(5) << endl;



	std::system("Pause");

	return 0;
}
template <typename T>
T addDataT(T a, T b) {
	return a + b;
}