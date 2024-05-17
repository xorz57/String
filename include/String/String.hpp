#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

class String {
public:
  String() = default;

  ~String() {
    if (mBuffer) {
      mLength = 0;
      delete[] mBuffer;
      mBuffer = nullptr;
    }
  }

  explicit String(const char *str) {
    mLength = std::strlen(str);
    mBuffer = new char[mLength + 1];
    mBuffer[mLength] = '\0';
    std::copy_n(str, mLength, mBuffer);
  }

  String(const String &other) : mLength(other.mLength) {
    mBuffer = new char[other.mLength + 1];
    std::copy_n(other.mBuffer, other.mLength, mBuffer);
    mBuffer[other.mLength] = '\0';
  }

  String(String &&other) noexcept
      : mLength(other.mLength), mBuffer(other.mBuffer) {
    other.mLength = 0;
    other.mBuffer = nullptr;
  }

  String &operator=(const String &other) {
    if (this != &other) {
      mLength = other.mLength;
      mBuffer = new char[other.mLength + 1];
      std::copy_n(other.mBuffer, other.mLength, mBuffer);
      mBuffer[other.mLength] = '\0';
    }
    return *this;
  }

  String &operator=(String &&other) noexcept {
    if (this != &other) {
      mLength = other.mLength;
      mBuffer = other.mBuffer;
      other.mLength = 0;
      other.mBuffer = nullptr;
    }
    return *this;
  }

  size_t length() const { return mLength; }

  friend std::ostream &operator<<(std::ostream &os, const String &string) {
    if (string.mBuffer) {
      os << string.mBuffer;
    }
    return os;
  }

private:
  size_t mLength = 0;
  char *mBuffer = nullptr;
};
