#include <sys/types.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class RunTime {
public:
	RunTime() { m_first = clock(); };
	string TimeFormat(const double NumSeconds) const;
	double TotalSeconds() const;

	friend ostream& operator<<(ostream& ros, const RunTime &rTime);
private:
	time_t m_first;
};


string RunTime::TimeFormat(const double NumSeconds) const
{
	stringstream line;
	const long BSIZE = 100;
	char buf[BSIZE];
	double total_seconds = NumSeconds;
	long minutes = (long)total_seconds / 60;
	long hours = minutes / 60;
	minutes = minutes - hours * 60;
	double seconds = total_seconds - minutes * 60 - hours * 3600;
	if (hours) sprintf(buf,"%ld:%2.2ld:%5.3f",hours,minutes,seconds);
	else if (minutes) sprintf(buf,"%2.2ld:%5.3f",minutes,seconds);
	else sprintf(buf,"%5.3f",seconds);
	return buf;
}

double RunTime::TotalSeconds() const
{
	time_t val = clock();
	return ( (double)(val - m_first)/(double)CLOCKS_PER_SEC );
}

ostream& operator<<( ostream& ros, const RunTime &rTime) 
{
	ros << rTime.TimeFormat(rTime.TotalSeconds());
	return ros;
}



