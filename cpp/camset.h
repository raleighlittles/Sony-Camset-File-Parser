/**
 * @file camset.h
 * @author your name (you@domain.com)
 * @brief Class representing a Camset file
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <string>
#include <array>
#include <cstdint>
#include <fstream>
#include <filesystem>

class Camset
{

  public:

    Camset(const std::filesystem::path filePath) {

        std::ifstream camsetFile(filePath, std::ios::in | std::ios::binary);

        // TODO: I don't know which one is the right one to use.
        if (camsetFile.is_open() && camsetFile.good()) {
            camsetFile.read(reinterpret_cast<char*>(mCamsetData.data()), mCamsetFileSize);
        }
    }

    /// Getters ///
    std::string getCameraMakeModel(void) const {

        // First 4 bytes are the Make, always 'SONY'
        std::string make = std::string(reinterpret_cast<const char*>(mCamsetData.data()), 4);

        // 5th byte is a '!', skip it
        // 6th byte thru 14th byte have the 'Model' (always 'ILCE-7RM4')
        std::string model = std::string(reinterpret_cast<const char*>(mCamsetData.data() + 5), /* 15 - 6 = */ 9);

        return (make + model);
    }

    std::string getFileDate(void) const;
    std::string getFileName(void) const;


  private:
    static const int mCamsetFileSize = 9216;
    std::array<std::byte, mCamsetFileSize> mCamsetData;
};