#include "Compression.hpp"
#include <zlib.h>
#include <cstring>  // for memcpy

namespace utils {

std::vector<uint8_t> Compression::compress(const uint8_t* data, size_t size) const
{
    if (!data || size == 0)
        throw std::invalid_argument("Dati non validi per la compressione");

    uLongf compressedSize = compressBound(size);
    std::vector<uint8_t> compressedData(compressedSize);

    int res = compress2(compressedData.data(), &compressedSize, data, size, Z_BEST_COMPRESSION);
    if (res != Z_OK) {
        throw std::runtime_error("Compression failed with zlib error code: " + std::to_string(res));
    }

    compressedData.resize(compressedSize);
    return compressedData;
}

std::vector<uint8_t> Compression::compress(const std::vector<uint8_t>& data) const
{
    return compress(data.data(), data.size());
}

std::vector<uint8_t> Compression::decompress(const uint8_t* data, size_t size, size_t originalSize) const
{
    if (!data || size == 0 || originalSize == 0)
        throw std::invalid_argument("Dati non validi per la decompressione");

    std::vector<uint8_t> decompressedData(originalSize);

    uLongf destLen = originalSize;
    int res = uncompress(decompressedData.data(), &destLen, data, size);

    if (res != Z_OK) {
        throw std::runtime_error("Decompression failed with zlib error code: " + std::to_string(res));
    }

    if (destLen != originalSize) {
        // Questa condizione è rara, ma meglio gestirla
        decompressedData.resize(destLen);
    }

    return decompressedData;
}

std::vector<uint8_t> Compression::decompress(const std::vector<uint8_t>& data, size_t originalSize) const
{
    return decompress(data.data(), data.size(), originalSize);
}

}