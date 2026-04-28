#include <iostream>
using namespace std;



class Complex 
{
    public:
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void print() const
    {
        cout << real << " + " << imag << "i\n";
    }

    // 3. 멤버 함수, void, 참조 전달
    void add_member_void(const Complex& a, const Complex& b) 
    {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 4. 멤버 함수, return, 참조 전달
    Complex add_member_return(const Complex& b) const 
    {
        return Complex(real + b.real, imag + b.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(const Complex& b) const {
        return Complex(real + b.real, imag + b.imag);
    }
};

//1 일반 함수, void, 참조 전달
void add_global_void(const Complex& a, const Complex& b, Complex& result) 
{
result.real = a.real + b.real;
result.imag = a.imag + b.imag;
}

// 2. 일반 함수, return, 값 전달
Complex add_global_return(Complex a, Complex b) 
{
return Complex(a.real + b.real, a.imag + b.imag);
}





//- 종합 비교된 5가지 함수를 구현하고 검증
  //  - a = 1+2i, b = 3+4i, c = ?
int main()
{
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    cout << "a = ";
    a.print();

    cout << "b = ";
    b.print();

    cout << "\n1. 일반 함수, void, 참조 전달\n";
    add_global_void(a, b, c);
    cout << "c = ";
    c.print();

    cout << "\n2. 일반 함수, return, 값 전달\n";
    c = add_global_return(a, b);
    cout << "c = ";
    c.print();

    cout << "\n3. 멤버 함수, void, 참조 전달\n";
    c.add_member_void(a, b);
    cout << "c = ";
    c.print();

    cout << "\n4. 멤버 함수, return, 참조 전달\n";
    c = a.add_member_return(b);
    cout << "c = ";
    c.print();

    cout << "\n5. 연산자 오버로딩\n";
    c = a + b;
    cout << "c = ";
    c.print();

    return 0;
}