#include <iostream>
#include <functional>
#include <time.h>
#include <chrono>
using namespace std;

unsigned long long FuncFor(int input) {
	unsigned long long answer = 1;
	for (int i = 1; i <= input; i++) {
		answer *= i;
	}
	return answer;
}

unsigned long long Funcfact(int input) {
	if (input <= 0) return 1;
	else return (input * Funcfact(input - 1));
}

inline unsigned long long FuncInline(int input) {
	if (input <= 0) return 1;
	else return (input * Funcfact(input - 1));
}

unsigned long long Funclambda(int input) {
	function<unsigned long long(int)> fact;
	fact =
		[&fact](int n)-> unsigned long long {
		if (n <= 0) return 1;
		else
		{
			return (n * fact(n - 1));
		}
	};
	return fact(input);
}


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

	std::chrono::system_clock::time_point startTime;
	std::chrono::system_clock::time_point endTime;

	//1 : 기본 for문 방식
	startTime = std::chrono::system_clock::now();
	cout << "For :" << FuncFor(input) << endl;
	endTime = std::chrono::system_clock::now();
	cout << "Time :: " << (endTime - startTime).count() << endl;

	//2 : 일반 재귀 함수
	startTime = std::chrono::system_clock::now();
	cout << "Recurv : " << Funcfact(input) << endl;
	endTime = std::chrono::system_clock::now();
	cout << "Time :: " << (endTime - startTime).count() << endl;

	//3 : 인라인 재귀 함수
	startTime = std::chrono::system_clock::now();
	cout << "inline : " << FuncInline(input) << endl;
	endTime = std::chrono::system_clock::now();
	cout << "Time :: " << (endTime - startTime).count() << endl;

	//4 : 람다 함수
	startTime = std::chrono::system_clock::now();
	cout << "lambda :" << fact(input) << endl;
	endTime = std::chrono::system_clock::now();
	cout << "Time :: " << (endTime - startTime).count() << endl;

	//5 : 외부 람다 함수
	startTime = std::chrono::system_clock::now();
	cout << "Outto lambda :" << Funclambda(input) << endl;
	endTime = std::chrono::system_clock::now();
	cout << "Time :: " << (endTime - startTime).count() << endl;

	std::system("Pause");

	return 0;
}
