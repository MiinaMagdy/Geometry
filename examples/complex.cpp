#include <iostream>
#include <complex>

using namespace std;

int main() {
    complex<double> a(1, 2);
    complex<double> b(3, 4);
    complex<double> c = a + b; // 4 + 6i
    cout << c << endl; // (4, 6)
    cout << real(c) << endl; // 4
    cout << imag(c) << endl; // 6
    cout << abs(c) << endl; // 7.2111 = sqrt(4^2 + 6^2)
    cout << arg(c) << endl; // 0.876058 = atan(6/4)
    cout << conj(c) << endl; // 4 - 6i
    cout << norm(c) << endl; // 52 = 4^2 + 6^2 = abs(c)^2
    cout << polar(1.0, 1.0) << endl; // 0.540302 + 0.841471i
    cout << exp(c) << endl; // -4.82981 - 15.1367i
    return 0;
}
