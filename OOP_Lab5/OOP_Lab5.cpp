#include <iostream>
#include <memory>
#include "Figures.h";
//#include "FiguresVirtual.h";

Figure ReturnFigure(Figure a){			// Сздается а
	return a;							// Создается копия а, а - удаляется.
}
Figure* ReturnFigure(Figure* a){		
	return a;							// переменная указатель "а" удаляется, но выделенная память остается и передается из функции
}
std::unique_ptr<Figure> ReturnFigureUnique(std::unique_ptr<Figure> a){
	return a;							// а передается из функции если результат функции не записывается в переменную, то память освобождается
}

int main(){
	Figure* a = new Figure();
	Figure* b = new Line(10);
	Line* c = new Line();

	a->draw();
	b->draw();
	c->draw();
	std::cout << "\n";

	/*
	Line* d = dynamic_cast<Line*>(b);
	d->draw();
	d->length();
	//*/

	delete(a);
	delete(b);
	delete(c);
	std::cout << "\n\n\n";

	//*
	{
		std::unique_ptr<Figure> e = std::make_unique<Figure>();
		std::unique_ptr<Figure> f = std::move(e);					// f = e, e = nullptr;
	}																// delete(f);
	//*/
	//*
	{
		std::unique_ptr<Figure> g = std::make_unique<Figure>();
		std::unique_ptr<Figure> h = ReturnFigureUnique(std::move(g));	// h = g, g = nullptr;
		ReturnFigureUnique(std::move(h));								// delete(h)
	}
	//*/
	//*
	{
		std::shared_ptr<Line> i(new Line(10));	
		{
			std::shared_ptr<Line> j(i);			//i = j
			j->length();						// 10
		}
		i->length();							// 10
	}											// delete()
	//*/
}
