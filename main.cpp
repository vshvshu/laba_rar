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

int main()
{
    ifstream file("C:\\study\\labRar\\Example.rar", ios::binary);
    if(file.is_open())
        {

        file.seekg(0, ios::end);
        int sizeFile = file.tellg();
        file.seekg(0, ios::beg);

        vector<char> array(sizeFile, 0);

        file.read(array.data(), sizeFile);

        int index = 20;
        }
        while(true)
            {

            head* p_header = reinterpret_cast<head*> (&array[index]);
            index += 7;

            if(int(p_header->header_type) != 116)
            {
                break;
            }
            else
                {
                file_head* d_header = reinterpret_cast<file_head*> (&array[index]);
                index += 25;

                for(int i = index; i < index + int(d_header->name_size);i++){
                    cout << array[i];
                }
                index -= 25;
                cout << endl;
                index -= 7;
                index += int(d_header->pack_size);
                index +=  p_header->header_size;
            }
        }
    }
    return 0;
}
