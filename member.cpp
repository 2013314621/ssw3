#include <iostream>
#include <string>
#include "member.h"
using namespace std;

string member::name_get(){
	return name;
}
void member :: name_set(string s){
	name = s;
}
undergraduated :: undergraduated(){
	book_name = "";
	num_borrow = 0;
	restricted_day = "";
}
undergraduated :: undergraduated(string s){
	book_name = "";
	num_borrow = 0;
	restricted_day = "";
	name_set(s);
}
int undergraduated :: limit_get(){
	return num_borrow;
}
void undergraduated :: limit_set(int i){
	num_borrow = i;
}
int undergraduated :: ban_get(){
	return ban;
}
void undergraduated :: ban_set(int i){
	ban = i;
}
string undergraduated :: restricted_day_get(){
	return restricted_day;
}
void undergraduated :: restricted_day_set(string s){
	restricted_day = s;
}
string undergraduated :: book_name_get(){
	return book_name;
}
void undergraduated :: book_name_set(string s){
	book_name = s;
}
