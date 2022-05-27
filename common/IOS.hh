#pragma once

#include <Common.hh>

namespace IOS {

void Init();

enum class Mode : u32 {
    None = 0,
    Read = 1 << 0,
    Write = 1 << 1,
    Both = Write | Read,
};

class Resource {
public:
    struct IoctlvPair {
        void *data;
        u32 size;
    };

    Resource(const Resource &) = delete;
    Resource &operator=(const Resource &) = delete;

protected:
    Resource(const char *path, Mode mode);
    ~Resource();
    s32 ioctl(u32 ioctl, const void *input, u32 inputSize, void *output, u32 outputSize);
    s32 ioctlv(u32 ioctlv, u32 inputCount, u32 outputCount, IoctlvPair *pairs);
    bool ok() const;

private:
    s32 open(const char *path, Mode mode);
    s32 close();

protected:
    s32 m_fd = -1;
};

class File : protected Resource {
public:
    File(const char *path, Mode mode);
    ~File() = default;
    s32 read(void *output, u32 outputSize);
    s32 write(const void *input, u32 inputSize);
    using Resource::ok;
};

} // namespace IOS