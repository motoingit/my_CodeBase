public class j04_xPOWn{
    public static int pow(int x, int n) { //todo : height of stack is n ~~
        if(n>0)
            return x*pow(x, --n);
        if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        return 1;
    }
    public static void main(String[] args) {
        int n = 4, x = 4;
        int xPOWn = pow(x,n);
        System.out.println(xPOWn + " is the x^n");
    }
}
