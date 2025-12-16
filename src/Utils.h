#pragma once

#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

template <std::size_t N>
void CopyToFixedBuffer(char (&dest)[N], const char* src) {
    if (src != 0) {
        std::strncpy(dest, src, N - 1);
    } else {
        dest[0] = '\0';
    }
    dest[N - 1] = '\0';
}

template <std::size_t N>
void CopyToFixedBuffer(char (&dest)[N], const std::string& src) {
    CopyToFixedBuffer(dest, src.c_str());
}

template <typename T>
void printField(
    std::ostream& os, const char* eng, const char* chi, const T& value, int engWidth = 18, int chiWidth = 14) {
    os << "  " << std::left << std::setw(engWidth) << eng << std::left << std::setw(chiWidth) << chi << value << '\n';
}
