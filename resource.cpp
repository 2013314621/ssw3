#include <iostream>
#include <string>
#include "resource.h"
#include <fstream>

using namespace std;

string resource :: name_get(){
	return name;
}
void resource :: name_set(string s){
	name = s;
}
int resource :: condition_get(){
	return condition;
}
void resource :: condition_set(int i){
	condition = i;
}
void book :: return_day_set(string s){
	string year, month, day;
	int year_int, month_int, day_int, all_day;
	year = s[0];
	year = year + s[1];
	month = s[3];
	month = month + s[4];
	day = s[6];
	day = day + s[7];
	year_int = stoi(year);
	month_int = stoi(month);
	day_int = stoi(day);
	all_day = year_int*360 + month_int*30 + day_int + 13;
	year = to_string(all_day/360);
	if(year.length()==1) year = "0" + year;
	month = to_string((all_day%360)/30);
	if(month.length()==1) month = "0" + month;
	day = to_string((all_day%360)%30);
	if(day.length()==1) day = "0" + day;
	day_return = year + "/" + month + "/" + day;	
}
string book :: return_day_get(){
	return day_return;
}
string book :: borrow_member_get(){
	return member_borrow;
}
void book :: borrow_member_set(string s){
	member_borrow = s;
}
string book :: borrow_day_get(){
	return day_borrow;
}
void book :: borrow_day_set(string s){
	day_borrow = s;
}
book :: book(string s){
	name_set(s);
}

