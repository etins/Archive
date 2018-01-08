package access;

import java.util.Arrays;

public class _8 {
    private _8() {}
    int[] Connection = {1, 2, 3};
    private static _8 singleObj = new _8();
    static _8 ConnectionManager() {
        return singleObj;
    }

    public static void main(String[] args) {
        _8 obj = _8.ConnectionManager();
        System.out.println(Arrays.toString(obj.Connection));
    }

}
