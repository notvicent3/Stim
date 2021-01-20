#include <algorithm>
#include <cstring>
#include <immintrin.h>
#include <random>

#include "simd_bit_table.h"
#include "simd_util.h"

simd_bit_table::simd_bit_table(size_t num_bits_major, size_t num_bits_minor) :
    num_bits_major(num_bits_major),
    num_words_minor(ceil256(num_bits_minor) >> 8),
    data(ceil256(num_bits_minor) * num_bits_major) {
}

simd_range_ref simd_bit_table::operator[](size_t major_index) {
    return data.word_range_ref(major_index * num_words_minor, num_words_minor);
}

const simd_range_ref simd_bit_table::operator[](size_t major_index) const {
    return data.word_range_ref(major_index * num_words_minor, num_words_minor);
}

void simd_bit_table::clear() {
    data.clear();
}