class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                int j = 0;
                while (j <= i) {
                    swap(word[j++], word[i--]);
                }
                break;
            }
        }
        return word;
    }
};