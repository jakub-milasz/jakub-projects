import java.util.ArrayList;
public class BusinessCard {
    private String name;
    private String surname;
    private Address address;
    private char borderChar = '*';
    public BusinessCard(String name, String surname, Address address){
        this.name = name;
        this.surname = surname;
        this.address = address;
    }
    public BusinessCard(String name, String surname, String address){
        this(name, surname, Address.of(address));
    }
    public BusinessCard(String name, String surname){
        this(name, surname, "");
    }
    public String getAddress(){
        return address.toString();
    }
    public String getName() {
        return name;
    }
    public String getSurname() {
        return surname;
    }
    private char getBorderChar() {
        return borderChar;
    }
    public void setBorderChar(char borderChar) {
        this.borderChar = borderChar;
    }

    public void setAddress(Address address) {
        this.address = address;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setSurname(String surname) {
        this.surname = surname;
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
    public ArrayList<String> getLines() {
        ArrayList<String> lines = new ArrayList <>();
        lines.add( name + " " + surname );
        lines.add(address.toString());
        return lines;
    }
}