#include "Fixed.hpp"
#include "Point.hpp"

Fixed sign (Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

    return !(has_neg && has_pos);
}

int main()
{
	Point A(0.0f, 0.0f);	
	Point B(0.0f, 1.0f);	
	Point C(1.0f, 0.0f);	
	Point D(0.5f, 0.5f);	

	A.show("A");
	B.show("B");
	C.show("C");
	D.show("D");

	if (bsp(A, B, C, D))
		std::cout << "Point D is inside triangle" << std::endl;
	else
		std::cout << "Point D is NOT inside triangle" << std::endl;
	
	std::cout << std::endl;	

	Point E(0.0f, 0.0f);	
	Point F(0.0f, 1.0f);	
	Point G(1.0f, 0.0f);	
	Point H(1.5f, 0.5f);	

	E.show("E");
	F.show("F");
	G.show("G");
	H.show("H");

	if (bsp(E, F, G, H))
		std::cout << "Point H is inside triangle" << std::endl;
	else
		std::cout << "Point H is NOT inside triangle" << std::endl;

	std::cout << std::endl;	

	Point I(0.0f, 0.0f);	
	Point J(0.0f, 1.0f);	
	Point K(1.0f, 0.0f);	
	Point L(0.0f, 0.0f);	

	I.show("I");
	J.show("J");
	K.show("K");
	L.show("L");

	if (bsp(I, J, K, L))
		std::cout << "Point L is inside triangle" << std::endl;
	else
		std::cout << "Point L is NOT inside triangle" << std::endl;

	std::cout << std::endl;	

	Point M(0.2f, 0.2f);	

	I.show("A");
	J.show("B");
	K.show("C");
	M.show("M");

	if (bsp(A, B, C, M))
		std::cout << "Point M is inside triangle" << std::endl;
	else
		std::cout << "Point M is NOT inside triangle" << std::endl;

	return (0);
}
