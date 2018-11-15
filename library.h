#include <iostream>
#include <string>
#include "space.h"
#include "member.h"
#include "resource.h"
#include <vector>
using namespace std;
class library{
	private:
		vector <book> book_list;
		vector <member> mem_list;
		vector <seat> seat_list;
		vector <studyroom> studyroom_list;
	public:
		library();
		void input_get();
		void data_get();
		int process_s(string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8);
		int daytoint_r(string s);
		int daytoint_s(string s);
		
};