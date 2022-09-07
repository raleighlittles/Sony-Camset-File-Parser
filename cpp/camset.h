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
        // 6th byte thru 15th byte have the 'Model' (always 'ILCE-7RM4')
        std::string model = std::string(reinterpret_cast<const char*>(mCamsetData.data() + 5), /* 15 - 6 = */ 9);

        return (make + model);
    }

    std::string getFileDate(void) const {
        // TODO: Eventually refactor to have separate getYear(), getMonth(), getDay(), etc

        // Date starts at byte 21, goes for 13 bytes, ending at byte 34
        // Has the format <YYYYMMDD_HHMM>, in 24-hour time
        // Example: "20220906_1323"

        return std::string(reinterpret_cast<const char*>(mCamsetData.data() + 21), 13);
    }


    std::string getFileName(void) const {
        // I'm not entirely sure the format of this, I'm just assuming it looks the same every time

        // Filename looks like: 'CAMSET01.DAT'
        // Starts at byte 40, goes for 12 bytes, up to byte 52

        return std::string(reinterpret_cast<const char*>(mCamsetData.data() + 40), 12);
    }


  private:
    static const int mCamsetFileSize = 9216;
    std::array<std::byte, mCamsetFileSize> mCamsetData;
};