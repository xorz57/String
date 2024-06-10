# String

```cpp
#include "String/String.hpp"

#include <utility>

int main() {
    string_t s0;

    string_t s1("dead");
    string_t s2("beef");

    string_t s3(s1);
    string_t s4(std::move(s2));

    string_t s5;
    string_t s6;
    s5 = s3;
    s6 = std::move(s4);

    std::cout << "s0: " << s0 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s6: " << s6 << std::endl;

    return 0;
}
```

```console
s0: 
s1: dead
s2:
s3: dead
s4:
s5: dead
s6: beef
```

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/String.git
cd String
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/String.git
cd String
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
