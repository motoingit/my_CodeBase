public class j03_fibonnaci_nth{
    public static int nthFabonaci(int n){
        if(n == 1){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        
        return nthFabonaci(n-1) + nthFabonaci(n-2);
    }
                //todo:              0  1   1   2   3   5   8   13
    public static void main(String[] args) {
        int n = 8;
        int nth = nthFabonaci(n);
        System.out.println(nth);
    }
}
