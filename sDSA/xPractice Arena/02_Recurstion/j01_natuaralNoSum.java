public class j01_natuaralNoSum{
    public static int SumOfN_Natural(int n){
        if(n == 0){
            return 0;
        }
        return n+SumOfN_Natural(--n);
    }
    public static void main(String[] args) {
        int n = 100;
        int sumN = SumOfN_Natural(n);
        System.out.println("SUm of first Natual : "+sumN);
    }
}
