#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <vector>
#include <SketchUpAPI\sketchup.h>
#include "utilities/get_string.h"

#define SU(func) {SUResult res = (func); if (res != SU_ERROR_NONE) throw std::runtime_error(std::to_string(res));}

int main() {

	SUInitialize();
	// Load the model from a file
	SUModelRef model = SU_INVALID;
	SU(SUModelCreateFromFile(&model, "C:/Users/Jim/Downloads/issue-19.skp"));

	SUAttributeDictionaryRef ad_ref = SU_INVALID;
	SU(SUModelGetAttributeDictionary(model, "TypedValues", &ad_ref));

	SUTypedValueRef tv_ref = SU_INVALID;
	SU(SUTypedValueCreate(&tv_ref));
	SU(SUAttributeDictionaryGetValue(ad_ref, "Array", &tv_ref));

	size_t count = 0, len = 0;
	SU(SUTypedValueGetNumArrayItems(tv_ref, &len));
	//assert(len == 5);

	std::vector<SUTypedValueRef> refs(len, SU_INVALID);
	SU(SUTypedValueGetArrayItems(tv_ref, len, &refs[0], &count));

	std::vector<std::string> out_v{};

	for (auto tv : refs) {
		SUStringRef s = SU_INVALID;
		SU(SUStringCreate(&s));
		SU(SUTypedValueGetString(tv, &s));
		std::string str = get_string(s);
		out_v.push_back(str);
		SUStringRelease(&s);
	}
	SU(SUModelRelease(&model));
	SUTerminate();

	std::cout << "Array:\n";
	for (auto i = 0; i < out_v.size(); i++) {
		std::cout << "<" << out_v[i] << ">" << std::endl;
	}

	return 0;
}