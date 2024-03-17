public class Main {
    public static void main(String[] args) {
        FQueue<Character> s = new FQueue(); //nie mozna konkretywzowac szablonu typem podstawowym -> nie <char>
        FQueue<Integer> s1 = new FQueue();
        try {
            s.Enqueue('A');
            s.Enqueue('B');
            s.Enqueue('C');

            s1.Enqueue(1);
            s1.Enqueue(2);
            s1.Enqueue(3);

            System.out.println( s.Dequeue () + " " + s.Dequeue() );
            System.out.println( s.Dequeue() );

            System.out.println( s1.Dequeue() + " " + s1.Dequeue() );
            System.out.println( s1.Dequeue() );
            System.out.println( s1.Dequeue() ); //wyjatek
      }
        catch( FifoException e ){
            System.out.println( "Exception: " + e.getReason() );
        }
    }
}