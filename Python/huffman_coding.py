import heapq
from collections import defaultdict

def huffman_encoding(data):
    freq = defaultdict(int)
    for char in data:
        freq[char] += 1

    pq = [[weight, [char, ""]] for char, weight in freq.items()]
    heapq.heapify(pq)

    while len(pq) > 1:
        left = heapq.heappop(pq)
        right = heapq.heappop(pq)
        for pair in left[1:]:
            pair[1] = '0' + pair[1]
        for pair in right[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(pq, [left[0] + right[0]] + left[1:] + right[1:])

    huffman_codes = dict(sorted(heapq.heappop(pq)[1:], key=lambda p: (len(p[-1]), p)))

    encoded_data = ''.join(huffman_codes[char] for char in data)
    return encoded_data, huffman_codes

def huffman_decoding(data, huffman_codes):
    reverse_map = {code: char for char, code in huffman_codes.items()}
    decoded_data = ""
    code = ""
    for bit in data:
        code += bit
        if code in reverse_map:
            decoded_data += reverse_map[code]
            code = ""
    return decoded_data

data = "hello"
encoded_data, huffman_codes = huffman_encoding(data)
decoded_data = huffman_decoding(encoded_data, huffman_codes)

