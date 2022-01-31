#pragma once
#include <iostream>
#include <string>
class Figure{
public:
	Figure(){
		std::cout << "Figure constructor\n";
	}
	Figure(Figure* a){
		std::cout << "Figure(copy) constructor\n";
	}
	Figure(Figure& a){
		std::cout << "Figure(copy) constructor\n";
	}
	virtual ~Figure(){
		std::cout << "Figure destructor\n";
	}
	virtual void endDraw(){
		std::cout << " has been drawn\n";
	}
	virtual void draw(){
		std::cout << "Figure";
		endDraw();
	}
	virtual std::string classname(){
		return "Figure";
	}
	virtual bool isA(std::string classname){
		return (classname == "Figure") ? true : false;
	}
};
class Line: public Figure{
//protected:
public:
	int len;
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
	virtual ~Line() override{
		std::cout << "Line destructor\n";
	}
	virtual void endDraw() override{
		std::cout << " ------ has been drawn\n";
	}
	virtual void draw() override{
		std::cout << "Line";
		endDraw();
	}
	void length(){
		std::cout << "Length: " << len << "\n";
	}
	int getLength(){
		return len;
	}
	virtual std::string classname() override{
		return "Line";
	}
	virtual bool isA(std::string classname) override{
		return (classname == "Line") || Figure::isA(classname);
	}
};
class Sector: public Line{
public:
	Sector(){
		std::cout << "Line constructor\n";
	}
	Sector(int len):Line(len){
		std::cout << "Line constructor\n";
	}
	Sector(Sector* a){
		len = a->getLength();
		std::cout << "Line(copy) constructor\n";
	}
	Sector(Sector& a){
		std::cout << "Line(copy) constructor\n";
	}
	virtual ~Sector() override{
		std::cout << "Line destructor\n";
	}
	virtual void endDraw() override{
		std::cout << " ------ has been drawn\n";
	}
	virtual void draw() override{
		std::cout << "Line";
		endDraw();
	}
	void length(){
		std::cout << "Length: " << len << "\n";
	}
	int getLength(){
		return len;
	}
	virtual std::string classname() override{
		return "Sector";
	}
	virtual bool isA(std::string classname) override{
		return (classname == "Sector") || Line::isA(classname);
	}
};