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
    cout << arg(c) << endl; // 0.876058 = atan2(6/4) | arg(a) = atan2(a.imag() / a.real())
    cout << conj(c) << endl; // 4 - 6i | conj(a) = a.real() - a.imag() * i
    cout << norm(c) << endl; // 52 = 4^2 + 6^2 = abs(c)^2 | norm(a) = a * conj(a) = a.real() * a.real() + a.imag() * a.imag()
    cout << abs(c) << endl; // 7.2111 = sqrt(4^2 + 6^2) | abs(a) = sqrt(norm(a))
    cout << polar(1.0, 1.0) << endl; // 0.540302 + 0.841471i | polar(r, theta) = r * exp(i * theta)
    cout << exp(c) << endl; // -4.82981 - 15.1367i | exp(a) = e^a.real() * exp(i * a.imag())
    return 0;
}
