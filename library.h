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
		int daytoint_r(string s);
		int daytoint_s(string s);
		
};