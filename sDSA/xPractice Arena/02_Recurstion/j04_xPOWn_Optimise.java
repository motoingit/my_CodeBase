public class j04_xPOWn_Optimise{ //!       form   n to logn
    public static int pow(int x, int n) { //todo : height of stack is n ~~
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;

        if (n%2 == 1)
            return pow(x, n/2) * pow(x, n/2) * x;
        else{
            return pow(x, n/2) * pow(x, n/2);
        }
    }
    public static void main(String[] args) {
        int n = 7, x = 5;
        int xPOWn = pow(x,n);
        System.out.println(xPOWn + " is the x^n");
    }
}
