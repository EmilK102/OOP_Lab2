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
		printf("Point(%i,%i)\n", x,y);
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
	virtual ~Point() {
		printf("~Point()\n");
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
		printf("Point3D(%i)\n",z);
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
	virtual ~Point3D(){
		printf("~Point3D()\n");
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
		printf("Vector(%i,%i,%i,%i)\n", x1, x2, y1, y2);
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
		printf("Статическое создание объектов\n");
		printf("___________________________\n");
		Point p1;
		Point p2 = Point(1, 2);
		Point p3 = Point(p2);
	}
	{
		printf("___________________________\n");
		printf("Динамическое создание объектов\n");
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
		printf("Геттер динамического объекта класса\n");
		printf("___________________________\n");
		Point *p = new Point(2, 3);
		printf("X:%i\n", p->GetX());
		p->Reset();

		delete p;
	}
	{
		printf("___________________________\n");
		printf("Помещение объекта в свой тип\n");
		printf("___________________________\n");
		Point3D *p = new Point3D(1, 2, 3);

		delete p;
	}
	{
		printf("___________________________\n");
		printf("Помещение объекта в родительский тип\n");
		printf("___________________________\n");
		Point *p = new Point3D(1, 2, 3);

		delete p;
	}
	{
		printf("___________________________\n");
		printf("Создание вектора\n");
		printf("___________________________\n");
		Vector *v1 = new Vector;
		printf("___________________________\n");
		printf("Создание вектора c параметрами\n");
		printf("___________________________\n");
		Vector* v2 = new Vector(1,2,1,3);
		printf("___________________________\n");
		printf("Создание вектора конструктором копирования\n");
		printf("___________________________\n");
		Vector* v3 = new Vector(*v2);
		printf("___________________________\n");
		printf("Удаление векторов\n");
		printf("___________________________\n");
		delete v1;
		delete v2;
		delete v3;
	}

	return 0;
}