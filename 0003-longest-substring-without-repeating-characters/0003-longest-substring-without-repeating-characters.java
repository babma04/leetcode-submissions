class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> m = new HashMap<>();
        int max = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (m.containsKey(c)) {
                start = Math.max(start, m.get(c));
            }
            max = Math.max(max, i - start + 1);
            m.put(c, i + 1);
        }
        return max;
    }
}