#include <cstdio>
#include <clocale>

class Point {
	int x;
	int y;
public:
	Point() {
		this->x = 0;
		this->y = 0;
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
		printf("~Point()\n");
	}
};

class Point3D : public Point {
	int z;
public:
	Point3D() {
		this->z = 0;
	}
	void SetZ(int z) {
		this->z = z;
	}
	int GetZ() {
		return this->z;
	}
	~Point3D() {
		printf("~Point3D()\n");
	}
};

int main() {
	setlocale(LC_ALL, "");

	Point3D p3d;

	p3d.SetY(5);
	printf("Y: %i\n", p3d.GetY());

	return 0;
}