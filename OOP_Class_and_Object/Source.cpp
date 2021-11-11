#include <cstdio>
#include <clocale>

class Point {
protected:
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
	void Reset();
	~Point() {
		printf("~Point(%i,%i)\n",x,y);
	}
};

void Point::Reset() {
	this->x = 0;
	this->y = 0;
}

class Point3D : public Point {
private:
	int z;
public:
	Point3D() : Point(){
		this->z = 0;
		printf("Point3D()\n");
	}
	Point3D(int x, int y, int z) : Point(x,y){
		this->z = z;
		printf("Point3D(int z)\n");
	}
	Point3D(const Point3D &p){
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		printf("Point3D(const Point3D &p)\n");
	}
	void SetZ(int z) {
		this->z = z;
	}
	int GetZ() {
		return this->z;
	}
	~Point3D(){
		printf("~Point3D(%i,%i,%i)\n",x,y,z);
	}
};

class Vector {
private:
	Point *p1;
	Point *p2;
public:
	Vector() {
		p1 = new Point;
		p2 = new Point;
		printf("Vector()\n");
	}
	Vector(int x1,int x2,int y1, int y2) {
		p1 = new Point(x1,y1);
		p2 = new Point(x2,y2);
		printf("Vector(int x1,int x2,int y1, int y2)\n");
	}
	Vector(const Vector &v) {
		p1 = new Point(*(v.p1));
		p2 = new Point(*(v.p2));
		printf("Vector(const Vector &v)\n");
	}
	~Vector() {
		delete p1;
		delete p2;
		printf("~Vector()\n");
	}
};

int main() {
	setlocale(LC_ALL, "");

	{
		printf("___________________________\n");
		Point p1;
		Point p2 = Point(1, 2);
		Point p3 = Point(p2);
	}
	{
		printf("___________________________\n");
		Point *p1 = new Point;
		Point *p2 = new Point(1, 2);
		Point *p3 = new Point(*p2);

		delete p1;
		delete p2;
		delete p3;
	}
	{
		printf("___________________________\n");
		Point *p = new Point(2, 3);
		printf("X:%i\n", p->GetX());
		p->Reset();

		delete p;
	}
	{
		printf("___________________________\n");
		Point3D *p = new Point3D(1, 2, 3);

		delete p;
	}
	{
		printf("___________________________\n");
		Point *p = new Point3D(1, 2, 3);

		delete p;
	}
	{
		printf("___________________________\n");
		Vector *v1 = new Vector;
		Vector* v2 = new Vector(1,2,1,3);
		Vector* v3 = new Vector(*v2);

		delete v1;
		delete v2;
		delete v3;
	}

	return 0;
}