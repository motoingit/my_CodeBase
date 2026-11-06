public class j00{
    public static void printNum(int i){
        if(i > 0){
            System.out.print(i+" "); //SYSO
            printNum(--i);
        }
    }
    public static void main(String[] args) {
        int n = 5;
        printNum(n);
    }
}
