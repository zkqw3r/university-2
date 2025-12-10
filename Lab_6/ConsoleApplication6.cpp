#include <iostream>
#include "Logic.h"

using namespace std;

int main()
{
    float x, y, s, r, c;

    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    try {
        float res = Calculate(x, y, s, r, c);
        cout << "s = " << s << endl;
		cout << "r = " << r << endl;
		cout << "c = " << c << endl;
    }
    catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    system("pause");
    return 0;

}
