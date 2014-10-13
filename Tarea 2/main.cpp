#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <csignal>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



int number;
int p[2];

struct arrival{
	int position;
	string time;
};

string read_from_pipe (int file)
{
	FILE *stream;
	char c;
	stream = fdopen (file, "r");
	string s="";
	while ((c = fgetc (stream)) != EOF){
		s=s + c;
	}
	fclose (stream);
	return s;
}

string getTime(){
	time_t ltime;
	struct tm *Tm;
	ltime=time(NULL);
	Tm=localtime(&ltime);
	ostringstream convert;
	convert<<Tm->tm_hour<<":"<<Tm->tm_min<<":"<<Tm->tm_sec;
	return convert.str();
}

void write_to_pipe (int file)
{
	ostringstream convert;
	convert <<number<<" "<<getTime()<<"\n";
	string input = convert.str();
	FILE *stream;
	stream = fdopen (file, "w");
	fprintf (stream,"%s", input.c_str());
	fclose (stream);
}

void signalHandler( int signum )
{
	sleep(10);
	cout<<"Pony "<<number<<" ha terminado la carrera \n";
	close (p[0]);
	write_to_pipe (p[1]);
   exit(signum);

}

int main(int argc, char **argv)
{
    int count = 0;
    string startTime;

    if (pipe (p))
         {
           fprintf (stderr, "Pipe failed.\n");
           return EXIT_FAILURE;
         }

    int numberOfSons = 9;

    pid_t pid=1;
    pid_t sons[numberOfSons];
    int status[numberOfSons];
    signal(SIGINT, signalHandler);

    while(pid!=0 && count<numberOfSons)
    {
    	number = count+1;
    	pid=fork();

    	if (pid!=0){
    		sons[count]=pid;
    	}else{
			while(1);
    	}
    	count++;
    }


    if (pid!=0)
    {
    	cout<<"Iniciando Conteo Regresivo:\n";
    	for(int i = 3; i>0; i--){
    		sleep(1);
    		cout<<i<<"\n";
    	}

    	signal(SIGINT, SIG_IGN);
    	startTime=getTime();
    	kill(0,SIGINT);

    	for(int i = 0; i<numberOfSons;i++){
			waitpid(sons[i],&status[i],0);
		}
    	close (p[1]);

    	string raw = read_from_pipe(p[0]);
    	cout<<"El juez de linea dice:\n"<<"La carrera inicio a las "<<startTime<<"\n";


    	arrival arrived[numberOfSons];
    	stringstream stream(raw);
    	string word;

    	while( getline(stream, word) ){
    		int pos = atoi(word.substr(0, word.find(" ")).c_str());
    		string time = word.substr(word.find(" "));
    		arrived[pos-1].position=pos;
    		arrived[pos-1].time=time;
    	}
    	for(int i = 0; i<numberOfSons; i++)
    	{
    		cout<<"El pony "<<arrived[i].position<<" se retiro de la carrera a las"<<arrived[i].time<<"\n";
    	}
    }
    return 0;
}
