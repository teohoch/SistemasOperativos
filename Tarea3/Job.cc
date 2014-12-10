
#include "Job.h"

Job::Job()
{	
}

int Job::getValue()
{
	return this->value;
}

int Job::getId()
{
	return this->id;
}

void Job::setValue(int value)
{
	this->value = value;
}

void Job::setId(int id)
{
	this->id = id;
}
