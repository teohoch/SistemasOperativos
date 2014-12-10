#ifndef _JOB_
#define _JOB_

class Job{
	private:
		int value;
		unsigned long int id;
	public:
		Job();
		~Job(){};
		int getValue();
		unsigned long int getId();
		void setValue(int value);
		void setId(unsigned long int id);
};


#endif
