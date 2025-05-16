#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <vector>
#include <cstdint>
#include <stdexcept>

namespace utils {

class Compression {
public:
    Compression() = default;
    ~Compression() = default;

    /**
     * @brief Comprimi dati raw (buffer)
     * @param data Puntatore ai dati originali
     * @param size Dimensione dati originali in byte
     * @return std::vector<uint8_t> dati compressi
     * @throws std::invalid_argument se dati non validi
     * @throws std::runtime_error se compressione fallisce
     */
    std::vector<uint8_t> compress(const uint8_t* data, size_t size) const;

    /**
     * @brief Comprimi dati raw (std::vector overload)
     * @param data Vettore di dati originali
     * @return std::vector<uint8_t> dati compressi
     */
    std::vector<uint8_t> compress(const std::vector<uint8_t>& data) const;

    /**
     * @brief Decomprimi dati compressi
     * @param data Puntatore ai dati compressi
     * @param size Dimensione dati compressi
     * @param originalSize Dimensione attesa dei dati decompressi (necessaria per decompressione)
     * @return std::vector<uint8_t> dati decompressi
     * @throws std::invalid_argument se dati non validi
     * @throws std::runtime_error se decompressione fallisce
     */
    std::vector<uint8_t> decompress(const uint8_t* data, size_t size, size_t originalSize) const;

    /**
     * @brief Decomprimi dati compressi (std::vector overload)
     * @param data Vettore dati compressi
     * @param originalSize Dimensione dati decompressi attesi
     * @return std::vector<uint8_t> dati decompressi
     */
    std::vector<uint8_t> decompress(const std::vector<uint8_t>& data, size_t originalSize) const;
};

}

#endif // COMPRESSION_HPP
