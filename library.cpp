#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "library.h"
using namespace std;
library::library(){
	for(int i = 0;i < 10;i++){
		studyroom temp;
		temp.room_num_set(i+1);
		studyroom_list.push_back(temp);
	}
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 50;j++){
			seat temp;
			temp.floor_set(i+1);
			seat_list.push_back(temp);
		}
	}
	input_get();
}
int library :: daytoint_r(string s){
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
	all_day = year_int*360 + month_int*30 + day_int;
	return all_day;
}
int library :: daytoint_s(string s){
	string year, month, day, hr;
	int year_int, month_int, day_int, hr_int, all_day;
	year = year + s[2];
	year = year + s[3];
	month = s[5];
	month = month + s[6];
	day = s[8];
	day = day + s[9];
	hr = s[11];
	hr = hr + s[12];
	year_int = stoi(year);
	month_int = stoi(month);
	day_int = stoi(day);
	all_day = year_int*360 + month_int*30 + day_int;
	return all_day;
}
void library::data_get(){
	ifstream in_1;
	in_1.open("resource.dat");
	string temp;
	in_1 >> temp;
	in_1 >> temp;
	int i = 0;
	while(in_1 >> temp){
		in_1 >> temp;
		book book_temp(temp);
		b_list.push_back(book_temp);	
	}
	in_1.close();
	
}
void library::input_get(){
	ifstream input_space;
	ifstream input_resource;
	string date_s;
	string space_t_s;
	string space_n_s;
	string op_s;
	string mem_t_s;
	string mem_n_s;
	string num_mem_s;
	string time_s;
	string date_r;
	string resource_t_r;
	string resource_n_r;
	string op_r;
	string mem_t_r;
	string mem_n_r;
	int count = 1;
	int all_day_r;
	int all_day_s;
	int flag_r;
	int flag_s;
	string temp;
	input_resource.open("input.dat");
	input_space.open("space.dat");
	for(int i = 0;i < 6;i++){
		input_resource >> temp;
	}
	for(int i = 0;i < 8;i++){
		input_space >> temp;
	}
	while(1){
			flag_r = 0;
			flag_s = 0;
		if(input_resource >> date_r){
			input_resource >> resource_t_r >> resource_n_r >> op_r >> mem_t_r >> mem_n_r;
			flag_r = 1;
		}
		if(input_space >> date_s){
			input_space >> space_t_s >> space_n_s >> op_s >> mem_t_s >> mem_n_s;
			if(op_s == "B"){
				input_space >> num_mem_s >> time_s;
			}
			flag_s = 1;
		}
		if((flag_r == 1) && (flag_s == 1))
		{
			all_day_r = daytoint_r(date_r);
			all_day_s = daytoint_s(date_s);
			if(all_day_r > all_day_s){
				cout << "space faster" << endl;
				//process_s(date_s,space_t_s,space_n_s,op_s,mem_t_s,mem_n_s,num_mem_s,time_s);
				//process_r(date_r,resource_t_r,resource_n_r,op_r,mem_t_r,mem_n_r);
			}
			else{
				cout << "resource faster" << endl;
				//process_r(date_r,resource_t_r,resource_n_r,op_r,mem_t_r,mem_n_r);
				//process_s(date_s,space_t_s,space_n_s,op_s,mem_t_s,mem_n_s,num_mem_s,time_s);
			}
		}
		else if((flag_r == 1) && (flag_s == 0)){
			//process_r(date_r,resource_t_r,resource_n_r,op_r,mem_t_r,mem_n_r);
			cout << "resource" << endl;
		}
		else if((flag_r == 0) && (flag_s == 1)){
			cout << "space" << endl;
			//process_s(date_s,space_t_s,space_n_s,op_s,mem_t_s,mem_n_s,num_mem_s,time_s);
		}
		else break;
	}
}
void library::process_r(string date_r, string resource_t_r, string resource_n_r, string op_r, string mem_t_r, string mem_n_r){
	for(auto a:)
}
void library::process_s(string date_s, string space_t_s, string space_n_s, string op_s, string mem_t_s, string mem_n_s, string num_mem_s, string time_s){
	int now_hr_int;
	string now_hr
	int flag = 0;
	int return_time[150];
	if(space_t_s == "StudyRoom"){
		if(stoi(space_n_s) > 10) return 8;
	}
	else if(space_t_s == "Seat"){
		if(stoi(space_n_s) > 3) return 8;
	}
	if(space_t_s == "StudyRoom"){
		now_hr = date_s[11];
		now_hr = now_hr + date_s[12];
		now_hr_int = stoi(now_hr);
		if((now_hr_int > 18) || (now_hr_int < 9)) return 91;
	}
	else if(space_t_s == "Seat"){
		now_hr = date_s[11];
		now_hr = now_hr + date_s[12];
		now_hr_int = stoi(now_hr);
		if(space_n_s == "2"){
			if((now_hr_int < 9) || (now_hr_int > 21)) return 92;
		}
		else if(space_n_s == "3"){
			if((now_hr_int > 18) || (now_hr_int < 9)) return 91;
		}
	}
	if(op_s != "B"){
		if(space_t_s == "StudyRoom"){
			for(auto a: studyroom_list){
				if(a.room_num_get() == stoi(space_n_s)){
					if(a.name_get() != mem_n_s){
						return 10;
					}
				}
			}
		}
		else if(space_t_s == "Seat"){
			for(auto a: seat_list){
				if(a.floor_get() == space_n_s){
					if(a.name_get() != mem_n_s) return 10;
				}
			}
		}
	}
	else if(op_s == "B"){
		if(space_t_s == "StudyRoom"){
			for(auto a: studyroom_list){
				if(a.name_get() == mem_n_s) return 11;
				if(stoi(num_mem_s) > 6) return 12;
				if(stoi(time_s) > 3) return 13;
				if(a.room_num_get() == stoi(space_n_s)){
					if(a.condition_get() != 0){
						return 14 + stoi(a.time_get());
					}
				}
			}
		}
		else if(space_t_s == "Seat"){
			i = 0;
			for(auto a: seat_list){
				if(a.name_get() == mem_n_s) return 11;
				if(stoi(num_mem_s) > 1) return 12;
				if(stoi(time_s) > 3) return 13;
				if(a.floor_get() == space_n_s){
					if(a.condition_get() == 0) flag = 1;
					else{
						return_time[i] = a.time_get();
						i++;
					} 
				}
			}
			if(flag == 0){
				int min = return_time[0];
				for(int j = 0;j < i;j++){
					if(min > return_time[j]) min = return_time[j];
					if(space_n_s == "1"){
						if(min >= 24) min =0;
					}
					if(space_n_s == "2"){
						if(min > 21) min = 21;
					}
					if(space_n_s == "3"){
						if(min > 18) min = 18;
					}
				}
				return 14 + min;
			}
		}
		if(space_t_s == "StudyRoom"){
			int count = 0;
			for(auto a: studyroom_list){
				if(a.room_num_get() == stoi(space_n_s)){
					now_hr = date_s[11];
					now_hr = now_hr + date_s[12];
					a.time_set(now_hr, stoi(time_s));
					if(a.time_get() > 18) a.time_set("18", 0);
					a.name_set(mem_n_s);
					a.condition_set(2);
					studyroom_list.push_back(a);
					studyroom_list.erase(studyroom_list.begin()+count);
				}
				count++;
			}
		}
		if(space_t_s == "Seat"){
			int count = 0;
			for(auto a: seat_list){
				if(a.floor_get() == stoi(space_n_s)){
					now_hr = date_s[11];
					now_hr = now_hr + date_s[12];
					a.time_set(now_hr, stoi(time_s));
					if(a.floor_get() == 2){
						if(a.time_get() > 21) a.time_set("21", 0);
					}
					if(a.floor_get() == 3){
						if(a.time_get() > 18) a.time_set("18", 0);
					}
					a.name_set(mem_n_s);
					a.condition_set(2);
					seat_list.push_back(a);
					seat_list.erase(seat_list.begin()+count);
				}
				count++;
			}
		}
	}
	if(op_s == "R"){
		
	}
}