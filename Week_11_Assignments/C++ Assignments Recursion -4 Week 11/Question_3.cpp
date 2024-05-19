int longestCommonSubstringHelper(string s1, string s2, int m, int n, int count) {
    if (m == 0 || n == 0) {
        return count;
    }

    int count1 = count;
    if (s1[m - 1] == s2[n - 1]) {
        count1 = longestCommonSubstringHelper(s1, s2, m - 1, n - 1, count + 1);
    }

    int count2 = longestCommonSubstringHelper(s1, s2, m, n - 1, 0);
    int count3 = longestCommonSubstringHelper(s1, s2, m - 1, n, 0);

    return max(count1, max(count2, count3));
}

int longestCommonSubstring(string s1, string s2) {
    return longestCommonSubstringHelper(s1, s2, s1.size(), s2.size(), 0);
}
