public class BusinessCardDemo {
    public static void main(String[] args) {
        BusinessCard mine = new BusinessCard("Jakub", "Milasz", new Address("30-123", "Cracow", "Stara", "40"));
        BankCard card = new BankCard("Jan", "Kowal", new Address("34-980", "Cracow", "Mała", "9"), "19 1961-9876-9876-9876-0000-0001");
        mine.print();
        card.print();
    }
}
    