// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� WEBDRIVER_CPP_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// WEBDRIVER_CPP_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef _WEBDRIVER_CPP_H_
#define _WEBDRIVER_CPP_H_

#include <string>
#include <functional>

#ifdef WEBDRIVER_CPP_EXPORTS
#define WEBDRIVER_CPP_API __declspec(dllexport)
#else
#define WEBDRIVER_CPP_API __declspec(dllimport)
#endif

namespace WEBDRIVER
{

	// �����Ǵ� webdriver_cpp.dll ������
	class WEBDRIVER_CPP_API CWebdriver
	{
	public: 
		typedef std::function<void(const std::string& appid, const std::string& pageid, const std::string& wid, const std::string& name, const std::string& sid, const std::string& value, void* user)> NOTICE_CALLBACK;
		typedef std::function<void(const std::string& appid, bool state)> CONNECTSTATE_CALLBACK;
	public:
		CWebdriver(void);
		// TODO: �ڴ�������ķ�����

	public:
		static int config(const std::string& serverip);

		static int connect(const std::string& appid, const std::string& accesskey, const std::string& secretkey, NOTICE_CALLBACK noticeCallback, CONNECTSTATE_CALLBACK connectStateCallback);
		static int disconnect(const std::string& appid);

		static int write(const std::string& appid, const std::string& pageid, const std::string& wid, const std::string& name, const std::string& sid, const std::string& value);
		static int read(const std::string& appid, const std::string& pageid, const std::string& wid, const std::string& name, void* value);

		static int showPage(const std::string& appid, const std::string& pageid, const std::string& targetpageid, const std::string& sid);
		static int sendMessage(const std::string& appid, const std::string& pageid, const std::string& type, const std::string& title, const std::string& message, int duration, const std::string& sid);
	};

}

#endif //!_WEBDRIVER_CPP_H_