#include <cstdio>
#include <clocale>

class Point {
private:
	int x;
	int y;
public:
	Point() {
		this->x = 0;
		this->y = 0;
		printf("Point()\n");
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
		printf("Point(int x,int y)\n");
	}
	Point(const Point &p) {
		this->x = p.x;
		this->y = p.y;
		printf("Point(const Point &p)\n");
	}
	void SetX(int x) {
		this->x = x;
	}
	void SetY(int y) {
		this->y = y;
	}
	int GetX() {
		return this->x;
	}
	int GetY() {
		return this->y;
	}
	~Point() {
		printf("~Point(%i,%i)\n",x,y);
	}
};

class Point3D : public Point {
private:
	int z;
public:
	Point3D() {
		this->z = 0;
		printf("Point3D()\n");
	}
	Point3D(int z) {
		this->z = z;
		printf("Point3D(int z)\n");
	}
	Point3D(const Point3D &p) {
		this->z = p.z;
		printf("Point3D(const Point3D &p)\n");
	}
	void SetZ(int z) {
		this->z = z;
	}
	int GetZ() {
		return this->z;
	}
	~Point3D() {
		printf("~Point3D(x,y,%i)\n",z);
	}
};

int main() {
	setlocale(LC_ALL, "");

	{
		Point p1;
		Point p2 = Point(1, 2);
		Point p3 = Point(p2);
	}
	{
		Point *p1 = new Point();
		Point *p2 = new Point(1, 2);
		Point *p3 = new Point(*p2);

		delete p1;
		delete p2;
		delete p3;
	}


	return 0;
}