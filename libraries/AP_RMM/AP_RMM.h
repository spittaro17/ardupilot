#pragma once 

class RMM {
    void* pool;
    //int* pool_size;
    //bool* top_level;
    //int* free_offset;

    RMM(void* parent_pool, int parent_free_offset, int size_in_bytes);

public:
    RMM(int size_in_bytes = 10 * 1024 * 1024); //default is 10 MB
    ~RMM();

    void* allocate(int size_in_bytes);
    void reset();

    RMM* create_nested_region(int size_in_bytes);

    void create_new_pool(int);

    void print_status();

    void dump_region();

    //This Function Would Be Ardu Specific
   // void repopulate_regions();

private:
    const int TOP_LEVEL= 0;
    const int SIZE= 0+sizeof(int);
    const int OFFSET= 0+sizeof(int)+sizeof(int);
    const int FULL= 0+sizeof(int)+sizeof(int)+sizeof(int);

    void init_allocate(int size_in_bytes);
};
