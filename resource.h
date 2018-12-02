#include <iostream>
#include <string>

using namespace std;
class resource{
	private:
		string name;
		int condition;
	public:
		string name_get();
		int condition_get();
		void condition_set(int i);
		void name_set(string s);
};

class book: public resource{
	private:
		string day_return;
		string day_borrow;
		string member_borrow;
	public:
		book(string member);
		string borrow_member_get();
		void borrow_member_set(string s);
		string borrow_day_get();
		void borrow_day_set(string s);
		void return_day_set(string day_borrow);
		string return_day_get();
};

class magazine: public resource{
	private:
		string day_return;
		string day_borrow;
		string member_borrow;
	public:
		magazine(string member);
		string borrow_member_get();
		void borrow_member_set(string s);
		string borrow_day_get();
		void borrow_day_set(string s);
		void return_day_set(string day_borrow);
		string return_day_get();
};

class e_book: public resource{
	private:
		string day_return;
		string day_borrow;
		string member_borrow;
	public:
		e_book(string member);
		string borrow_member_get();
		void borrow_member_set(string s);
		string borrow_day_get();
		void borrow_day_set(string s);
		void return_day_set(string day_borrow);
		string return_day_get();
};
