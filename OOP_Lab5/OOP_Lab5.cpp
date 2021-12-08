#include <iostream>
#include <memory>
//#include "Figures.h";
#include "FiguresVirtual.h";



int main(){
	Figure* a = new Figure();
	Figure* b = new Line(10);
	Line* c = new Line();

	a->draw();
	b->draw();
	c->draw();
	std::cout << "\n";

	Line* d = dynamic_cast<Line*>(b);
	d->draw();
	d->length();

	delete(a);
	delete(b);
	delete(c);

}
