#define DO_UNIT_TEST 0
#if DO_UNIT_TEST
#include <gtest/gtest.h>
#else
#include <word_reader.h>
#include <array_list.h>
#include <array_list_utility.h>
#include <iostream>
#include <unordered_map.h>

// A simple class to keep a pair: word and count (from the map)
class WordFreq
{
public:
    std::string mWord;
    unsigned int mCount;
    WordFreq() : mWord(""), mCount(0) {}
    WordFreq(std::string w, unsigned int c) : mWord(w), mCount(c) {}
};

bool operator< (const WordFreq& a, const WordFreq& b) { return a.mCount < b.mCount; }
bool operator> (const WordFreq& a, const WordFreq& b) { return a.mCount > b.mCount; }
bool operator== (const WordFreq& a, const WordFreq& b) { return a.mCount == b.mCount; }

#endif

int main()
{
#if DO_UNIT_TEST
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
#else
    misc::WordReader WR("../../../media/books/dracula.txt", misc::WordReader::CharConversion::LOWER);
    ssuds::UnorderedMap<std::string, unsigned int> WC;

    std::cout << "Reading file...";
    while (!WR.done())
    {
        std::string w = WR.get_next();
        if (w.length() > 0)
        {
            if (WC.find(w) == WC.end())
                WC[w] = 1;
            else
                WC[w]++;
        }
    }
    std::cout << "done!\n";

    std::cout << "Sorting...";
    ssuds::ArrayList<WordFreq> WL;
    for (std::pair<std::string, unsigned int> p : WC)
        WL.append(WordFreq(p.first, p.second));
    // quicksort stack overflowed!
    //ssuds::quicksort(WL, ssuds::SortOrder::DESCENDING);
    ssuds::bubblesort(WL, ssuds::SortOrder::DESCENDING);
    std::cout << "done!\n";

    const unsigned int n = 20;
    std::cout << "Top " << n << " words\n";
    std::cout << "===========================\n";
    for (unsigned int i = 0; i < n && i < WL.size(); i++)
        std::cout << i << "\t" << WL[i].mWord << "(" << WL[i].mCount << ")\n";

    return 0;
#endif
}