#include <iostream>

using namespace std;

class Vector
{
    public:
        float x;
        float y;
        Vector(float x, float y)
        {
            this->x = x;
            this->y = y;
        }
        
};


Vector & operator + (const Vector &v1, const Vector &v2)
{
    return *(new Vector(v1.x + v2.x, v1.y +v2.y));
}

Vector & operator - (const Vector &v1, const Vector &v2)
{
    return *(new Vector(v1.x - v2.x, v1.y - v2.y));
}

int main()
{
    Vector vector1(4,5);
    Vector vector2(7,6);
    Vector suma = vector1 + vector2;
    Vector resta = vector1 - vector2;

    cout << "Suma de 2 vectores: (" << suma.x << " , "<< suma.y <<") "<< endl;
    cout << "Resta de 2 vectores: (" << resta.x << " , "<< resta.y <<") "<< endl;
    return 0;
}
