import java.util.Stack;

class Solution {
    // Helper function to remove all instances of a given substring using a stack
    public String remove(String s, String pattern) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (!stack.isEmpty() && curr == pattern.charAt(1) && stack.peek() == pattern.charAt(0)) {
                stack.pop(); // matched the pattern, remove it
            } else {
                stack.push(curr);
            }
        }

        // Rebuild string from stack
        StringBuilder ans = new StringBuilder();
        while (!stack.isEmpty()) {
            ans.append(stack.pop());
        }
        return ans.reverse().toString();
    }

    public int maximumGain(String s, int x, int y) {
        int ans = 0;

        String maxStr = (x > y) ? "ab" : "ba";
        String minStr = (x > y) ? "ba" : "ab";

        int n = s.length();

        // First remove the more profitable substring
        String first = remove(s, maxStr);
        int l = first.length();
        ans += ((n - l) / 2) * Math.max(x, y);

        // Then remove the less profitable substring
        String last = remove(first, minStr);
        int l1 = last.length();
        ans += ((l - l1) / 2) * Math.min(x, y);

        return ans;
    }
}
