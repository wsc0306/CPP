#include <iostream>

using namespace std;

class Point
{
    protected:
        int x, y;


    public:
        Point(int xx, int yy) : x(xx), y(yy) { }

        void draw()
        {
            cout << x << ", " << y << "에 점을 그려라.\n";
        }
};

class Rectangle : public Point
{
    private:
    int width, height;

    public:
    Rectangle(int xx, int yy, int w, int h)
    : Point(xx, yy), width(w), height(h) { }

    void draw()
    {
        cout << x << ", " << y << "에 가로 " << width
             << ", 세로 " << height << "인 사각형을 그려라.\n";
    }
};

int main()
{
    Rectangle r(2, 3, 100, 200);
    r.draw();

    return 0;
}

// 4번 문제
// protected -> private
// Rectangle 클래스에서 x, y에 직접 접근할 수 없다. (오류 발생)
// private는 자기 클래스인 Point 내부에서만 사용 가능
// 상속받은 클래스에서 사용 X