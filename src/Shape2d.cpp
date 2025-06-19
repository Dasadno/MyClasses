#include "../hd/Shape2D.hpp"



Shape::Shape(int amountOfPoints) {
	shape_ = new Point2D[amountOfPoints];
	amountOfPoints_ = amountOfPoints;
}


Shape::~Shape() {
	delete[] shape_;
}

void Shape::Clear() {
	shape_ = NULL;
}

void Shape::AddNewPoint(Point2D point) {
	amountOfPoints_ += 1;
	Point2D* newShape = new Point2D[amountOfPoints_.ToInt()];
	for (int i = 0; i < amountOfPoints_.ToInt(); i++) {
		newShape[i] = shape_[i];
	}
	newShape[amountOfPoints_.ToInt() - 1] = point;
}

void Shape::RemoveDotAt(Integer index) {}
