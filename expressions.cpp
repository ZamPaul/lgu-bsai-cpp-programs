#include <iostream>
#include <math.h>
using namespace std;

// Question 1:
// int main()
// {
//     float R;
//     float x, y;
//     cout << "Enter coefficients x, y:c ";
//     cin >> x >> y;

//     R = (((x + y) * (x + y)) / (x - y)) + (sqrt(x * y));

//     cout << "Result is" << R;

//     return 0;
// }

// Question 2:
// int main()
// {
//     float V;
//     float m, n, p, q, r, s;
//     cout << "Enter coefficients m, n, p, q: ";
//     cin >> m >> n >> p >> q;

//     cout << "Enter coefficients x and y: ";
//     cin >> r >> s;

//     V = ((m * n) / (p + q)) - (r / s);

//     cout << "Result is: " << V;

//     return 0;
// }

// Question 3
// int main()
// {
//     float A;
//     float a, b;

//     cout << "Enter coefficients a and b: ";
//     cin >> a >> b;

//     A = ((a + b) * (a + b) * (a + b)) / (a * a + b * b);

//     cout << "Result is: " << A;

//     return 0;
// }

// Question 4
// int main()
// {
//     float Z;
//     float p, q, r, s, l, u;

//     cout << "Enter coefficients p, q, r, s, l, u: ";
//     cin >> p >> q >> r >> s >> l >> u;

//     Z = ((p + q) * (r - s)) / (l + u);

//     cout << "Result is: " << Z;

//     return 0;
// }

// Question 5
int main()
{
    float distance;
    int x1, x2, y1, y2;

    cout << "Enter coefficients x1 and x2: ";
    cin >> x1 >> x2;

    cout << "Enter coefficients y1 and y2: ";
    cin >> y1 >> y2;

    distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    cout << "Distance is: " << distance;

    return 0;
}