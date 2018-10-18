/** @file wdjson.h
  * @brief JSON��������
  * @copyright (c) 2018, MeiXuan All rights reserved
  * @author MeiXuan01
  * @date 2018/10/10
  */
#ifndef __WD_JSON_H__
#define __WD_JSON_H__

#include <string>
#include <list>
#include "assert.h"
#include "json.h"

/**
* @namespace nim
* @brief namespace nim
*/
namespace WEBDRIVER
{
/** @fn bool StrListToJsonString(const std::list<std::string>& list, std::string& out)
  * @brief ��һ��string���͵�list��װ��һ��Json Array
  * @param[in] list string���͵�list
  * @param[out] out Json Array
  * @return bool �ɹ� ��ʧ��
  */
bool StrListToJsonString(const std::list<std::string>& list, std::string& out);

/** @fn bool JsonStrArrayToList(const Json::Value& array_str, std::list<std::string>& out)
  * @brief ��һ��string���͵�Json Array������һ��string���͵�list
  * @param[in] array_str string���͵�Json Array
  * @param[out] out string���͵�list
  * @return bool �����ɹ� ��ʧ��
  */
bool JsonStrArrayToList(const Json::Value& array_str, std::list<std::string>& out);

/** @fn bool JsonArrayStringToList(const std::string& array_str, std::list<std::string>& out)
  * @brief ��һ��string���͵�Json Array������һ��string���͵�list
  * @param[in] array_str string���͵�Json Array
  * @param[out] out string���͵�list
  * @return bool �����ɹ� ��ʧ��
  */
bool JsonArrayStringToList(const std::string& array_str, std::list<std::string>& out);

/** @fn bool ParseJsonValue(const std::string &content, Json::Value &values);
  * @brief ����JsonString
  * @param[in] content JsonString
  * @param[out] values JsonValue
  * @return bool �����ɹ�ʧ��
  */
bool ParseJsonValue(const std::string &content, Json::Value &values);

/** @fn std::string GetJsonStringWithNoStyled(const Json::Value& values);
  * @brief ��÷Ǹ�ʽ����Json string,����SDK��json string��ʽҪ��Ϊ�Ǹ�ʽ���ģ�����Ǹ�ʽ����json string���ܻ�Ӱ�칦��
  * @param[in] values Json Value
  * @return std::string �Ǹ�ʽ����json string
  */
std::string GetJsonStringWithNoStyled(const Json::Value& values);

/** @fn Json::Value GetJsonValueFromJsonString(const std::string& json_string);
  * @brief ����JsonString
  * @return JsonValue
  */
Json::Value GetJsonValueFromJsonString(const std::string& json_string);

}

#endif //!__WD_JSON_H__