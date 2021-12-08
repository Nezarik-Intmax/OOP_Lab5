#pragma once
#include <iostream>
#include <string>
class Figure{
public:
	Figure(){
		std::cout << "Figure constructor\n";
	}
	Figure(std::string classname){
		std::cout << "Figure constructor\n";
	}
	Figure(Figure* a){
		std::cout << "Figure(copy*) constructor\n";
	}
	Figure(Figure& a){
		std::cout << "Figure(copy&) constructor\n";
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
	virtual std::string classname(){
		return "Figure";
	}
	bool isA(std::string classname){
		return (classname==this->classname()) ? true : false;
	}
};
class Line: public Figure{
private:
	int len;
public:
	Line():len(0){
		std::cout << "Line constructor\n";
	}
	Line(int len):len(len){
		std::cout << "Line constructor\n";
	}
	Line(Line* a):len(a->getLength()){
		std::cout << "Line(copy) constructor\n";
	}
	Line(Line& a):len(a.getLength()){
		std::cout << "Line(copy) constructor\n";
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
	void length(){
		std::cout << "Length: " << len << "\n";
	}
	int getLength(){
		return len;
	}
	virtual std::string classname()override{
		return "Line";
	}
};