public class j13_PrintKey_combination {

    static String[] keypad = {
        ".",     // 0
        "abc",   // 1
        "def",   // 2
        "ghi",   // 3
        "jkl",   // 4
        "mno",   // 5
        "pqrs",  // 6
        "tu",    // 7
        "vwx",   // 8
        "yz"     // 9
    };

    public static void printCombo(int[] arr, int idx, String result) {
        if (idx == arr.length) {
            System.out.println("{" + result + "}");
            return;
        }

        String letters = keypad[arr[idx]];

        for (int i = 0; i < letters.length(); i++) {
            printCombo(arr, idx + 1, result + letters.charAt(i));
        }
    }

    public static void main(String[] args) {
        int[] arr = {6, 7};
        printCombo(arr, 0, "");
    }
}
