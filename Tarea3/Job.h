#ifndef _JOB_
#define _JOB_
Class Job
{
	private:
		int value;
		int id;
	public:
		Job(int value, int id);
		~Job(){};
		int getValue();
		int getId();
}

#endif
