#ifndef _JOB_
#define _JOB_

class Job{
	private:
		int value;
		int id;
	public:
		Job();
		~Job(){};
		int getValue();
		int getId();
		void setValue(int value);
		void setId(int id);
};


#endif
