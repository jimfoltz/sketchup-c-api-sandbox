#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <vector>
#include <SketchUpAPI\sketchup.h>

#define SU_CALL(func) {SUResult res = (func); if (res != SU_ERROR_NONE) throw std::runtime_error(std::to_string(res));}

int main() {

	//auto model = CW::Model("C:/Users/Jim/Downloads/issue-19.skp");
	SUInitialize();
	// Load the model from a file
	SUModelRef model = SU_INVALID;
	SU_CALL(SUModelCreateFromFile(&model, "C:/Users/Jim/Downloads/issue-19.skp"));

	SUAttributeDictionaryRef ad_ref( SU_INVALID );
	SU_CALL(SUModelGetAttributeDictionary(model, "TypedValues", &ad_ref));

	SUTypedValueRef tv_ref(SU_INVALID );
	SU_CALL(SUTypedValueCreate(&tv_ref));
	SU_CALL(SUAttributeDictionaryGetValue(ad_ref, "Array", &tv_ref));

	size_t count = 0, len = 0;
	SU_CALL(SUTypedValueGetNumArrayItems(tv_ref, &len));
	//assert(len == 5);

	std::vector<SUTypedValueRef> refs(len);
	SU_CALL(SUTypedValueGetArrayItems(tv_ref, len, &refs[0], &count));
	SUStringRef s( SU_INVALID );
	SU_CALL(SUStringCreate(&s));
	std::vector<std::string> out_v{};
	for (auto tv : refs) {
		SU_CALL(SUTypedValueGetString(tv, &s));
		size_t s_len = 0;
		SU_CALL(SUStringGetUTF8Length(s, &s_len));
		size_t out = 0;
		std::string str{};
		SUStringGetUTF8(s, s_len + 1, &str[0], &out);
		out_v.push_back(str);
	}

	SU_CALL(SUModelRelease(&model));
	SUTerminate();

	return 0;
}