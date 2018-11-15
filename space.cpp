#include <iostream>
#include <string>
#include "space.h"
using namespace std;
space::space(){
	time = 0;
	name = "";
	condition = 0;
}
studyroom::studyroom(){
	room_num = 0;
}
seat::seat(){
	floor = 0;
}
int space::time_get(){
	return time;
}
void space::time_set(string s, int i){
	int hr;
	int min;
	string hr_s;
	string min_s;
	hr_s = s[11];
	hr = stoi(hr_s);
	min_s = s[12];
	min = stoi(min_s);
	time = hr + min + i;
}

string space::name_get(){
	return name;
}
void space::name_set(string s){
	name = s;
}

int space::condition_get(){
	return condition;
}
void space::condition_set(int i){
	condition = i;
}

int studyroom::room_num_get(){
	return room_num;
}
void studyroom::room_num_set(int i){
	room_num = i;
}
int seat::floor_get(){
	return floor;
}
void seat::floor_set(int i){
	floor = i;
}

