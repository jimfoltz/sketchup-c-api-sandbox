#ifndef A2S_SHOW_SKETCHUP_ERROR_H
#define A2S_SHOW_SKETCHUP_ERROR_H

void output_sketchup_error(SUResult err) {
	switch (err) {
	case SU_ERROR_NONE:
		std::cout << "SU_ERROR_NONE\n";
		std::cout << "Indicates Success";
		break;
	case SU_ERROR_NULL_POINTER_INPUT:
		std::cout << "SU_ERROR_NULL_POINTER_INPUT\n";
		std::cout << "A pointer for a required input was NULL.";
		break;
	case SU_ERROR_INVALID_INPUT:
		std::cout << "SU_ERROR_INVALID_INPUT\n";
		std::cout << "An API object input to the function was not created properly.";
		break;
	case SU_ERROR_NULL_POINTER_OUTPUT:
		std::cout << "SU_ERROR_NULL_POINTER_OUTPUT\n";
		std::cout << "A pointer for a required output was NULL. ";
		break;
	case SU_ERROR_INVALID_OUTPUT:
		std::cout << "SU_ERROR_INVALID_OUTPUT\n";
		std::cout << "An API object to be written with output from the function was not created properly.";
		break;
	case SU_ERROR_OVERWRITE_VALID:
		std::cout << "SU_ERROR_OVERWRITE_VALID\n";
		std::cout << "Indicates that an input object reference already references an object where it was expected to be SU_INVALID.";
		break;
	case SU_ERROR_GENERIC:
		std::cout << "SU_ERROR_GENERIC\n";
		std::cout << "Indicates an unspecified error.";
		break;
	case SU_ERROR_SERIALIZATION:
		std::cout << "SU_ERROR_SERIALIZATION\n";
		std::cout << "Indicates an error occurred during loading or saving of a file.";
		break;
	case SU_ERROR_OUT_OF_RANGE:
		std::cout << "SU_ERROR_OUT_OF_RANGE\n";
		std::cout << "An input contained a value that was outside the range of allowed values.";
		break;
	case SU_ERROR_NO_DATA:
		std::cout << "SU_ERROR_NO_DATA\n";
		std::cout << "The requested operation has no data to return to the user. This usually occurs when a request is made for data that is only available conditionally.";
		break;
	case SU_ERROR_INSUFFICIENT_SIZE:
		std::cout << "SU_ERROR_INSUFFICIENT_SIZE\n";
		std::cout << "Indicates that the size of an output parameter is insufficient.";
		break;
	case SU_ERROR_UNKNOWN_EXCEPTION:
		std::cout << "SU_ERROR_UNKNOWN_EXCEPTION\n";
		std::cout << "An unknown exception occurred.";
		break;
	case SU_ERROR_MODEL_INVALID:
		std::cout << "SU_ERROR_MODEL_INVALID\n";
		std::cout << "The model requested is invalid and cannot be loaded.";
		break;
	case SU_ERROR_MODEL_VERSION:
		std::cout << "SU_ERROR_MODEL_VERSION\n";
		std::cout << "The model cannot be loaded or saved due to an invalid version.";
		break;
	default:
		std::cout << "Unknown Error #" << err;
	}
	std::cout << std::endl;
}

#endif