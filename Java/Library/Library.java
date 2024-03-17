import java.util.*;

public class Library {
        private static String[] BOOKS= {
                "Priests Of Dawn",
                "Chicken Abroad",
                "Lord With Sins",
                "Chicken Abroad",
                "Fish And Horses",
                "Mistress Of Devotion",
                "Bandit Of The Void",
                "Lord With Sins",
                "Guardians And Gangsters",
                "Lions Of Dread",
                "Chicken Abroad",
                "Future Of Fire",
                "Priests Of Dawn",
                "Fish And Horses",
                "Chicken Abroad",
                "Fish And Horses",
                "Guardians And Gangsters",
                "Inception Of Heaven",
                "Lord With Sins",
                "Future Of Fire",
                "Driving Into The Depths",
                "Starting The Demons",
                "Maid With Blue Eyes",
                "Mistress Of Devotion",
                "Lovers In The Forest",
                "Fish And Horses",
                "Maid With Blue Eyes",
                "Destruction Of The Faceless Ones",
                "Guardians And Gangsters",
                "Chicken Abroad"    };
        public static HashMap<String, Integer>countBooks() {
            HashMap<String, Integer>countBooks = new HashMap<>();
            for ( String book : BOOKS ) {
               countBook( countBooks, book);
            }
            return countBooks;
        }
        public static void countBook( HashMap<String, Integer>booksCounter, String book ) {
            if(booksCounter.containsKey(book)){
                booksCounter.put(book, booksCounter.get(book) + 1);
            }
            else{
                booksCounter.put(book, 1);
            }
}
    public static ArrayList<String>findWhiteRavens(HashMap<String, Integer>booksCounter) {
            ArrayList<String>whiteRavens = new ArrayList<>();
            for( HashMap.Entry<String, Integer> entry : booksCounter.entrySet() ){
                String book = entry.getKey();
                Integer p = entry.getValue();
                if( p == 1){
                    whiteRavens.add(book);
                }
            }
            Collections.sort(whiteRavens);
            return whiteRavens;
        }
        public static void printWhiteRavens(ArrayList<String>whiteRavens) {
            for( String raven : whiteRavens ){
                System.out.println(raven);
            }
        }
        public static void books(){
            HashSet<String>books = new HashSet<>();
            books.addAll(Arrays.asList(BOOKS));
            for( String book : books){
                System.out.println(book);
            }
        }
    public static void main(String[] args) {
        System.out.println("\n\nWhite Ravens: ");
        printWhiteRavens(findWhiteRavens(countBooks()));
        System.out.println("\nAll books without repetition: ");
        books();
    }
}