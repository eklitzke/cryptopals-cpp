#pragma once

#include "./buffer.h"
#include "./problem.h"
#include "./util.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#define DECLARE(x, y) \
  virtual std::pair<int, int> number() const { return {x, y}; }

namespace cryptopals {
struct Problem_1_1 : Problem {
 public:
  DECLARE(1, 1)

  virtual bool test() {
    Buffer input(
        "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f6973"
        "6f6e6f7573206d757368726f6f6d",
        true);
    return input.encode_base64() ==
           "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  }
};

struct Problem_1_2 : Problem {
 public:
  DECLARE(1, 2)

  virtual bool test() {
    Buffer a("1c0111001f010100061a024b53535009181c");
    Buffer b("686974207468652062756c6c277320657965");
    a ^= b;
    return a.encode_hex() == "746865206b696420646f6e277420706c6179";
  }
};

struct Problem_1_3 : Problem {
 public:
  DECLARE(1, 3)

  virtual bool test() {
    std::string best_string;
    float best_score = 1000;

    for (int key = 0; key <= 255; key++) {
      Buffer buf(
          "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b373"
          "6");
      buf.xor_byte(static_cast<uint8_t>(key));
      std::string s = buf.encode_raw();
      float score = score_string(s);
      if (score < best_score) {
        best_score = score;
        best_string = s;
      }
    }
    return best_string == "Cooking MC's like a pound of bacon";
  }
};

struct Problem_1_4 : Problem {
 public:
  DECLARE(1, 4)

  virtual bool test() {
    std::vector<std::string> inputs;
    std::ifstream infile("data/4.txt");
    std::string line;

    std::string best_string;
    float best_score = 1000;

    while (std::getline(infile, line)) {
      assert(line.size() <= 60);
      for (int key = 0; key <= 255; key++) {
        Buffer buf(line);
        buf.xor_byte(static_cast<uint8_t>(key));
        std::string s = buf.encode_raw();
        float score = score_string(s);
        if (score < best_score) {
          best_score = score;
          best_string = s;
        }
      }
    }
    return best_string == "Now that the party is jumping\n";
  }
};

void add_solutions(ProblemManager *manager);
}  // namespace cryptopals
