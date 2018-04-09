#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Objects{
private:
	double m_profit;
    static int m_id;
public:
	virtual ~Objects();
	Objects(double pro = 0.);
	Objects(const Objects&obj);
	void setprofit(double pro=0.);
	double getprofit()const;
	static int getid();
	virtual void move(double,double,double)=0;
	virtual void zoomin (unsigned int times)=0;
	virtual void zoomout(unsigned int times)=0;
	virtual void print()const=0;
	virtual const double getvolume()const=0;
	virtual const double getarea()const=0;
	virtual const double getlength()const = 0;
};