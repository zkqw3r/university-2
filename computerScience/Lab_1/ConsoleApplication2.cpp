#include <iostream>

using namespace std;

int main()
{
    float x, y, s, c, r;

    cout << "x = " ;
    cin >> x;
	cout << "y = ";
	cin >> y;
    r = sqrt(x * x + y * y)*sin(x);
    s = exp(x / y);
	cout << "r = " << r << endl;
	cout << "s = " << s << endl;
    c = max(r, s);
	cout << "c = " << c << endl;

	system("pause");
    return 0;
}