#include <iostream>
#include<limits>
using namespace std;


int main() {
	
	/*long long int maxValue1 = LLONG_MAX;
	cout << "the maxValue of long long int is" << maxValue1 << endl;
	long int maxValue2 = LONG_MAX;
	cout << "the maxValue of  long int is" << maxValue2 << endl;
	long long int minValue1 = LLONG_MIN;
	cout << "the minValue of long long int is" << minValue1 << endl;
	long int minValue2 = LONG_MIN;
	cout << "the maxValue of  long int is" << minValue2 << endl;
	*/
	cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
	cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
	cout << "Maximum value for long int: " << std::numeric_limits<long int>::max() << '\n';
	cout << "Minimum value for int: " << std::numeric_limits<long int>::min() << '\n';
	





}
