class Solution {

    public String add0(String str, int length) {
        StringBuilder stringBuilder = new StringBuilder(length);
        for (int i = 0; i < length - str.length(); i++) {
            stringBuilder.append('0');
        }
        return stringBuilder.append(str).toString();
    }

    public int minFlips(int a, int b, int c) {
        String as = Integer.toBinaryString(a);
        String bs = Integer.toBinaryString(b);
        String cs = Integer.toBinaryString(c);
        int maxLength = Math.max(Math.max(as.length(), bs.length()), cs.length());
        as = add0(as, maxLength);
        bs = add0(bs, maxLength);
        cs = add0(cs, maxLength);
        int result = 0;
        for (int i = 0; i < maxLength; i++) {
            if (cs.charAt(i) == '1') {
                if (as.charAt(i) == '0' && bs.charAt(i) == '0') {
                    result += 1;
                }
            } else {
                if (as.charAt(i) == '1' && bs.charAt(i) == '1') {
                    result += 2;
                } else if (as.charAt(i) == '1' || bs.charAt(i) == '1') {
                    result += 1;
                }
            }
        }
        return result;
    }
}