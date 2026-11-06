public class j02_Factorial{
    public static int nFactorial(int n){
        if(n == 1){
            System.out.print("1 = ");
            return 1;
        }
        System.err.print(n+" x ");
        return n*nFactorial(--n);
    }
    public static void main(String[] args) {
        int n = 5;
        int nFact = nFactorial(n);
        System.out.println(nFact);
    }
}
