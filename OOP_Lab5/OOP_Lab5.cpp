#include <iostream>
#include <memory>
#include "Figures.h";
//#include "FiguresVirtual.h";

Figure ReturnFigure1(){
	Figure a;
	return a;
}
Figure* ReturnFigure2(){
	Figure* a = new Figure();
	return a;
}
Figure& ReturnFigure3(){
	Figure *temp = new Figure();
	return *temp;
}
std::unique_ptr<Figure> ReturnFigureUnique(std::unique_ptr<Figure> a){
	return a;							// а передается из функции если результат функции не записывается в переменную, то память освобождается
}
std::shared_ptr<Figure> ReturnFigureShared(std::shared_ptr<Figure> a){
	return a;
}

void func1(Figure obj){
	std::cout << "func1:\n";
	std::cout << "obj: " << obj.classname() << "\n";
	obj.draw();
	if(obj.isA("Line")){
		dynamic_cast<Line*>(&obj)->length();
	}
};
void func2(Figure* obj){
	std::cout << "func2:\n";
	std::cout << "obj: " << obj->classname() << "\n";
	obj->draw();
	if(obj->isA("Line")){
		dynamic_cast<Line*>(obj)->length();
	}
};
void func3(Figure& obj){
	std::cout << "func3:\n";
	std::cout << "obj: " << obj.classname() << "\n";
	obj.draw();
	if(obj.isA("Line")){
		dynamic_cast<Line*>(&obj)->length();
	}
};


int main(){
	
	Figure* a = new Figure();
	Figure* b = new Line(10);
	Line* c = new Line(20);
	std::cout << "\n";

	func1(a);
	std::cout << "\n";
	func2(a);
	std::cout << "\n";
	func3(*a);
	std::cout << "\n";
	std::cout << "\n";
	func1(b);
	std::cout << "\n";
	func2(b);
	std::cout << "\n";
	func3(*b);
	std::cout << "\n";
	std::cout << "\n";
	func1(c);
	std::cout << "\n";
	func2(c);
	std::cout << "\n";
	func3(*c);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	/*
	a->draw();
	b->draw();
	c->draw();
	std::cout << "\n";

	std::cout << a->classname() << "\n";
	std::cout << b->classname() << "\n";
	std::cout << c->classname() << "\n";
	std::cout << "\n";
	//*

	dynamic_cast<Line*>(b)->draw();
	dynamic_cast<Line*>(b)->length();
	dynamic_cast<Line*>(b)->classname();
	std::cout << "\n";

	Line* d = dynamic_cast<Line*>(b);
	d->draw();
	d->length();
	d->classname();
	std::cout << "\n";

	if(a->isA("Line")){
		static_cast<Line*>(a)->draw();
		static_cast<Line*>(a)->length();
		static_cast<Line*>(a)->classname();
	}
	if(b->isA("Line")){
		static_cast<Line*>(b)->draw();
		static_cast<Line*>(b)->length();
		static_cast<Line*>(b)->classname();
	}
	if(c->isA("Line")){
		static_cast<Line*>(c)->draw();
		static_cast<Line*>(c)->length();
		static_cast<Line*>(c)->classname();
	}
	std::cout << "\n";

	delete(a);
	delete(b);
	delete(c);
	d = nullptr;
	std::cout << "\n\n\n";
	//*/
	Figure a = (Figure&)ReturnFigure1();
	std::cout << "\n\n";
	Figure* b = ReturnFigure2();
	std::cout << "\n\n";
	Figure& c = ReturnFigure3();
	std::cout << "\n\n";

	delete(b);

	/*
	{
		std::unique_ptr<Figure> e = std::make_unique<Figure>();
		std::unique_ptr<Figure> f = std::move(e);					// f = e, e = nullptr;
	}
	std::cout << "\n\n";
	{
		std::unique_ptr<Figure> g = std::make_unique<Figure>();
		std::unique_ptr<Figure> h = ReturnFigureUnique(std::move(g));	// h = g, g = nullptr;
		ReturnFigureUnique(std::move(h));								// delete(h)
	}
	std::cout << "\n\n";
	{
		std::shared_ptr<Line> i = std::make_shared<Line>(10);	
		{
			std::shared_ptr<Line> j(i);			//i = j
			j->length();						// 10
			ReturnFigureShared(i);				
		}
		i->length();							// 10
	}											// delete()
	//*/
}
