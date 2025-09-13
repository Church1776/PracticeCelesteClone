#include "platform.h"
#include "gl_renderer.h"
#include "base_lib.h"

//################################################################################################################################
//                                                         Bump Allocator
//################################################################################################################################



BumpAllocator make_bump_allocator(size_t size){
    
    BumpAllocator ba = {};
    
    ba.memory = (char*)malloc(size);
    if(ba.memory){
        ba.capacity = size; 
        memset(ba.memory, 0, size);   
    }else{
        SM_ASSERT(false, "Failed to allocate memory!");
    }
    
    return ba;    
}

char* bump_alloc(BumpAllocator* alloc, size_t size){
    
    char* result = nullptr;
    
    size_t allignedSize = (size + 7) & ~ 7;
    if(alloc->used + allignedSize <= alloc->capacity){
        result = alloc->memory + alloc->used;
        alloc->used += allignedSize;
    }else{
        SM_ASSERT(false, "BumpAllocator is full!");
    }
    
    return result;
}

//################################################################################################################################
//                                                            File I/O
//################################################################################################################################

long long get_timestamp(const char* file){
    struct stat file_stat = {};
    stat(file, &file_stat);
    return file_stat.st_mtime;
}

bool file_exists(const char* filePath){
    SM_ASSERT(filePath, "No file path supplied!");
    
    auto file = fopen(filePath, "rb");
    if(!file){
        return false;
    }
    fclose(file);
    
    return true;
}

long get_file_size(const char* filePath){
    SM_ASSERT(filePath, "No file path supplied!");
    
    long fileSize = 0;
    auto file = fopen(filePath, "rb");
    if(!file){
        SM_ERROR("Failed opening file: %s", filePath);
        return 0;
    }
    
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    
    return fileSize;
}

char* read_file(const char* filePath, int* fileSize, char* buffer){
    
    SM_ASSERT(filePath, "No file path supplied!");
    SM_ASSERT(fileSize, "No file size supplied!");
    SM_ASSERT(buffer, "No buffer supplied!");
    
    *fileSize = 0;
    auto file = fopen(filePath, "rb");
    if(!file){
        SM_ERROR("Failed opening file: %s", filePath);
        return nullptr;
    }
    
    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    memset(buffer, 0, *fileSize + 1);
    fread(buffer, sizeof(char), *fileSize, file);
    fclose(file);
    
    return buffer;
}

char* read_file(const char* filePath, int* fileSize, BumpAllocator* alloc){
    
    char* file = nullptr;
    long bufferSize = get_file_size(filePath);
    
    if(bufferSize){
        char* buffer = bump_alloc(alloc, bufferSize + 1);
        file = read_file(filePath, fileSize, buffer);
    }
    
    return file;
}

void write_file(const char* filePath, char* buffer, int size){
    
    SM_ASSERT(filePath, "No file path supplied!");
    SM_ASSERT(buffer, "No buffer supplied!");
    auto file = fopen(filePath, "wb");
    if(!file){
        SM_ERROR("Failed opening file: %s", filePath);
        return;
    }
    
    fwrite(buffer, sizeof(char), size, file);
    fclose(file);    
}

bool copy_file(const char* fileName, const char* outputName, char* buffer){
    
    int fileSize = 0;
    char* data = read_file(fileName, &fileSize, buffer);
    
    auto outputFile = fopen(outputName, "wb");
    if(!outputFile){
        SM_ERROR("Failed opening file: %s", outputName);
        return false;
    }
    
    int result = fwrite(data, sizeof(char), fileSize, outputFile);
    if(!result){
        SM_ERROR("Failed opening file: %s", outputName);
        return false;
    }
    
    fclose(outputFile);
    
    return true;
}

bool copy_file(const char* fileName, const char* outputName, BumpAllocator* alloc){
    
    char* file = nullptr;
    long bufferSize = get_file_size(fileName);
    
    if(bufferSize){
        char* buffer = bump_alloc(alloc, bufferSize + 1);
        return copy_file(fileName, outputName, buffer);
    }
    
    return false;
}
