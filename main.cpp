#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
using namespace std;

#pragma pack (push, 1)

struct head
{
    uint16_t header_crc;
    char  header_type;
    uint16_t header_flag;
    uint16_t header_size;
};

struct file_head
{
    uint32_t pack_size;
    uint32_t unp_size;
    char host_OS;
    uint32_t file_crc;
    uint32_t file_time;
    char unp_ver;
    char metod;
    uint16_t name_size;
    uint32_t file_attr;
};

struct main_head
{
    uint16_t high_posav;
    uint32_t pos_AV;
};

#pragma pack(pop)
