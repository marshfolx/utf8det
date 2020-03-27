#pragma once


#include <memory>

//a thin wrap for TextEncodingDetect

//forward declaration
namespace AutoIt {
	namespace Common {
		class TextEncodingDetect;
	}
}

//shall not be modified at all, especially the ordering.
enum class det_encoding : int {
	none = 0,				// Unknown, binary probably.
	ansi,				// ansi or something unknown.
	ascii,				// 0-127
	utf8_bom,			// UTF8 with BOM
	utf8,				// UTF8 without BOM
	utf16_le_bom,		// UTF16 LE with BOM
	utf16_le,			// UTF16 LE without BOM
	utf16_be_bom,		// UTF16-BE with BOM
	utf16_be,			// UTF16-BE without BOM
};

inline bool is_utf8(det_encoding d) {
	return d == det_encoding::utf8 || d == det_encoding::utf8_bom;
}


class Utf8Det {
private:
	std::unique_ptr<AutoIt::Common::TextEncodingDetect> det;

public:
	Utf8Det();
	~Utf8Det() = default;

	Utf8Det(const Utf8Det& d) = delete;
	const Utf8Det& operator=(const Utf8Det d) = delete;

	det_encoding scan(const char* buf, size_t buf_size);
};