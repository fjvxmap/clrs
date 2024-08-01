#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPSArray(const string& pattern, vector<int>& lps) {
  int k = 0;
  lps[1] = 0;

  for (int i = 2; i < pattern.size(); i++) {
    while (k > 0 && pattern[i] != pattern[k + 1]) {
      k = lps[k];
    }
    if (pattern[i] == pattern[k + 1]) {
      k++;
    }
    lps[i] = k;
  }
}

void KMPSearch(const string& text, const string& pattern) {
  int m = pattern.size();
  int n = text.size();

  vector<int> lps(m + 1);
  computeLPSArray(pattern, lps);

  int q = 0;

  for (int i = 1; i < n; i++) {
    while (q > 0 && pattern[q + 1] != text[i]) {
      q = lps[q];
    }
    if (pattern[q + 1] == text[i]) {
      q++;
    }
    if (q == m - 1) {
      cout << (i - m + 1) << " ";
      q = lps[q];
    }
  }
  cout << "\n";
}

int main() {
  string text, pattern;
  getline(cin, text);
  getline(cin, pattern);
  text = " " + text;
  pattern = " " + pattern;
  KMPSearch(text, pattern);
  return 0;
}
