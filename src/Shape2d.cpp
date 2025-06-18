#include "../hd/Shape2D.hpp"



Shape2D::Shape2D(int amountOfPoints) {
	shape_ = new Point2D[amountOfPoints];
	amountOfPoints_ = amountOfPoints;
}


Shape2D::~Shape2D() {
	delete[] shape_;
}

void Shape2D::Clear() {
	shape_ = NULL;
}

void Shape2D::AddNewPoint(Point2D point) {
	amountOfPoints_ += 1;
	Point2D* newShape = new Point2D[amountOfPoints_.ToInt()];
	for (int i = 0; i < amountOfPoints_.ToInt(); i++) {
		newShape[i] = shape_[i];
	}
	newShape[amountOfPoints_.ToInt() - 1] = point;
}

void Shape2D::RemoveDotAt(Integer index) {}
