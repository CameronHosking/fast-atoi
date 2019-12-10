
static const uint64_t offsets[21] = {0,'0',
        '0'*11ull,
        '0'*111ull,
        '0'*1111ull,
        '0'*11111ull,
        '0'*111111ull,
        '0'*1111111ull,
        '0'*11111111ull,
        '0'*111111111ull,
        '0'*1111111111ull,
        '0'*11111111111ull,
        '0'*111111111111ull,
        '0'*1111111111111ull,
        '0'*11111111111111ull,
        '0'*111111111111111ull,
        '0'*1111111111111111ull,
        '0'*11111111111111111ull,
        '0'*111111111111111111ull,
        '0'*1111111111111111111ull,
        '0'*11111111111111111111ull};

//convert char *s to an unsigned 64bit integer
uint32_t atoui32(const char *s)
{
    uint64_t ret = s[0];
    uint8_t len = 1;
    while(s[len])
    {
        ret = ret*10 + s[len++];
    }
    return ret-offsets[len];
}

//convert char *s to an unsigned 32bit integer
uint32_t atoui32(const char *s)
{
    uint32_t ret = s[0];
    uint8_t len = 1;
    while(s[len])
    {
        ret = ret*10 + s[len++];
    }
    return ret-offsets[len];
}

//convert char *s to an unsigned 64bit integer
//len is the number of numeric characters
//s does not require the trailing '\0'
uint64_t atoui64(const char *str, uint8_t len)
{
    size_t value = 0;
    switch (len) { // handle up to 20 digits, assume we're 64-bit
        case 20:    value += str[len-20] * 10000000000000000000ull;
        case 19:    value += str[len-19] * 1000000000000000000ull;
        case 18:    value += str[len-18] * 100000000000000000ull;
        case 17:    value += str[len-17] * 10000000000000000ull;
        case 16:    value += str[len-16] * 1000000000000000ull;
        case 15:    value += str[len-15] * 100000000000000ull;
        case 14:    value += str[len-14] * 10000000000000ull;
        case 13:    value += str[len-13] * 1000000000000ull;
        case 12:    value += str[len-12] * 100000000000ull;
        case 11:    value += str[len-11] * 10000000000ull;
        case 10:    value += str[len-10] * 1000000000ull;
        case  9:    value += str[len- 9] * 100000000ull;
        case  8:    value += str[len- 8] * 10000000ull;
        case  7:    value += str[len- 7] * 1000000ull;
        case  6:    value += str[len- 6] * 100000ull;
        case  5:    value += str[len- 5] * 10000ull;
        case  4:    value += str[len- 4] * 1000ull;
        case  3:    value += str[len- 3] * 100ull;
        case  2:    value += str[len- 2] * 10ull;
        case  1:    value += str[len- 1];
    }
    return value - offsets[len];
}

//convert char *s to an unsigned 32bit integer
//len is the number of numeric characters
//s does not require the trailing '\0'
uint32_t strToSmallUint(const char *str, uint8_t len)
{
    uint32_t value = 0;
    switch (len) { // handle up to 10 digits, assume we're 32-bit
            case 10:    value += str[len-10] * 1000000000;
            case  9:    value += str[len- 9] * 100000000;
            case  8:    value += str[len- 8] * 10000000;
            case  7:    value += str[len- 7] * 1000000;
            case  6:    value += str[len- 6] * 100000;
            case  5:    value += str[len- 5] * 10000;
            case  4:    value += str[len- 4] * 1000;
            case  3:    value += str[len- 3] * 100;
            case  2:    value += str[len- 2] * 10;
            case  1:    value += str[len- 1];
        }
    return value - offsets[len];
}
