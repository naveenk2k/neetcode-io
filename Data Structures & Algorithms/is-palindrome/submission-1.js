class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        s = s.toLocaleLowerCase()
            .split('')
            .filter(c => (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            .join('');
        let i = 0, j = s.length - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
}
