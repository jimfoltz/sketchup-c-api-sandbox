#include <string>
#include <vector>

std::string get_string(const SUStringRef& string) {
	size_t length = 0;
	SUStringGetUTF8Length(string, &length);
	std::vector<char> buffer(length + 1);
	size_t out_length = 0;
	SUStringGetUTF8(string, length + 1, buffer.data(), &out_length);
	assert(out_length == length);
	return std::string(begin(buffer), end(buffer));
}
