package com.string_manu;

public class ZigZag_Conversion_6 {

	public static void main(String[] args) {
		// System.out.println(new
		// Solution_ZigZag_Conversion_6().convert("PAYPALISHIRING", 3));
		System.out.println(new Solution_ZigZag_Conversion_6().convert("A", 1));
	}

}

class Solution_ZigZag_Conversion_6 {
	public String convert(String s, int numRows) {
		String[] h_strs = new String[numRows];
		for (int i = 0; i < h_strs.length; i++)
			h_strs[i] = "";

		if (numRows < 3) {
			if (numRows == 1)
				return s;
			if (numRows == 2) {
				int j = 0;
				for (int i = 0; i < s.length(); i++) {
					j = i % 2;
					h_strs[j] += s.charAt(i);
				}
				String re = "";
				for (int i = 0; i < h_strs.length; i++) {
					re += h_strs[i];
				}
				return re;
			}
		}

		int j;
		int i = 0;
		while (i < s.length()) {
			int jishu = i % (2 * numRows - 2);
			if (jishu > numRows - 1) {
				j = 2 * numRows - 2 - jishu;
			} else {
				j = jishu % numRows;
			}
			h_strs[j] = h_strs[j] + s.charAt(i);
			i++;
		}

		String re = "";
		for (i = 0; i < h_strs.length; i++) {
			re += h_strs[i];
		}
		return re;
	}


	public String convert_others(String s, int nRows) {
    char[] c = s.toCharArray();
    int len = c.length;
    StringBuffer[] sb = new StringBuffer[nRows];
    for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();

    int i = 0;
    while (i < len) {
        for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
            sb[idx].append(c[i++]);
        for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up  去掉两头的
            sb[idx].append(c[i++]);
    }
    for (int idx = 1; idx < sb.length; idx++)
        sb[0].append(sb[idx]);
    return sb[0].toString();
	}
}
