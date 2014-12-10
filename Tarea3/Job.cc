
#include "Job.h"

Job::Job()
{	
}

int Job::getValue()
{
	return this->value;
}

unsigned long int Job::getId()
{
	return this->id;
}

void Job::setValue(int value)
{
	this->value = value;
}

void Job::setId(unsigned long int id)
{
	this->id = id;
}
