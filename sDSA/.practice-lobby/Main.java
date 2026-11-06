/*
Your OS pseudocode essentially says:

Producer:
    wait(empty)
    wait(mutex)

        insert item into buffer

    signal(mutex)
    signal(full)


Consumer:
    wait(full)
    wait(mutex)

        remove item from buffer

    signal(mutex)
    signal(empty)
*/

class Consumer implements Runnable{
  public static void put(){
    
  }
}
