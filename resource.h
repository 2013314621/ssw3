#include <iostream>
#include <string>

using namespace std;
class resource{
	private:
		string name;
	public:
		string name_get();
		
		void store(string s);
		void name_set(string s);
};

class book: public resource{
	private:
		string day_return;
		string day_borrow;
		string member_borrow;
		int avail;
	public:
		book(string member);
		string borrow_member_get();
		void borrow_member_set(string s);
		string borrow_day(string day_borrow);
		void return_day_set(string day_borrow);
		string return_day_get();
		int available(string member);
};
