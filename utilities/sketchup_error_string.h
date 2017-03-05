#pragma once

#include <sstream>

std::string sketchup_error_string(SUResult err, std::string file = "", int  line = 0 ) {
    std::ostringstream ss{};
    ss << file << ":" << line << "\n";
    switch (err) {
    case SU_ERROR_NONE:
        ss << "SU_ERROR_NONE\n";
        ss << "Indicates Success";
        break;
    case SU_ERROR_NULL_POINTER_INPUT:
        ss << "SU_ERROR_NULL_POINTER_INPUT\n";
        ss << "A pointer for a required input was NULL.";
        break;
    case SU_ERROR_INVALID_INPUT:
        ss << "SU_ERROR_INVALID_INPUT\n";
        ss << "An API object input to the function was not created properly.";
        break;
    case SU_ERROR_NULL_POINTER_OUTPUT:
        ss << "SU_ERROR_NULL_POINTER_OUTPUT\n";
        ss << "A pointer for a required output was NULL. ";
        break;
    case SU_ERROR_INVALID_OUTPUT:
        ss << "SU_ERROR_INVALID_OUTPUT\n";
        ss << "An API object to be written with output from the function was not created properly.";
        break;
    case SU_ERROR_OVERWRITE_VALID:
        ss << "SU_ERROR_OVERWRITE_VALID\n";
        ss << "Indicates that an input object reference already references an object where it was expected to be SU_INVALID.";
        break;
    case SU_ERROR_GENERIC:
        ss << "SU_ERROR_GENERIC\n";
        ss << "Indicates an unspecified error.";
        break;
    case SU_ERROR_SERIALIZATION:
        ss << "SU_ERROR_SERIALIZATION\n";
        ss << "Indicates an error occurred during loading or saving of a file.";
        break;
    case SU_ERROR_OUT_OF_RANGE:
        ss << "SU_ERROR_OUT_OF_RANGE\n";
        ss << "An input contained a value that was outside the range of allowed values.";
        break;
    case SU_ERROR_NO_DATA:
        ss << "SU_ERROR_NO_DATA\n";
        ss << "The requested operation has no data to return to the user. This usually occurs when a request is made for data that is only available conditionally.";
        break;
    case SU_ERROR_INSUFFICIENT_SIZE:
        ss << "SU_ERROR_INSUFFICIENT_SIZE\n";
        ss << "Indicates that the size of an output parameter is insufficient.";
        break;
    case SU_ERROR_UNKNOWN_EXCEPTION:
        ss << "SU_ERROR_UNKNOWN_EXCEPTION\n";
        ss << "An unknown exception occurred.";
        break;
    case SU_ERROR_MODEL_INVALID:
        ss << "SU_ERROR_MODEL_INVALID\n";
        ss << "The model requested is invalid and cannot be loaded.";
        break;
    case SU_ERROR_MODEL_VERSION:
        ss << "SU_ERROR_MODEL_VERSION\n";
        ss << "The model cannot be loaded or saved due to an invalid version.";
        break;
    default:
        ss << "Unknown Error #" << err;
    }
    return ss.str();
}

