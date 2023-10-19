#ifndef LCL_BIN_ARY_HPP_
#define LCL_BIN_ARY_HPP_
#include <stdint.h>
#include <cstddef>
#define LCLLIB_LITTLE_ENDIAN true
#define LCLLIB_BIG_ENDIAN false
namespace LCLLib{
    typedef uint8_t byte ;
    class BINarySetter;
    class BINary{
        byte* data;
        size_t sizeInByte;
        public:
        BINary(byte* data,size_t length);
        BINary();
        BINary(uint8_t i8);
        BINary(uint16_t i16);
        BINary(uint32_t i32);
        BINary(float f32);
        BINary(double f64);
        BINary(uint64_t i64);
        void set(size_t sz,bool idx);
        bool get(size_t sz);
        BINarySetter operator[](size_t idx);
        // Returns the bit-length
        size_t length(); 
        // Returns the byte-size
        size_t size();
        //
        char* toString(bool isLittleEndian);
    };
    class BINarySetter{
        private:
        BINary ref;
        size_t idx;
        public:
        BINarySetter(BINary ref,size_t idx);
        BINarySetter& operator=(bool& bit);
        operator bool();
        operator BINary();
    };
}
#endif