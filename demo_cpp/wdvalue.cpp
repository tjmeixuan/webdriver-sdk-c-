/** @file wdvalue.cpp
  * @brief ֵ���ַ�����ת��������
  * @copyright (c) 2018, MeiXuan All rights reserved
  * @author MeiXuan01
  * @date 2018/10/10
  */
#include "stdafx.h"
#include "wdvalue.h"
#include <sstream>

namespace WEBDRIVER
{
WDValue::WDValue() 
{
}
int WDValue::str_to_int(std::string& value)
{
	int int_temp;
	std::stringstream stream(value);  
    stream>>int_temp;
	return int_temp;
}
unsigned int WDValue::str_to_uint(std::string& value)
{
	unsigned int int_temp;
	std::stringstream stream(value);  
    stream>>int_temp;
	return int_temp;
}
double WDValue::str_to_double(std::string& value)
{
	std::istringstream iss(value);
	double num;
	iss >> num;
	return num;
}
bool WDValue::str_to_bool(std::string& value)
{
	if(value.empty() || value.compare("0") == 0 || value.compare("false") == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::string WDValue::int_to_str(int value)
{
	std::string string_temp;
	std::stringstream stream;  
	stream<<value;
	string_temp=stream.str();   //�˴�Ҳ������ stream>>string_temp 
	return string_temp;
}
std::string WDValue::uint_to_str(unsigned int value)
{
	std::string string_temp;
	std::stringstream stream;  
	stream<<value;
	string_temp=stream.str();   //�˴�Ҳ������ stream>>string_temp 
	return string_temp;
}
std::string WDValue::double_to_str(long double value, int decplaces)
{
	char DECIMAL_POINT='.'; // ŷ���÷�Ϊ','
	std::ostringstream out;
	int prec = std::numeric_limits<long double>::digits10; // 18
	out.precision(prec);//����Ĭ�Ͼ���
	out<<value;
	std::string str= out.str(); //������ȡ���ַ���
	size_t n=str.find(DECIMAL_POINT);
 
	if ((n!=std::string::npos)&& (str.size()> n+decplaces)) //��С������ //�������ٻ���decplacesλ��
	{
		str[n+decplaces]='\0';//���ǵ�һ���������
	}
	str.swap(std::string(str.c_str()));//ɾ��nul֮��Ķ����ַ�
	return str;
}
std::string WDValue::bool_to_str(bool value)
{
	std::string string_temp;
	string_temp = value?"1":"0";
	return string_temp;
}	
}

