#include <iostream>
#include <string>

using namespace std;

class member{
	private:
		string name;
	public:
		string name_get();
		void name_set(string s);
};

class undergraduated: public member{
	private:
		string book_name;
		int ban;
		int num_borrow;
		string restricted_day;
	public:
		undergraduated();
		undergraduated(string s);
		int ban_get();
		void ban_set(int i);
		int limit_get();
		void limit_set(int i);
		string restricted_day_get();
		void restricted_day_set(string s);
		void book_name_set(string s);
		string book_name_get();
};
