#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point2D.hpp"


class Shape {
public:
	Shape(int amountOfPoints);

	~Shape();


	void Clear();

	void AddNewPoint(Point2D point);

	void RemoveDotAt(Integer index);

private:
	Point2D* shape_;
	Integer amountOfPoints_;

};

#endif // !SHAPE_HPP
