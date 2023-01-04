#include "prim/unicu.h"

using namespace unicu;

bool unicu::isAlphabetic(UChar32 c) {
	return u_isUAlphabetic(c) || isNepali(c);
}

bool unicu::isDigit(UChar32 c) {
	return u_isdigit(c);
}

bool unicu::isWhiteSpace(UChar32 c) {
	return u_isUWhiteSpace(c);
}

bool unicu::isPunct(UChar32 c) {
	return u_ispunct(c) || isPunct128(c);
}

bool unicu::isPunct128(UChar32 c) {
	return (
		(33 <= c && c <= 47) ||
		(60 <= c && c <= 62) ||
		(94 <= c && c <= 96) ||
		(124 <= c && c <= 127)
	);
}

bool unicu::isSingle(UChar32 c) {
	return isChinese(c) || isEmoji(c);
}

bool unicu::isChinese(UChar32 c) {
	return (
		(0x4E00 <= c && c <= 0x9FFF) ||
		(0x3400 <= c && c <= 0x4DBF) ||
		(0x20000 <= c && c <= 0x2A6DF) ||
		(0x2A700 <= c && c <= 0x2B73F) ||
		(0x2B740 <= c && c <= 0x2B81F) ||
		(0x2B820 <= c && c <= 0x2CEAF) ||
		(0xF900 <= c && c <= 0xFAFF) ||
		(0x2F800 <= c && c <= 0x2FA1F)
	);
}

bool unicu::isNepali(UChar32 c) {
	return (
		(0x0900 <= c && c <= 0x097F)
	);
}

bool unicu::isEmoji(UChar32 c) {
	return (
		(0x1F004 <= c && c <= 0xE007F) ||
		(0x2194 <= c && c <= 0x2B55)
	);
}

bool unicu::isEmojiJoiner(UChar32 c) {
	return (
		0x200D == c
	);
}

bool unicu::isEmojiVariation(UChar32 c) {
	return (
		(0xFE00 <= c && c <= 0xFE0F) ||		// Variation selector
		(0x1F3FB <= c && c <= 0x1F3FF) ||	// skin tone indicator
		0x2642 == c ||	// male
		0x2640 == c		// female
	);
}

bool unicu::isUpper(UChar32 c) {
	return u_isupper(c);
}

bool unicu::isLower(UChar32 c) {
	return u_islower(c);
}

int unicu::strLen(const UChar *str) {
	return u_strlen(str);
}

int unicu::strCmp(_TCHAR *str1, _TCHAR *str2) {
	icu::UnicodeString ustr1 = icu::UnicodeString::fromUTF8(icu::StringPiece(str1 ));
	const UChar *strBuff1 = reinterpret_cast<const UChar *>(ustr1.getTerminatedBuffer());
	icu::UnicodeString ustr2 = icu::UnicodeString::fromUTF8(icu::StringPiece(str2));
	const UChar *strBuff2 = reinterpret_cast<const UChar *>(ustr2.getTerminatedBuffer());
	return u_strcasecmp(strBuff1, strBuff2, U_COMPARE_IGNORE_CASE);
}

UChar *unicu::contains(_TCHAR *str1, _TCHAR *str2, bool noCase=true) {
	icu::UnicodeString ustr1 = icu::UnicodeString::fromUTF8(icu::StringPiece(str1 ));
	if (noCase)
		ustr1.toLower();
	const UChar *strBuff1 = reinterpret_cast<const UChar *>(ustr1.getTerminatedBuffer());
	icu::UnicodeString ustr2 = icu::UnicodeString::fromUTF8(icu::StringPiece(str2));
	if (noCase)
		ustr2.toLower();
	const UChar *strBuff2 = reinterpret_cast<const UChar *>(ustr2.getTerminatedBuffer());
	return u_strstr(strBuff2,strBuff1);
}