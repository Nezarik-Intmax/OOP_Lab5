#pragma once
#include <iostream>
class Figure{
public:
	Figure(){
		std::cout << "Figure constructor\n";
	}
	Figure(Figure* a){
		std::cout << "Figure(copy) constructor\n";
	}
	~Figure(){
		std::cout << "Figure destructor\n";
	}
	void endDraw(){
		std::cout << " has been drawn\n";
	}
	void draw(){
		std::cout << "Figure";
		endDraw();
	}
};
class Line: public Figure{
public:
	Line(){
		std::cout << "Line constructor\n";
	}
	~Line(){
		std::cout << "Line destructor\n";
	}
	void endDraw(){
		std::cout << " ------ has been drawn\n";
	}
	void draw(){
		std::cout << "Line";
		endDraw();
	}
};