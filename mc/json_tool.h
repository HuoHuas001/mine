#pragma once
#include <iostream>
#include "json.hpp"

using Json = nlohmann::basic_json<>;
using JsonType = nlohmann::detail::value_t;
//�ַ���תJSON����������� https://json.nlohmann.me ��JSON��3.10.0�汾
inline Json StringToJson(std::string_view str) {
	try {
		return Json::parse(str);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return nullptr;
	}
}
