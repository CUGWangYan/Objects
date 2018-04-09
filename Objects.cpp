#include "Objects.h"
Objects::~Objects() { m_id--; };
Objects::Objects(double pro) :m_profit(pro) {
	m_id++;
};
void Objects::setprofit(double pro) {
	m_profit = pro;
};
double Objects::getprofit()const {
	return m_profit;
}
int Objects::getid(){
	return m_id;
}
Objects::Objects(const Objects&obj) {
	m_profit = obj.m_profit;
};
int Objects::m_id = 0;