import java.util.ArrayList;

public class BankCard extends BusinessCard{
    private String bankAccount;

    private char borderChar = '$';

    public BankCard(String name, String surname, Address address, String bankAccount){
        super(name, surname, address);
        this.bankAccount = bankAccount;
    }
    public void print() {
        ArrayList<String> lines = getLines();
        int maxLength = getMaxLength(lines);
        char borderChar = getBorderChar();
        String borderLine = "";
        for (int i = 0; i < maxLength + 4; i++) {
            borderLine += borderChar;
        }
        System.out.println(borderLine);
        for (String line : lines) {
            int lengthDiff = maxLength - line.length();
            for (int i = 0; i < lengthDiff; i++) {
                line += " ";
            }
            line = borderChar + " " + line + " " + borderChar;
            System.out.println(line);
        }
        System.out.println(borderLine);
    }
    private int getMaxLength(ArrayList<String> lines) {
        int maxLength = 0;
        for (String line : lines) {
            int lineLength = line.length();
            if (lineLength > maxLength) {
                maxLength = lineLength;
            }
        } return maxLength;
    }
    private char getBorderChar() {
        return borderChar;
    }
    public ArrayList<String> getLines() {
        ArrayList<String> lines = super.getLines();
        lines.add( bankAccount );
        return lines;
    }

    public String getBankAccount() {
        return bankAccount;
    }

    public void setBankAccount(String bankAccount) {
        this.bankAccount = bankAccount;
    }
}
