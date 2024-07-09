#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

class string_t {
public:
    string_t() = default;

    ~string_t() {
        if (m_buffer) {
            m_length = 0;
            delete[] m_buffer;
            m_buffer = nullptr;
        }
    }

    explicit string_t(const char *str) {
        m_length = std::strlen(str);
        m_buffer = new char[m_length + 1];
        m_buffer[m_length] = '\0';
        std::copy_n(str, m_length, m_buffer);
    }

    string_t(const string_t &other) : m_length(other.m_length) {
        m_buffer = new char[other.m_length + 1];
        std::copy_n(other.m_buffer, other.m_length, m_buffer);
        m_buffer[other.m_length] = '\0';
    }

    string_t(string_t &&other) noexcept : m_length(other.m_length), m_buffer(other.m_buffer) {
        other.m_length = 0;
        other.m_buffer = nullptr;
    }

    string_t &operator=(const string_t &other) {
        if (this != &other) {
            m_length = other.m_length;
            m_buffer = new char[other.m_length + 1];
            std::copy_n(other.m_buffer, other.m_length, m_buffer);
            m_buffer[other.m_length] = '\0';
        }
        return *this;
    }

    string_t &operator=(string_t &&other) noexcept {
        if (this != &other) {
            m_length = other.m_length;
            m_buffer = other.m_buffer;
            other.m_length = 0;
            other.m_buffer = nullptr;
        }
        return *this;
    }

    size_t length() const { return m_length; }

    friend std::ostream &operator<<(std::ostream &os, const string_t &string) {
        if (string.m_buffer) {
            os << string.m_buffer;
        }
        return os;
    }

private:
    size_t m_length = 0;
    char *m_buffer = nullptr;
};
