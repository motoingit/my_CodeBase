//Question : Push all targetChar to the last of the given string
public class j09_push_all_e{
    public static void pushTarget(String atr, StringBuilder btr, char target, int idx){

        if(atr.length() == idx) //todo : base
            return;

        //on stacking (appending non-x)
        if( atr.charAt(idx) != target){
            btr.append(atr.charAt(idx));
        }

        pushTarget(atr, btr, target, idx + 1); //* idx is incremeting here */

        // on de-stacking (appending x)
        if(atr.charAt(idx) == target){
            btr.append(atr.charAt(idx));
        }
        
    }

    public static void main(String[] args) {
        String orgString = "mississippi";
        char target = 's';

        StringBuilder newString = new StringBuilder("");
        pushTarget(orgString, newString, target, 0);
        System.out.println(newString);
    }
}
