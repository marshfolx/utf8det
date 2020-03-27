
#include "utf8det.h"
#include "TextEncodingDetect/text_encoding_detect.h"

using namespace AutoIt::Common;

Utf8Det::Utf8Det(): det(std::make_unique<TextEncodingDetect>()) {

}

det_encoding Utf8Det::scan(const char* buf, size_t buf_size) {
	return static_cast<det_encoding>(this->det->DetectEncoding(
	                                 reinterpret_cast<const unsigned char*>(buf), buf_size));
}

