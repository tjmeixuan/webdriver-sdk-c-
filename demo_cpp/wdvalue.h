/** @file wdvalue.h
  * @brief �ַ�����ֵ��ת��������
  * @copyright (c) 2018, MeiXuan All rights reserved
  * @author MeiXuan01
  * @date 2018/10/10
  */
#ifndef __WD_VALUE_H__
#define __WD_VALUE_H__

#include <string>

namespace WEBDRIVER
{
	class WDValue
	{
	public:
		WDValue();
	public:
		static int str_to_int(std::string& value);
		static unsigned int str_to_uint(std::string& value);
		static double str_to_double(std::string& value);
		static bool str_to_bool(std::string& value);

		static std::string int_to_str(int value);
		static std::string uint_to_str(unsigned int value);
		/*
		 * ���� decplaces: ����С�����Լ�����С��λ�� Ĭ��decplaces=3������ 0.01
 		 */
		static std::string double_to_str(long double value, int decplaces=3);
		static std::string bool_to_str(bool value);		
	};
}



#endif //!__WD_VALUE_H__