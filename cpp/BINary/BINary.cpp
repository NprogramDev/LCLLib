#include "BINary.hpp"
#include <iostream>
using namespace LCLLib;
BINary::BINary(byte *data, size_t sizeInByte)
{
    this->data = data;
    this->sizeInByte = sizeInByte;
}
BINary::BINary() : BINary::BINary(new byte[0], 0)
{
}
BINary::BINary(uint8_t i8)
{
    this->sizeInByte = 1;
    this->data = new byte[sizeInByte]{i8};
}
BINary::BINary(uint16_t i16)
{
    this->sizeInByte = 2;
    this->data = new byte[sizeInByte]{0};

    for (size_t i = 0; i < this->sizeInByte; i++)
    {
        this->data[i] = i16;
        i16 >>= 8;
    }
}
BINary::BINary(uint32_t i32)
{
    
    this->sizeInByte = 4;
    this->data = new byte[sizeInByte]{0};
    for (size_t i = 0; i < this->sizeInByte; i++)
    {
        this->data[i] = i32;
        i32 >>= 8;
    }
}
BINary::BINary(float f32)
{
    uint32_t i32 = *((uint32_t*) &f32);
    this->sizeInByte = 4;
    this->data = new byte[sizeInByte]{0};
    for (size_t i = 0; i < this->sizeInByte; i++)
    {
        this->data[i] = i32;
        i32 >>= 8;
    }
}
BINary::BINary(uint64_t i64)
{
    this->sizeInByte = 8;
    this->data = new byte[sizeInByte]{0};
    for (size_t i = 0; i < this->sizeInByte; i++)
    {
        this->data[i] = i64;
        i64 >>= 8;
    }
}

BINary::BINary(double f64)
{
    uint64_t i64 = *((uint64_t*)&f64);
    this->sizeInByte = 8;
    this->data = new byte[sizeInByte]{0};
    for (size_t i = 0; i < this->sizeInByte; i++)
    {
        this->data[i] = i64;
        i64 >>= 8;
    }
}

size_t indexTBinray(size_t i)
{
    switch (i)
    {
    case 0:
        return 0b1;

    case 1:
        return 0b10;

    case 2:
        return 0b100;

    case 3:
        return 0b1000;

    case 4:
        return 0b10000;

    case 5:
        return 0b100000;

    case 6:
        return 0b1000000;
    case 7:
        return 0b10000000;

    case 8:
        return 0b0;

    default:
        return 0b0;
    }
}
bool BINary::get(size_t idx)
{
    size_t i = idx / 8;
    size_t k = indexTBinray(idx% 8);
    if (i >= this->sizeInByte)
        return true;
    return (this->data[i] & k) != 0;
}
void BINary::set(size_t idx, bool bit)
{
    int i = idx / 8;
    int k = indexTBinray(idx % 8);
    if(bit){
        this->data[i] |= k;
    }else{
        this->data[i] &= ~k;
    }
}
char *BINary::toString(bool isLittleEndian)
{
    char *rt = new char[this->length() + 1]{0};
    size_t j = 0;
    for (size_t i = (isLittleEndian ? this->length() - 1 : 0); (isLittleEndian ? i + 1 > 0 : i < this->length()); (isLittleEndian ? --i : ++i))
    {
        rt[j] = (this->get(i) ? '1' : '0');
        j++;
    }
    rt[this->length()] = 0;
    return rt;
}
size_t BINary::length()
{
    return this->sizeInByte * 8;
}
size_t BINary::size()
{
    return this->sizeInByte;
}
BINarySetter BINary::operator[](size_t idx)
{
    BINarySetter rt(*this, idx);
    return rt;
}
BINarySetter::BINarySetter(BINary ref, size_t idx)
{
    this->ref = ref;
    this->idx = idx;
}
BINarySetter::operator bool()
{
    return ref.get(idx);
}
BINarySetter::operator BINary()
{
    return ref;
}
BINarySetter &BINarySetter::operator=(bool &bit)
{
    ref.set(this->idx, bit);
    return *this;
}
