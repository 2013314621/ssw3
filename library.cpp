#include <iostream>
#include <string>
#include <cstring>
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
	data_get();
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
string library :: inttoday_r(int i){
	string year, month, day;
	year = to_string(i/360);
	if(year.length()==1) year = "0" + year;
	month = to_string((i%360)/30);
	if(month.length()==1) month = "0" + month;
	day = to_string((i%360)%30);
	if(day.length()==1) day = "0" + day;
	return year + "/" + month + "/" + day;	
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
		book_list.push_back(book_temp);	
	}
	in_1.close();
	
}
int library::find_num(string s){
	if(s.find('1') != -1) return 1;
	else if(s.find('2') != -1) return 1;
	else if(s.find('3') != -1) return 1;
	else if(s.find('4') != -1) return 1;
	else if(s.find('5') != -1) return 1;
	else if(s.find('6') != -1) return 1;
	else if(s.find('7') != -1) return 1;
	else if(s.find('8') != -1) return 1;
	else if(s.find('9') != -1) return 1;
	else if(s.find('0') != -1) return 1;
	else return 0;
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
	int flag_r = 0;
	int flag_s = 0;
	int date_s_int;
	int temp_date_int;
	int clear_flag = 0;
	string temp;
	string temp_date;
	input_resource.open("input.dat");
	input_space.open("space.dat");
	for(int i = 0;i < 6;i++){
		input_resource >> temp;
	}
	for(int i = 0;i < 8;i++){
		input_space >> temp;
	}
	while(1){
		if(flag_r == 0){
			if(input_resource >> date_r){
				input_resource >> resource_t_r >> resource_n_r >> op_r >> mem_t_r >> mem_n_r;
				flag_r = 1;
			}
		}
		if(flag_s == 0){
			if(input_space >> date_s){
				if(clear_flag == 1){
					date_s_int = daytoint_s(date_s);
					temp_date_int = daytoint_s(temp_date);
					if(date_s_int != temp_date_int){
						seat_list.clear();
						studyroom_list.clear();
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
					}
				}
				input_space >> space_t_s >> space_n_s >> op_s >> mem_t_s >> mem_n_s;
				clear_flag = 1;
				if(op_s == "B"){
					input_space >> num_mem_s >> time_s;
				}
				flag_s = 1;
			}
		}
		if((flag_r == 1) && (flag_s == 1))
		{
			all_day_r = daytoint_r(date_r);
			all_day_s = daytoint_s(date_s);

			if(all_day_r > all_day_s){
				try{
					if(daytoint_s(date_s) < daytoint_s("2009/12/30/00")) throw -1;
					else if((space_t_s != "StudyRoom") && (space_t_s != "Seat")) throw -2;
					else if((op_s != "R") && (op_s != "B")) throw -3;
					else if((mem_t_s != "Undergraduate") && (mem_t_s != "Faculty") && (mem_t_s != "Graduate")) throw -4;
					else if(find_num(mem_n_s) == 1) throw -5;
					else if(stoi(time_s) < 0) throw -6;
					else output_s(process_s(date_s,space_t_s,space_n_s,op_s,mem_t_s,mem_n_s,num_mem_s,time_s));
				}
				catch(int i){
					char tmp;
					while(true){
						input_space.get(tmp);
						if(tmp == '\n') break;
					}
					if(i == -1) cout << "Date out of range" << endl;
					else if(i == -2) cout << "Non-exist space type" << endl;
					else if(i == -3) cout << "Non-exist operation" << endl;
					else if(i == -4) cout << "Non-exist member type" << endl;
					else if(i == -5) cout << "Member name with numbers" << endl;
					else if(i == -6) cout << "Negative time" << endl;
				}
				
				temp_date = date_s;
				flag_s = 0;
			}
			else{
				output_r(process_r(date_r,resource_t_r,resource_n_r,op_r,mem_t_r,mem_n_r));
				flag_r = 0;
			}
		}
		else if((flag_r == 1) && (flag_s == 0)){
			output_r(process_r(date_r,resource_t_r,resource_n_r,op_r,mem_t_r,mem_n_r));
			flag_r = 0;
		}
		else if((flag_r == 0) && (flag_s == 1)){
				try{
					if(daytoint_s(date_s) < daytoint_s("2009/12/30/00")) throw -1;
					else if((space_t_s != "StudyRoom") && (space_t_s != "Seat")) throw -2;
					else if((op_s != "R") && (op_s != "B")) throw -3;
					else if((mem_t_s != "Undergraduate") && (mem_t_s != "Faculty") && (mem_t_s != "Graduate")) throw -4;
					else if(find_num(mem_n_s) == 1) throw -5;
					else if(stoi(time_s) < 0) throw -6;
					else output_s(process_s(date_s,space_t_s,space_n_s,op_s,mem_t_s,mem_n_s,num_mem_s,time_s));
				}
				catch(int i){
					char tmp;
					while(true){
						input_space.get(tmp);
						if(tmp == '\n') break;
					}
					if(i == -1) cout << "Date out of range" << endl;
					else if(i == -2) cout << "Non-exist space type" << endl;
					else if(i == -3) cout << "Non-exist operation" << endl;
					else if(i == -4) cout << "Non-exist member type" << endl;
					else if(i == -5) cout << "Member name with numbers" << endl;
					else if(i == -6) cout << "Negative time" << endl;				
				}
			
			temp_date = date_s;
			flag_s = 0;
		}
		else break;
	}
}
int library::process_r(string date_r, string resource_t_r, string resource_n_r, string op_r, string mem_t_r, string mem_n_r){
	int flag = 0;
	int state = 0;
	int i = 0;
	int int_temp;
	int temp_day_int;
	string delay;
	for(auto a : book_list){
		if(a.name_get() == resource_n_r){
			flag = 1;
		}
	}
	if(flag == 0){
		return 1;
	}
	else{
		if(op_r == "B"){
			for(auto a : mem_list){
				if(a.name_get() == mem_n_r){
					if(a.limit_get() != 0){ 
						return 2;	
					}
					if(a.ban_get() == 1){
						return 600 + daytoint_r(a.restricted_day_get());
					}
				}
			}
			for(auto a : book_list){
				if(a.name_get() == resource_n_r){
					if(a.condition_get() == 0){
						if(a.borrow_member_get() == mem_n_r) return 4 + daytoint_r(a.borrow_day_get());
						else{
							return 50 + daytoint_r(a.return_day_get());
						}
					}
				}
			}
		}
		else if(op_r == "R"){
			for(auto a : book_list){
				if(a.name_get() == resource_n_r){
					if(a.borrow_member_get() == mem_n_r){
						if(daytoint_r(a.return_day_get()) > daytoint_r(date_r)){
							temp_day_int = daytoint_r(a.return_day_get()) - daytoint_r(date_r);
							int count = 0;
							for(auto a: mem_list){
								if(a.name_get() == mem_n_r){
									a.book_name_set("");
									a.limit_set(0);
									a.ban_set(1);
									a.restricted_day_set(inttoday_r(temp_day_int + daytoint_r(date_r)));
									mem_list.push_back(a);
									mem_list.erase(mem_list.begin() +count);
								}
								count++;
							}
							return 7000 + temp_day_int + daytoint_r(date_r);
						}
					}
				}
			}
		}
		if(op_r == "B"){
			int count = 0;
			for(auto a:book_list){
				if(a.name_get() == resource_n_r){
					a.condition_set(0);
					a.borrow_member_set(mem_n_r);
					a.borrow_day_set(date_r);
					a.return_day_set(date_r);
					book_list.push_back(a);
					book_list.erase(book_list.begin()+count);
				}
				count++;	
			}
			undergraduated b(mem_n_r);
			b.book_name_set(resource_n_r);
			b.limit_set(1);
			mem_list.push_back(b);
		}
		return 0;
	}
}
int library::process_s(string date_s, string space_t_s, string space_n_s, string op_s, string mem_t_s, string mem_n_s, string num_mem_s, string time_s){
	int now_hr_int;
	string now_hr;
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
				if(a.floor_get() == stoi(space_n_s)){
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
						if(a.time_get() > 18){
							return 14 + 18;
						}
						else{
							return 14 + a.time_get();
						}
					}
				}
			}
		}
		else if(space_t_s == "Seat"){
			int i = 0;
			for(auto a: seat_list){
				if(a.name_get() == mem_n_s) return 11;
				if(stoi(num_mem_s) > 1) return 12;
				if(stoi(time_s) > 3) return 13;
				if(a.floor_get() == stoi(space_n_s)){
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
		return 0;
	}
	if(op_s == "R"){
		if(space_t_s == "StudyRoom"){
			int count = 0;
			for(auto a: studyroom_list){
				if(a.room_num_get() == stoi(space_n_s)){
					a.time_set("0",0);
					a.name_set("");
					a.condition_set(0);
					studyroom_list.push_back(a);
					studyroom_list.erase(studyroom_list.begin()+count);
				}
				count++;
			}
		}
		else if(space_t_s == "Seat"){
			int count = 0;
			for(auto a: seat_list){
				if(a.floor_get() == stoi(space_n_s)){
					a.time_set("0",0);
					a.name_set("");
					a.condition_set(0);
					seat_list.push_back(a);
					seat_list.erase(seat_list.begin()+count);
				}
				count++;
			}
		}
		return 0;
	}
	if(op_s == "E"){
		int count = 0;
		if(space_t_s == "StudyRoom"){
			for(auto a: studyroom_list){
				if(a.room_num_get() == stoi(space_n_s)){
					now_hr = date_s[11];
					now_hr = now_hr + date_s[12];
					a.condition_set(1);
					studyroom_list.push_back(a);
					studyroom_list.erase(studyroom_list.begin()+count);
				}
				count++;
			}
		}
		else if(space_t_s == "Seat"){
			int count = 0;
			for(auto a: seat_list){
				if(a.floor_get() == stoi(space_n_s)){
					now_hr = date_s[11];
					now_hr = now_hr + date_s[12];
					a.empty_time_set(stoi(now_hr));
					a.condition_set(1);
					seat_list.push_back(a);
					seat_list.erase(seat_list.begin()+count);
				}
				count++;
			}
		}
		return 0;
	}
	if(op_s == "C"){
		if(space_t_s == "StudyRoom"){
			int count = 0;
			for(auto a: studyroom_list){
				if(a.room_num_get() == stoi(space_n_s)){
					a.condition_set(2);
					studyroom_list.push_back(a);
					studyroom_list.erase(studyroom_list.begin()+count);
				}
				count++;
			}
		}
		else if(space_t_s == "Seat"){
			int count = 0;
			for(auto a: seat_list){
				if(a.floor_get() == stoi(space_n_s)){
					a.empty_time_set(0);
					a.condition_set(2);
					seat_list.push_back(a);
					seat_list.erase(seat_list.begin()+count);
				}
				count++;
			}
		}
		return 0;
	}
}
void library::output_s(int i){
	if(i == 0) cout << "Success." << endl;
	else if(i == 8) cout << "Invalid space id." << endl;
	else if(i == 91) cout << "This space is not available now. Available from 09 to 18." << endl;
	else if(i == 92) cout << "This space is not available now. Available from 09 to 21." << endl;
	else if(i == 10) cout << "You did not borrow this space." << endl;
	else if(i == 11) cout << "You already borrowed this kind of space." << endl;
	else if(i == 12) cout << "Exceed available number." << endl;
	else if(i == 13) cout << "Exceed available time." << endl;
	else if(i >= 14) cout << "There is no remain space. This space is available after " << i-14 << "." << endl;
}
void library::output_r(int i){
	if(i == 0) cout << "Success." << endl;
	else if(i == 1) cout << "Non exist resource." << endl;
	else if(i == 2) cout << "Exceeds your possible number of borrow. Possible # of borrows: 1" << endl;
	else if(i == 3) cout << "You did not borrow this book." << endl;
	else if(i == 4) cout << "" << endl;
	else if((i >= 50) && (i <90)) cout << "Other member already borrowed this book. This book will be returned at " << inttoday_r(i - 50) << "." << endl;
	else if((i >= 600) &&(i <= 700)) cout << "Restricted member until " << inttoday_r(i - 600) << "." << endl;
	else if(i >= 7000) cout << "Delayed return. You'll be restricted until " << inttoday_r(i-7000) <<"." << endl;
}