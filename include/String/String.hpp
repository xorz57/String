#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

class string_t {
public:
  string_t() = default;

  ~string_t() {
    if (mBuffer) {
      mLength = 0;
      delete[] mBuffer;
      mBuffer = nullptr;
    }
  }

  explicit string_t(const char *str) {
    mLength = std::strlen(str);
    mBuffer = new char[mLength + 1];
    mBuffer[mLength] = '\0';
    std::copy_n(str, mLength, mBuffer);
  }

  string_t(const string_t &other) : mLength(other.mLength) {
    mBuffer = new char[other.mLength + 1];
    std::copy_n(other.mBuffer, other.mLength, mBuffer);
    mBuffer[other.mLength] = '\0';
  }

  string_t(string_t &&other) noexcept
      : mLength(other.mLength), mBuffer(other.mBuffer) {
    other.mLength = 0;
    other.mBuffer = nullptr;
  }

  string_t &operator=(const string_t &other) {
    if (this != &other) {
      mLength = other.mLength;
      mBuffer = new char[other.mLength + 1];
      std::copy_n(other.mBuffer, other.mLength, mBuffer);
      mBuffer[other.mLength] = '\0';
    }
    return *this;
  }

  string_t &operator=(string_t &&other) noexcept {
    if (this != &other) {
      mLength = other.mLength;
      mBuffer = other.mBuffer;
      other.mLength = 0;
      other.mBuffer = nullptr;
    }
    return *this;
  }

  size_t length() const { return mLength; }

  friend std::ostream &operator<<(std::ostream &os, const string_t &string) {
    if (string.mBuffer) {
      os << string.mBuffer;
    }
    return os;
  }

private:
  size_t mLength = 0;
  char *mBuffer = nullptr;
};
