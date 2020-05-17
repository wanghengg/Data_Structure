/*
 * BitMap数据结构，数组的每一bit是1代表该索引有值，为0则没有
 */

#ifndef DATA_STRUCTURE_BITMAP_H
#define DATA_STRUCTURE_BITMAP_H

#include <cstring>
#include <cstdlib>

class BitMap{
private:
    char *bitmap;
    std::size_t size;
public:
    BitMap() : size(10000) {
        bitmap = new char [size];
        std::memset(bitmap, 0, size * sizeof(char));
    }

    explicit BitMap(std::size_t n) : size(n) {
        bitmap = new char [size];
        std::memset(bitmap, 0, size * sizeof(char));
    }

    ~BitMap() { delete [] bitmap; }

    bool get(int x) {
        int cur = x >> 3;
        int red = x & 7;
        if (cur >= size) return false;
        return bitmap[cur] & (0x80 >> red);
    }

    bool set(int x) {
        int cur = x >> 3;
        int red = x & 7;
        if (cur >= size) return false;
        bitmap[cur] |= (0x80 >> red);
        return true;
    }
};

#endif //DATA_STRUCTURE_BITMAP_H
