#pragma once
#include <string>
//����۲���
template <typename T>
struct span {
	size_t size;
	T* data;
};
//string_span
template <>
struct span<char> {
	size_t len;
	const char* str;
	span(const char* s) : len(strlen(s)), str(s) {}
	span(const std::string& s) : len(s.length()), str(s.c_str()) {}
};

