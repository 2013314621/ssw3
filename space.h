#include <iostream>
#include <string>
using namespace std;

class space{
	private:
		int time;
		string name;
		int condition;
	public:
		int time_get();
		void time_set(string s, int i);
		string name_get();
		void name_set(string s);
		int condition_get();
		void condition_set(int i);
		space();
};

class studyroom: public space{
	private:
		int room_num;
	public:
		int room_num_get();
		void room_num_set(int i);
		studyroom();
};
class seat: public space{
	private:
		int floor;
	public:
		int floor_get();
		void floor_set(int i);
		seat();
};