package exceptions;

public class _2 {
    _2 obj;
    public _2 getObj () {
        return obj;
    }
    public static void main(String[] args) {
        try {
            _2 obj = new _2();
            if (obj.getObj() == null) {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

