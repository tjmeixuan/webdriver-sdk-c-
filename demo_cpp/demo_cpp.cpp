// demo_cpp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"
#include <string>
#include<iostream>
#include "webdriver_cpp.h"
#include "wdvalue.h"
#include "wdjson.h"

std::string APPID = "5b4564eaab00093b641e99b5";
std::string ACCESSKEY = "a59836a11b76dda496bac68c";
std::string SECRETKEY = "3dcc2142b326020d92b77b1c";
std::string PAGEID = "5b45b741aa4a3a3f5840d15b";
std::string PAGEID2 = "5bbc30e769516e40e8366d17";
std::string CIRCLE = "WDVZ6DE5OF";	// ҳ��1�е�Բ���������ʾ�ı䱳����ɫ
std::string BUTTON1 = "WDJTLFVEQQ";	// ҳ��1�е��л�ҳ�水ť
std::string BUTTON2 = "WDCIILJPWO";	// ҳ��1�е���ʾ��Ϣ��ť
std::string BUTTON3 = "WDWLABJ5JW";	// ҳ��2�е��л�ҳ�水ť

void fNoticeCallback(const std::string& appid, const std::string& pageid, const std::string& wid, const std::string& name, const std::string& sid, const std::string& value, void* user)
{
	printf("rcv data wid = %s , name = %s, value = %s\r\n",  wid.c_str(), name.c_str(), value.c_str());

	if (pageid.compare(PAGEID) == 0)
	{
		if(wid.compare(BUTTON1) == 0)
		{
			// ��һҳ�İ�ť id
			printf("�յ� ��һҳ ��ť�� ����¼�, ׼����ת���ڶ�ҳ\n");

			// ��ת���ڶ�ҳ
			WEBDRIVER::CWebdriver::showPage(APPID, PAGEID, PAGEID2, "0");
		} 
		else if (wid.compare(BUTTON2) == 0)
		{
			// ��ʾ��Ϣ
			const char* title = "hello";
			const char* message = "welcome to webdriver";

			WEBDRIVER::CWebdriver::sendMessage(APPID, PAGEID, "success", title, message, 3, sid);
		}
	}
	else if (pageid.compare(PAGEID2) == 0)
	{
		if (wid.compare(BUTTON3) == 0){
			// �ڶ�ҳ�İ�ť id
			printf("�յ� �ڶ�ҳ ��ť�� ����¼�, ׼����ת����һҳ\n");
			// ��ת����һҳ
			WEBDRIVER::CWebdriver::showPage(APPID, PAGEID2, PAGEID, sid);
		} 
	}
}

void fConnectStateCallback(const std::string& appid, bool state){
	printf("connect state, appid = %s , state = %d\r\n",  appid.c_str(), state);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );    //���õ��ԶѺ������ٷ���ķ�ʽ 
    // _CrtSetBreakAlloc();     //��仰����ȷʵ���ڴ�й¶������£��� �ڴ������

	std::string colors[]  = {"red", "blue", "yellow"};
	std::string serverip = "127.0.0.1";
	int index = 0;

	// ���Ը�������
	std::cout<<"=== ���Ը������� ==="<<std::endl;
	std::string strvalue = "12.123456789";
	int a1;
	unsigned int a2;
	double a3;
	bool a4;
	std::string d1, d2, d3, d4;
	a1 = WEBDRIVER::WDValue::str_to_int(strvalue);
	a2 = WEBDRIVER::WDValue::str_to_uint(strvalue);
	a3 = WEBDRIVER::WDValue::str_to_double(strvalue);
	a4 = WEBDRIVER::WDValue::str_to_bool(strvalue);

	std::cout<<"a1="<<a1<<" a2="<<a2<<" a3="<<a3<<" a4="<<a4<<std::endl;

	d1 = WEBDRIVER::WDValue::int_to_str(a1);
	d2 = WEBDRIVER::WDValue::uint_to_str(a2);
	d3 = WEBDRIVER::WDValue::double_to_str(a3);
	d4 = WEBDRIVER::WDValue::bool_to_str(a4);

	std::cout<<"d1="<<d1<<" d2="<<d2<<" d3="<<d3<<" d4="<<d4<<std::endl;

	d3 = WEBDRIVER::WDValue::double_to_str(123456.123456);
	std::cout<<"double="<<123456.123456<<" str="<<d3<<std::endl;

	d3 = WEBDRIVER::WDValue::double_to_str(1.00000007);
	std::cout<<"double="<<1.00000007<<" str="<<d3<<std::endl;

	d3 = WEBDRIVER::WDValue::double_to_str(12345678.1);
	std::cout<<"double="<<12345678.1<<" str="<<d3<<std::endl;

	d3 = WEBDRIVER::WDValue::double_to_str(1.1234e-05);
	std::cout<<"double="<<1.1234e-05<<" str="<<d3<<std::endl;

	// ����JSON�����string ת��
	std::cout<<"=== ����JSON ==="<<std::endl;
	// ����json�Ǹ�ʽ�����ַ��� �� JSON���󣬶�ȡJSON�����е�ֵ
	std::string jsonstr = "{\"name\":\"webdriver\"}";
	Json::Value root;
	WEBDRIVER::ParseJsonValue(jsonstr, root);
	std::string name = root["name"].asString();
	std::cout<<"get name = "<<name<<std::endl;
	// ����json����ת�ַ���
	Json::Value root1;
	Json::Value childs;
	childs["name"] = "webdriver"; // ���ɶ���
	root1.append(childs);	// ��������
	std::string root1Str = WEBDRIVER::GetJsonStringWithNoStyled(root1);
	std::cout<<"get root1 = "<<root1Str<<std::endl;



	// ���Խӿ�
	std::cout<<"=== ���Խӿ� ==="<<std::endl;
	WEBDRIVER::CWebdriver::config(serverip);
	WEBDRIVER::CWebdriver::connect(APPID, ACCESSKEY, SECRETKEY, fNoticeCallback, fConnectStateCallback);

	while(1){
		Sleep(1000);
		// �ı�Բ�εı�����ɫ
		WEBDRIVER::CWebdriver::write(APPID, PAGEID, CIRCLE, "bg", "0", colors[index]);
		index++;
		if(index >= 3) index = 0;
	}
	return 0;
}

